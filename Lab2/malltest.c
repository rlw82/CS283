//Russell Wiley
//CS283
//Lab2
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
   char** strs;
   int numStr = 10;
   int strSize = 15;
   strs = malloc(numStr * sizeof(char*));
   for(i = 0; i < numStr; i++)
   {
      strs[i] = malloc(strSize * sizeof(char));
   }
   strcpy(strs[0],"zero\0");
   strcpy(strs[1],"one\0");
   strcpy(strs[2],"two\0");
   strcpy(strs[3],"three\0");
   strcpy(strs[4],"four\0");
   strcpy(strs[5],"five\0");
   strcpy(strs[6],"six\0");
   strcpy(strs[7],"seven\0");
   strcpy(strs[8],"eight\0");
   strcpy(strs[9],"nine\0");

   for(i = 0; i < numStr; i++)
   {
      printf("strs[%d] = \"%s\"\n",i,strs[i]);
      free(strs[i]);
   }
   free(strs);
}

int main(void)
{
   part2();
}

