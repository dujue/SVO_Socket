#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
    int a;
     srand(time(NULL));
    for (int i = 0; i < 5; ++i)
    {
      a= rand()%20;
      printf("number =%d \n", a);
    }
    

  return 0;
}