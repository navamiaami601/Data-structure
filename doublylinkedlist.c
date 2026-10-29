#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node*left,*right;
};
struct node*insert(struct node*start,int data)
{ 
  struct node*t=malloc(sizeof(struct node));
  t->data=data;
  t->left=NULL;
  t->right=start;
  if(start!=NULL)
    start->left=t;
    return t;
}
//search
struct node*search(struct node* start,int item)
{
   while(start!=NULL)
   {
     if(start->data==item)
     return start;
     start=start->right;
   
   }
   return NULL;
}
struct node*delete(struct node*start,struct node*t)
{ 
   if(t->left!=NULL)
   t->left->right=t->right;
   else
     start=t->right;
   if(t->right!=NULL)
   t->right->left=t->left;
   free(t);
   return start;
}
int main()
{
  struct node*L1=NULL,*t;
  int opt,data;
  do
  {
    printf("\n1.insert\n2.search\n3.delete\n4.exit\n");
    printf("enter opinion");
    scanf("%d",&opt);
    switch(opt)
    { 
      case 1:
      printf("enter data");
      scanf("%d",&data);
      L1=insert(L1,data);
      break;
      case 2:
      printf("enter item to search");
      scanf("%d",&data);
      t=search(L1,data);
      if(t==NULL)
      printf("NOT FOUND\n");
      else
      printf("found\n");
      break;
      case 3:
      printf("ente ritem to delete:");
      scanf("%d",&data);
      t=search(L1,data);
      if(t!=NULL)
      {
        L1=delete(L1,t);
        printf("item deleted\n");
      }
      else
      {
        printf("item does not exit\n");
      }
      break;
      case 4:
          printf("Exit\n");
          break;
          default:
             printf("invalid option\n");
    }
  }while(opt!=4);
  return 0;
}
