#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ListSize 20
#define MaxListNumber 100

struct element
{
    int key;
};
typedef struct element element;

void MergeSort(element [],int,int,int);
void MergeTwoOrderedList(element [],int,int,int);

int main(void)
{
    srand(time(NULL));
    int i,SetSize=ListSize;
    element List[ListSize+2];

    List[0].key=0;
    List[ListSize+1].key=MaxListNumber+1;
    for(i=1;i<=ListSize;i++)
    {
        List[i].key=1+rand()%MaxListNumber;
    }
    printf("Before sorting :\n");
    for(i=1;i<=ListSize;i++)
    {
        printf("%d ", List[i].key);
    }
    printf("\n");
    MergeSort(List,SetSize,1,SetSize);
    printf("After sorting :\n");
    for(i=1;i<=ListSize;i++)
    {
        printf("%d ", List[i].key);
    }
    printf("\n");

    system("pause");
    return 0;
}
void MergeSort(element List[],int SetSize,int left,int right)
{
    if (SetSize>2)
    {
        if (SetSize%2)
        {
            MergeSort(List,SetSize/2,left,left+SetSize/2-1);
            MergeSort(List,SetSize/2+1,left+SetSize/2,right);
            MergeTwoOrderedList(List,left,left+SetSize/2-1,right);
        }
        else
        {
            MergeSort(List,SetSize/2,left,left+SetSize/2-1);
            MergeSort(List,SetSize/2,left+SetSize/2,right);
            MergeTwoOrderedList(List,left,left+SetSize/2-1,right);
        }
    }
    else if (SetSize==2)
    {
        if (List[left].key>List[right].key)
        {
            element temp=List[left];
            List[left]=List[right];
            List[right]=temp;
        }
    }
}
void MergeTwoOrderedList(element List[], int leftliststart, int leftlistend, int rightlistend)
{
    element temp[ListSize+2];
    int i,j,k;
    for(i=leftliststart;i<=rightlistend;i++)
    {
        temp[i]=List[i];
    }
    i=leftliststart;
    j=leftlistend+1;
    k=i;
    while (i<=leftlistend && j<=rightlistend)
    {
        if (temp[i].key<=temp[j].key)
        {
            List[k++]=temp[i++];
        }
        else
        {
            List[k++]=temp[j++];
        }
    }
    while (j<=rightlistend)
    {
        List[k++]=temp[j++];
    }
    while (i<=leftlistend)
    {
        List[k++]=temp[i++];
    }
}
