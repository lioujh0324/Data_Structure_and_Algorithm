#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP 100

int main(void)
{
    int MaxHeap[MAX_HEAP];
    int i=0,temp,j,changevalue;
    do
    {
        i++;
        printf("Input a element : \n");
        scanf("%d",&MaxHeap[i]);
        j=i;
        /* sorting begin */
        while(i!=1 && MaxHeap[i]>MaxHeap[i/2])
        {
            temp=MaxHeap[i/2];
            MaxHeap[i/2]=MaxHeap[i];
            MaxHeap[i]=temp;
            i=i/2;
        }
        /* sorting end */
        i=j;
    } while (MaxHeap[i]>0);
    /* set remaining node to be 0 */
    while(i<MAX_HEAP)
    {
        MaxHeap[i]=0;
        i++;
    }
    /* print heap */
    i=1;
    while(MaxHeap[i]>0)
    {
        printf("%d ", MaxHeap[i]);
        i++;
    }
    printf("\n");
    
    /* revise node */
    printf("Input the node which you wanna change value :\n");
    scanf("%d", &i);
    printf("Input the value to change :\n");
    scanf("%d", &changevalue);
    if (changevalue>MaxHeap[i])
    {
        MaxHeap[i]=changevalue;
        while(i!=1 && MaxHeap[i]>MaxHeap[i/2])
        {
            temp=MaxHeap[i/2];
            MaxHeap[i/2]=MaxHeap[i];
            MaxHeap[i]=temp;
            i=i/2;
        }
    }
    else
    {
        MaxHeap[i]=changevalue;
        while(MaxHeap[i]<MaxHeap[2*i] || MaxHeap[i]<MaxHeap[2*i+1])
        {
            if(MaxHeap[i]<MaxHeap[2*i] && MaxHeap[i]<MaxHeap[2*i+1]) /* smaller than both children */
            {
                if(MaxHeap[2*i]>MaxHeap[2*i+1]) /* left > right */
                {
                    temp=MaxHeap[i];
                    MaxHeap[i]=MaxHeap[2*i];
                    MaxHeap[2*i]=temp;
                    i=i*2;
                }
                else /* left <= right */
                {
                    temp=MaxHeap[i];
                    MaxHeap[i]=MaxHeap[2*i+1];
                    MaxHeap[2*i+1]=temp;
                    i=i*2+1;
                }
            }
            else if (MaxHeap[i]<MaxHeap[2*i])
            {
                temp=MaxHeap[i];
                MaxHeap[i]=MaxHeap[2*i];
                MaxHeap[2*i]=temp;
                i=i*2;
            }
            else if (MaxHeap[i]<MaxHeap[2*i+1])
            {
                temp=MaxHeap[i];
                MaxHeap[i]=MaxHeap[2*i+1];
                MaxHeap[2*i+1]=temp;
                i=i*2+1;
            }
        }
    }
    /* print heap */
    i=1;
    while(MaxHeap[i]>0)
    {
        printf("%d ", MaxHeap[i]);
        i++;
    }
    printf("\n");
    
    system("pause");
    return 0;
}