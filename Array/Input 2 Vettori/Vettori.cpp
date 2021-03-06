using System;
using UnityEngine;

public class PlayerMovement: MonoBehaviour {

 //Assingables
 public Transform playerCam;
 public Transform orientation;

 //Other
 private Rigidbody rb;

 //Rotation and look
 private float xRotation;
 private float sensitivity = 50 f;
 private float sensMultiplier = 1 f;

 //Movement
 public float moveSpeed = 4500;
 public float walkSpeed = 2000;
 public float runSpeed = 4500;
 public float maxSpeed = 20;
 public bool grounded;
 private bool IsWalking = false;
 public LayerMask whatIsGround;

 //Animation
 public Animator animator;

 public float counterMovement = 0.175 f;
 private float threshold = 0.01 f;
 public float maxSlopeAngle = 35 f;

 //Crouch & Slide
 private Vector3 crouchScale = new Vector3(1, 0.5 f, 1);
 private Vector3 playerScale;
 public float slideForce = 400;
 public float slideCounterMovement = 0.2 f;

 //Jumping
 private bool readyToJump = true;
 private float jumpCooldown = 0.25 f;
 public float jumpForce = 550 f;

 //Input
 float x, y;
 bool jumping, sprinting, crouching;

 //Sliding
 private Vector3 normalVector = Vector3.up;
 private Vector3 wallNormalVector;

 void Awake() {
  rb = GetComponent < Rigidbody > ();
 }

 void Start() {
  playerScale = transform.localScale;
  Cursor.lockState = CursorLockMode.Locked;
  Cursor.visible = false;
 }


 private void FixedUpdate() {
  Movement();
 }

 private void Update() {
  MyInput();
  Look();
 }

 /// <summary>
 /// Find user input. Should put this in its own class but im lazy
 /// </summary>
 private void MyInput() {
  x = Input.GetAxisRaw("Horizontal");
  y = Input.GetAxisRaw("Vertical");

  animator.SetFloat("Speed", Mathf.Abs(x + y));

  jumping = Input.GetButton("Jump");

  crouching = Input.GetKey(KeyCode.LeftControl);

  //Crouching
  if (Input.GetKeyDown(KeyCode.LeftControl)) {
   animator.SetBool("IsCrouching", true);
   StartCrouch();
  }

  if (Input.GetKeyUp(KeyCode.LeftControl)) {
   animator.SetBool("IsCrouching", false);
   StopCrouch();
  }

  if (Input.GetKeyDown(KeyCode.B)) {
   animator.SetBool("IsDancing", true);
  }

  if (Input.GetKeyUp(KeyCode.B)) {
   animator.SetBool("IsDancing", false);
  }
 }

 private void StartCrouch() {
  transform.localScale = crouchScale;
  transform.position = new Vector3(transform.position.x, transform.position.y - 0.5 f, transform.position.z);
  if (rb.velocity.magnitude > 0.5 f) {
   if (grounded) {
    rb.AddForce(orientation.transform.forward * slideForce);
   }
  }
 }

 private void StopCrouch() {
  transform.localScale = playerScale;
  transform.position = new Vector3(transform.position.x, transform.position.y + 0.5 f, transform.position.z);
 }

 private void Movement() {

  if (Input.GetKeyDown(KeyCode.LeftShift)) {
   moveSpeed = runSpeed;
  } else {
   IsWalking = true;
   moveSpeed = walkSpeed;
  }

  //Extra gravity
  rb.AddForce(Vector3.down * Time.deltaTime * 10);

  //Find actual velocity relative to where player is looking
  Vector2 mag = FindVelRelativeToLook();
  float xMag = mag.x, yMag = mag.y;

  //Counteract sliding and sloppy movement
  CounterMovement(x, y, mag);

  //If holding jump && ready to jump, then jump
  if (readyToJump && jumping) Jump();

  //Set max speed
  float maxSpeed = this.maxSpeed;

  //If sliding down a ramp, add force down so player stays grounded and also builds speed
  if (crouching && grounded && readyToJump) {
   rb.AddForce(Vector3.down * Time.deltaTime * 3000);
   return;
  }

  //If speed is larger than maxspeed, cancel out the input so you don't go over max speed
  if (x > 0 && xMag > maxSpeed) x = 0;
  if (x < 0 && xMag < -maxSpeed) x = 0;
  if (y > 0 && yMag > maxSpeed) y = 0;
  if (y < 0 && yMag < -maxSpeed) y = 0;

  //Some multipliers
  float multiplier = 1 f, multiplierV = 1 f;

  // Movement in air
  if (!grounded) {
   multiplier = 0.5 f;
   multiplierV = 0.5 f;
  }

  // Movement while sliding
  if (grounded && crouching) {
   multiplierV = 0 f;
  }



  //Apply forces to move player
  rb.AddForce(orientation.transform.forward * y * moveSpeed * Time.deltaTime * multiplier * multiplierV);
  rb.AddForce(orientation.transform.right * x * moveSpeed * Time.deltaTime * multiplier);
 }

