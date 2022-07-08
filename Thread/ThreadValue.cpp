#include <stdio.h>
#include <pthread.h>

void *thread_code(void *arg)
{
  int function = 5*((2+4)*(7+3))-10;
  pthread_exit((int*) function);
}

int main()
{
  int thread, value;
  
  printf ("Creating Thread ...");
  pthread_t ptID;
  
  thread = pthread_create (&ptID, NULL, &thread_code, NULL);
  
  if (thread){
  	printf ("Execution Error!!");
  	
  	return 10;
  }
  
  pthread_join (ptID, &value); // Stand-by
  
  printf ("\nReturn Value --> %d", value);
  
  return 0;
}
