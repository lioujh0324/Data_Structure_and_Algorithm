#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct element
{
    int key;
};
typedef struct element element;
void QuickSort(element [], int, int);
void Swap(element [], int, int);

int main(void)
{
    srand(time(NULL));
    int i;
    element List[22];

    List[0].key=0;
    List[21].key=101;
    for(i=1;i<=20;i++)
    {
        List[i].key=1+rand()%100;
    }
    QuickSort(List,1,20);
    for(i=1;i<=20;i++)
    {
        printf("%d ", List[i].key);
    }
    printf("\n");

    system("pause");
    return 0;
}
void QuickSort(element List[], int left, int right)
{
    int i,j,pivot;
    i=left;
    j=right+1;
    pivot=List[left].key;

    while (i<j)
    {
        do
        {
            i++;
        } while (List[i].key<pivot);
        do
        {
            j--;
        } while (List[j].key>pivot);
        if (i<j)
        {
            Swap(List,i,j);
        }
        else
        {
            Swap(List,left,j);
            QuickSort(List,left,j-1);
            QuickSort(List,j+1,right);
        }
    }
}
void Swap(element List[], int a, int b)
{
    element temp;
    temp=List[a];
    List[a]=List[b];
    List[b]=temp;
}