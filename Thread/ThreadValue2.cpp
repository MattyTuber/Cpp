#include <stdio.h>
#include <pthread.h>

int x, y;

void *thread_code(void *arg)
{
  int function = (3+x)-(2+y)*(7*y+4)-10;
  pthread_exit((int*) function);
}

int main()
{
  int thread, value;
  
  printf("Inserire X --> ");
  scanf("%d", &x);
  
  printf("Inserire Y --> ");
  scanf("%d", &y);
  
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
