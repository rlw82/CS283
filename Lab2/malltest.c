#include <stdlib.h>
#include <stdio.h>

void part1()
{
   int i;
   int* x = (int*) malloc(10*sizeof(int));
   for(i = 0; i < 10; i++)
   {
      x[i] = i;
      printf("%d\n",x[i]);
   }
   free(x);
}

void part2()
{
   int i;
   char** my_strs;
   int numStr = 10;
   int strSize = 15;
   my_strs = malloc(numStr * sizeof(char));
   for(i = 0; i < numStr; i++)
   {
      my_strs[i] = malloc(strSize * sizeof(char));
   }


}

int main(void)
{
   part1();
}

