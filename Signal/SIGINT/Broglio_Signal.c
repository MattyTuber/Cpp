#include <stdio.h>
#include <signal.h>

void handler(int signal)
{
  printf("\nSignal Received --> %d\n", signal);
  sleep(2);
  printf("\nEnd...");
}

int main() {
  signal(SIGINT, handler);

  for (int i = 0; i<10; i++){
    printf("\nNum --> %d\n", i);
    sleep(1);
  }
}