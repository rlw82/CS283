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

void selectionsort(int* arr, int size)
{
   int i,j;
   int* arrpoint;

   for(i = 0; i < size; i++)
   {
      for(j = i+1; j < size; j++)
      {
         if(arr[j] < arr[i])
         {
            arrpoint = arr[j];
            arr[j] = arr[i];
            arr[i] = arrpoint;
         }
      }
   }
}

struct linkedlist
{
   int data;
   struct linkedlist *next;
};

void part4(struct linkedlist *ll)
{
    struct linkedlist *temp2;
    struct linkedlist *temp;
    int i;
    for(temp = ll; temp->next != NULL; temp = temp->next)
    {
        for(temp2 = temp->next; temp2 != NULL; temp2 = temp2->next)
        {
            if(temp->data > temp2->data)
            {
                i = temp->data;
                temp->data = temp2->data;
                temp2->data = i;
            }
        }
    }
}

int main(void)
{
    struct linkedlist *start,*node,*temp;
    start->next = NULL;
    node = start;
    int i;
    for(i = 0; i < 10; i++)
    {
        node->next = (struct linkedlist*) malloc(sizeof(struct linkedlist));
        node->data = 10-i;
        node = node->next;
        node->next = NULL;
    }
    part4(start);
    node = start;
    for(; node->next != NULL; node = node->next)
    {
        printf("%d\n", node->data);
    }
    node = start;
    temp = node;
    while(temp)
    {
        temp = node->next;
        free(node);
        node = temp;
    }
}
