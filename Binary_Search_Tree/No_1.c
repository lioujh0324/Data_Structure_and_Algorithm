#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 100

struct treenode
{
    int key;
    struct treenode *leftchild;
    struct treenode *rightchild;
};
typedef struct treenode treenode;
treenode *CreateNode();
void Insertnode(treenode *, treenode *);
int treenodeStackPush(int , treenode *, treenode *[MAX_STACK]);
int treenodeStackPop(int);
void iter_preorder(treenode *);
void DeleteNode(int, treenode *);

int main(void)
{
    treenode *root;
    treenode *currentnode, *newnode;
    root=(treenode *)malloc(sizeof(treenode));
    int deletekey;
    printf("Input the key of root\n");
    scanf("%d", &root->key);
    root->leftchild=NULL;
    root->rightchild=NULL;    
    currentnode=root;
    while(currentnode)
    {
        newnode=CreateNode();
        if(newnode)
        {
            Insertnode(root, newnode);
        }
        currentnode=newnode;
    }
    iter_preorder(root);
    printf("Input the key you wanna delete :\n");
    scanf("%d", &deletekey);
    DeleteNode(deletekey, root);
    if (root)
        iter_preorder(root);
    
    system("pause");
    return 0;
}
treenode *CreateNode()
{
    treenode *newnode;
    newnode=(treenode *)malloc(sizeof(treenode));
    printf("Input the key of newnode\n");
    scanf("%d", &newnode->key);
    if (newnode->key==0)
    {
        return NULL;
    }
    newnode->leftchild=NULL;
    newnode->rightchild=NULL;
    return newnode;
}
void Insertnode(treenode *root, treenode *newnode)
{
    treenode *currentnode=root, *previousnode;
    while(currentnode)
    {
        previousnode=currentnode;
        if (currentnode->key>newnode->key)
        {
            currentnode=currentnode->leftchild;
        }
        else if (currentnode->key==newnode->key)
        {
            printf("The key had existed!!\n");
            break;
        }
        else
        {
            currentnode=currentnode->rightchild;
        }
    }
    if (previousnode->key>newnode->key)
    {
        previousnode->leftchild=newnode;
    }
    else if (previousnode->key<newnode->key)
    {
        previousnode->rightchild=newnode;
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
        printf("%d ", currentnode->key);
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
    printf("\n");    
}
void DeleteNode(int key, treenode *root)
{
    treenode *currentnode, *targetnode=NULL, *temp;
    currentnode=root;
    while (currentnode)
    {
        if (key<currentnode->key)
        currentnode=currentnode->leftchild;
        else if (key>currentnode->key)
        currentnode=currentnode->rightchild;
        else
        {
            targetnode=currentnode;
            currentnode=NULL;
        }    
    }
    if (targetnode->leftchild)
    {
        currentnode=targetnode->leftchild;
        if (!currentnode->rightchild)
        {
            targetnode->key=currentnode->key;
            targetnode->leftchild=currentnode->leftchild;
            free(currentnode);
        }
        else
        {
            while(currentnode->rightchild->rightchild)
            {
                currentnode=currentnode->rightchild;
            }
            targetnode->key=currentnode->rightchild->key;
            temp=currentnode->rightchild->leftchild;
            free(currentnode->rightchild);
            currentnode->rightchild=temp;
        }
    }
    else if (targetnode->rightchild)
    {
        currentnode=targetnode->rightchild;
        if (!currentnode->leftchild)
        {
            targetnode->key=currentnode->key;
            targetnode->rightchild=currentnode->rightchild;
            free(currentnode);
        }
        else
        {
            while(currentnode->leftchild->leftchild)
            {
                currentnode=currentnode->leftchild;
            }
            targetnode->key=currentnode->leftchild->key;
            temp=currentnode->leftchild->rightchild;
            free(currentnode->leftchild);
            currentnode->leftchild=temp;
        }
    }
    else
    free(targetnode);

}
