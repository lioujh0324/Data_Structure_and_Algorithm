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
void AdjustMaxHeap(element [],int,int);
void HeapSort(element [],int,int);
void Swap(element [], int, int);

int main(void)
{
    srand(time(NULL));
    int i;
    element List[ListSize+2];

    List[0].key=0;
    List[ListSize+1].key=MaxListNumber+1;
    for(i=1;i<=ListSize;i++)
    {
        List[i].key=1+rand()%MaxListNumber;
    }
    HeapSort(List,1,ListSize);
    for(i=1;i<=ListSize;i++)
    {
        printf("%d ", List[i].key);
    }
    printf("\n");

    system("pause");
    return 0;
}
void AdjustMaxHeap(element List[],int root,int n)
{
    int rootkey=List[root].key;
    int child=2*root;
    while (child<=n)
    {
        if (child+1<=n && List[child+1].key>=List[child].key)
        {
            child++;
        }
        if (rootkey<=List[child].key)
        {
            Swap(List,root,child);
            root=child;
            child*=2;
        }
        else
        {
            child=n+1;
        }
    }
    
}
void HeapSort(element List[],int root,int n)
{
    int i;
    for (i=n/2; i>=root; i--)
    {
        AdjustMaxHeap(List,i,n);
    }
    for (i=n; i>=root; i--)
    {
        Swap(List,root,i);
        AdjustMaxHeap(List,root,i-1);
    }
    
    
}
void Swap(element List[], int a, int b)
{
    element temp;
    temp=List[a];
    List[a]=List[b];
    List[b]=temp;
}