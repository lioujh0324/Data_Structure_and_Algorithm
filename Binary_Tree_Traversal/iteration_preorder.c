#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 100

struct treenode
{
    int data;
    int label;
    struct treenode *leftchild;
    struct treenode *rightchild;
};
typedef struct treenode treenode;
void Addq(treenode *[], treenode *);
void Deleteq(treenode *[]);
treenode *CreateBinaryTree(treenode *);
void iter_preorder(treenode *);
int treenodeStackPush(int, treenode *, treenode *[]);
int treenodeStackPop(int);
void FreeTree(treenode *);

int main(void)
{ 
    treenode *root;
    root=(treenode *)malloc(sizeof(treenode));
    root=CreateBinaryTree(root);
    iter_preorder(root);
    FreeTree(root);
    printf("\n");

    system("pause");
    return 0;
}
treenode *CreateBinaryTree(treenode *root)
{
    treenode *child, *currentnode;
    treenode *qfr[2];   /* qfr[0] is front of queue, qfr[1] is rear of queue */
    int labelcount=1;
    char Yes_or_No;
    qfr[0]=NULL, qfr[1]=NULL;
    root->label=labelcount;
    Addq(qfr,root);
    do
    {
        currentnode=qfr[0];
        Deleteq(qfr);
        printf("Input the data of %d treenode :\n", currentnode->label);
        scanf("%d",&currentnode->data);
        fflush(stdin);
        printf("Does %d treenode has leftchilld (y/n)?\n", currentnode->label);
        Yes_or_No=getchar();
        labelcount=2*currentnode->label;
        if(Yes_or_No=='y')
        {
            child=(treenode *)malloc(sizeof(treenode));
            child->label=labelcount;
            currentnode->leftchild=child;
            Addq(qfr,child);
        }
        else
        {
            currentnode->leftchild=NULL;
        }
        printf("Does %d treenode has rightchilld (y/n)?\n", currentnode->label);
        fflush(stdin);
        Yes_or_No=getchar();
        labelcount=2*currentnode->label+1;
        if(Yes_or_No=='y')
        {
            child=(treenode *)malloc(sizeof(treenode));
            child->label=labelcount;
            currentnode->rightchild=child;
            Addq(qfr,child);
        }
        else
        {
            currentnode->rightchild=NULL;
        }

    } while (qfr[0]);
    return root;
}
void Addq(treenode *qfr[], treenode *newnode)
{
    if(qfr[0])
    {
        qfr[1]->rightchild=newnode;
        newnode->rightchild=NULL;
        qfr[1]=newnode;
    }
    else
    {
        qfr[0]=newnode;
        qfr[1]=qfr[0];
        qfr[1]->rightchild=NULL;
    }
}
void Deleteq(treenode *qfr[])
{
    if(qfr[0]!=qfr[1])
    {
        qfr[0]=qfr[0]->rightchild;
    }
    else
    {
        qfr[0]=qfr[1]=NULL;
    }
}
int treenodeStackPush(int top, treenode *newnode, treenode *stack[MAX_STACK])
{
    stack[++top]=newnode;
    return top;
}
int treenodeStackPop(int top)
{
    return --top;
}
void iter_preorder(treenode *root)
{
    int top=-1;
    treenode *stack[MAX_STACK];
    treenode *currentnode=root;
    while (top!=-2)
    {
        printf("%d ", currentnode->data);
        if(currentnode->leftchild)
        {
            if(currentnode->rightchild)
            {
                top=treenodeStackPush(top,currentnode->rightchild,stack);
                currentnode=currentnode->leftchild;
            }
            else
            currentnode=currentnode->leftchild;
        }
        else if(currentnode->rightchild)
        currentnode=currentnode->rightchild;
        else
        {
            currentnode=stack[top];
            top=treenodeStackPop(top);
        }
    }    
}
void FreeTree(treenode *root)
{
    if (root)
    {
        FreeTree(root->leftchild);
        FreeTree(root->rightchild);
        free(root);
    }
}