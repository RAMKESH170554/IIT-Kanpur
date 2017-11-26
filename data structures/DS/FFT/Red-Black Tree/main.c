#include <stdio.h>
#include <stdlib.h>
struct tree{
      int data;
      struct tree* parent;
      struct tree* leftChild;
      struct tree* rightChild;
      char colour;
}*root;
struct tree* node(int k)
{
    struct tree* new =(struct tree*)malloc(sizeof(struct tree));
    new->data=k;
    new->colour='R';
    new->leftChild=NULL;
    new->rightChild=NULL;
    new->parent=NULL;
    return new;
}
void leftRotate(struct tree* z)
{
    struct tree* y= z->rightChild;
        z->rightChild= y->leftChild;
        if(y->leftChild!=NULL)
          y->leftChild->parent= z;

            y->parent= z->parent;
        if(z->parent==NULL)
          root= y;
        else
            {if(z==z->parent->leftChild)
              z->parent->leftChild= y;
            else
              z->parent->rightChild= y;
            }
         y->leftChild= z;
         z->parent= y;
}
void rightRotate(struct tree* z)
{
        struct tree* y= z->leftChild;
        z->leftChild= y->rightChild;
        if(y->rightChild!=NULL)
          y->rightChild->parent= z;

            y->parent= z->parent;
        if(z->parent==NULL)
          root= y;
        else
            {if(z==z->parent->leftChild)
              z->parent->leftChild= y;
            else
              z->parent->rightChild= y;
            }
         y->rightChild= z;
         z->parent= y;
}
void Fix_up(struct tree* z)
{
    if(z->parent->parent==NULL)
    {
        z->parent->colour='B';
        return;
    }
    while(z->parent->colour=='R')
    {
        if(z->parent==z->parent->parent->leftChild)
         {
            struct tree* y= z->parent->parent->rightChild;
            if(y==NULL)
              {
                  if(z==z->parent->rightChild)
                  {
                      z=z->parent;
                      leftRotate(z);
                  }
                  z->parent->colour= 'B';
                  z->parent->parent->colour= 'R';
                  rightRotate(z->parent->parent);
              }
            else
            {
                if(y->colour=='R')
               {
                y->colour= 'B';
                z->parent->colour= 'B';
                z->parent->parent->colour= 'R';
                z= z->parent->parent;
                if(z==root)
                    return ;
                if(z->parent->parent==NULL)
                {
                    z->parent->colour='B';
                    return;
                }
               }
               else
              {
                if(z== z->parent->rightChild)
                    {z= z->parent;
                    leftRotate(z);
                    }
                    z->parent->colour= 'B';
                    z->parent->parent->colour= 'R';
                    rightRotate(z->parent->parent);
              }
            }
         }
         else
         {
              struct tree* y= z->parent->parent->leftChild;
              if(y==NULL)
              {
                  if(z==z->parent->leftChild)
                  {
                      z=z->parent;
                      rightRotate(z);
                  }
                  z->parent->colour= 'B';
                  z->parent->parent->colour= 'R';
                  leftRotate(z->parent->parent);
              }
              else
              {
                  if(y->colour=='R')
                {
                  y->colour= 'B';
                  z->parent->colour= 'B';
                  z->parent->parent->colour= 'R';
                  z= z->parent->parent;
                  if(z==root)
                    return;
                  if(z->parent->parent==NULL)
                  {
                    z->parent->colour='B';
                    return;
                  }
                }
                  else
                {
                   if(z== z->parent->leftChild)
                    {z= z->parent;
                    rightRotate(z);
                    }
                    z->parent->colour= 'B';
                    z->parent->parent->colour= 'R';
                    leftRotate(z->parent->parent);
                }
              }
          }
    }
    root->colour='B';
}
void Insert(struct tree* z)
{
    if(root==NULL)
        {
           root=z;
           return;
        }
    struct tree* x=root;
    struct tree* y;
     while(x!=NULL)
     {
         y=x;
         if(x->data<=z->data)
            x=x->rightChild;
         else
            x=x->leftChild;
     }
       if(y->data<=z->data)
          y->rightChild=z;
       else
          y->leftChild=z;

          z->parent= y;
     Fix_up(z);
}
void output(struct tree* x)
{
    if(x==NULL)
        return ;
    output(x->leftChild);
    if(x->parent==NULL)
        printf("%d %c NIL\n",x->data,x->colour);
    else
        printf("%d %c %d\n",x->data,x->colour,x->parent->data);
    output(x->rightChild);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];  struct tree* b[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
       b[i]= node(a[i]);
       Insert(b[i]);
    }
    struct tree* x=root;
    output(x);
    return 0;
}