 private void Jump() {
  if (grounded && readyToJump) {
   readyToJump = false;

   animator.SetBool("IsJumping", true);

   //Add jump forces
   rb.AddForce(Vector2.up * jumpForce * 1.5 f);
   rb.AddForce(normalVector * jumpForce * 0.5 f);

   //If jumping while falling, reset y velocity.
   Vector3 vel = rb.velocity;
   if (rb.velocity.y < 0.5 f)
    rb.velocity = new Vector3(vel.x, 0, vel.z);
   else if (rb.velocity.y > 0)
    rb.velocity = new Vector3(vel.x, vel.y / 2, vel.z);

   Invoke(nameof(ResetJump), jumpCooldown);
  }
 }

 private void ResetJump() {
  readyToJump = true;

  animator.SetBool("IsJumping", false);
 }

 private float desiredX;
 private void Look() {
  float mouseX = Input.GetAxis("Mouse X") * sensitivity * Time.fixedDeltaTime * sensMultiplier;
  float mouseY = Input.GetAxis("Mouse Y") * sensitivity * Time.fixedDeltaTime * sensMultiplier;

  //Find current look rotation
  Vector3 rot = playerCam.transform.localRotation.eulerAngles;
  desiredX = rot.y + mouseX;

  //Rotate, and also make sure we dont over- or under-rotate.
  xRotation -= mouseY;
  xRotation = Mathf.Clamp(xRotation, -90 f, 45 f);

  //Perform the rotations
  playerCam.transform.localRotation = Quaternion.Euler(xRotation, desiredX, 0);
  orientation.transform.localRotation = Quaternion.Euler(0, desiredX, 0);
 }

 private void CounterMovement(float x, float y, Vector2 mag) {
  if (!grounded || jumping) return;

  //Slow down sliding
  if (crouching) {
   rb.AddForce(moveSpeed * Time.deltaTime * -rb.velocity.normalized * slideCounterMovement);
   return;
  }

  //Counter movement
  if (Math.Abs(mag.x) > threshold && Math.Abs(x) < 0.05 f || (mag.x < -threshold && x > 0) || (mag.x > threshold && x < 0)) {
   rb.AddForce(moveSpeed * orientation.transform.right * Time.deltaTime * -mag.x * counterMovement);
  }
  if (Math.Abs(mag.y) > threshold && Math.Abs(y) < 0.05 f || (mag.y < -threshold && y > 0) || (mag.y > threshold && y < 0)) {
   rb.AddForce(moveSpeed * orientation.transform.forward * Time.deltaTime * -mag.y * counterMovement);
  }

  //Limit diagonal running. This will also cause a full stop if sliding fast and un-crouching, so not optimal.
  if (Mathf.Sqrt((Mathf.Pow(rb.velocity.x, 2) + Mathf.Pow(rb.velocity.z, 2))) > maxSpeed) {
   float fallspeed = rb.velocity.y;
   Vector3 n = rb.velocity.normalized * maxSpeed;
   rb.velocity = new Vector3(n.x, fallspeed, n.z);
  }
 }

 /// <summary>
 /// Find the velocity relative to where the player is looking
 /// Useful for vectors calculations regarding movement and limiting movement
 /// </summary>
 /// <returns></returns>
 public Vector2 FindVelRelativeToLook() {
  float lookAngle = orientation.transform.eulerAngles.y;
  float moveAngle = Mathf.Atan2(rb.velocity.x, rb.velocity.z) * Mathf.Rad2Deg;

  float u = Mathf.DeltaAngle(lookAngle, moveAngle);
  float v = 90 - u;

  float magnitue = rb.velocity.magnitude;
  float yMag = magnitue * Mathf.Cos(u * Mathf.Deg2Rad);
  float xMag = magnitue * Mathf.Cos(v * Mathf.Deg2Rad);

  return new Vector2(xMag, yMag);
 }

 private bool IsFloor(Vector3 v) {
  float angle = Vector3.Angle(Vector3.up, v);
  return angle < maxSlopeAngle;
 }

 private bool cancellingGrounded;

 /// <summary>
 /// Handle ground detection
 /// </summary>
 private void OnCollisionStay(Collision other) {
  //Make sure we are only checking for walkable layers
  int layer = other.gameObject.layer;
  if (whatIsGround != (whatIsGround | (1 << layer))) return;

  //Iterate through every collision in a physics update
  for (int i = 0; i < other.contactCount; i++) {
   Vector3 normal = other.contacts[i].normal;
   //FLOOR
   if (IsFloor(normal)) {
    grounded = true;
    cancellingGrounded = false;
    normalVector = normal;
    CancelInvoke(nameof(StopGrounded));
   }
  }

  //Invoke ground/wall cancel, since we can't check normals with CollisionExit
  float delay = 3 f;
  if (!cancellingGrounded) {
   cancellingGrounded = true;
   Invoke(nameof(StopGrounded), Time.deltaTime * delay);
  }
 }

 private void StopGrounded() {
  grounded = false;
 }
}