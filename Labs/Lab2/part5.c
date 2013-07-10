//Russell Wiley
//CS283
//Lab2
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct arrays
{
    int* values;
    int size;
    int length;
};

void addfast(struct arrays *a, int value)
{
    if(a->length+1 >= a->size)
    {
        a = realloc(a,sizeof(a)*2);
        a->size++;
        a->values[a->length] = value;
        a->length++;
    }
    else
    {
        a->values[a->length] = value;
        a->length++;
    }
}

void addslow(struct arrays *a, int value)
{
    if(a->length+1 >= a->size)
    {
        a = realloc(a,sizeof(a)+sizeof(int));
        a->size++;
        a->values[a->length] = value;
        a->length++;
    }
    else
    {
        a->values[a->length] = value;
        a->length++;
    }
}

void removes(struct arrays *a)
{
    a->values[a->length] = NULL;
    a->length = a->length - 1;
}

int get(struct arrays *a, int i)
{
    return a->values[i];
}

void main()
{
    clock_t begin, end;
    double time1,time2;
    begin = clock();
    int i;
    struct arrays *arr;
    arr = (struct arrays*) malloc(sizeof(struct arrays));
    for(i = 0; i < 100000; i++)
    {
        addslow(arr,1);
    }
    end = clock();
    time1 = (double)(end-begin)/CLOCKS_PER_SEC;
    struct arrays *arr2;
    arr2 = (struct arrays*) malloc(sizeof(struct arrays));
    begin = clock();
    for(i = 0; i < 100000; i++)
    {
        addfast(arr2,1);
    }
    end = clock();
    time2 = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("first way took %f, second way took %f",time1,time2);
}
