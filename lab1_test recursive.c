#include<stdio.h>
#include<stdlib.h>
struct rec
{
       int value;
       struct rec *next;
};

struct rec *insert(struct rec *head,int data)
    { struct rec *node,*tmp;
      if(head == NULL)
      {
              head = (struct rec*)malloc(sizeof(struct rec));
              head->value=data;
              head->next=NULL;
              
      }

      else
      {
          node = (struct rec*)malloc(sizeof(struct rec));
          node->value=data;
          tmp=head;
          if(tmp->value > data)
          {
               node->next = head;
               head = node;
          }

          
          else
          
          while(tmp!=NULL)
          {
               if(tmp->next == NULL)
               {
                     tmp->next=node;
                     node->next=NULL;
                     break;
               }
               else if(data < tmp->next->value)
               {
                       node->next = tmp->next;
                       tmp->next = node;
                       break;
               }
               else
               tmp = tmp->next;
          }
          
      }
    
      return head;
       
    }
    

void print(struct rec *tmp)
{

     if(tmp->next != NULL)
     print(tmp->next);
     printf("%d ",tmp->value);
}



int menu()
{
    int choose;
    printf("======== Menu ========\n");
    printf("1) Insert\n");
    printf("2) Print All data\n");
    printf("3) Print frist node and Last node\n");
    printf("4) Print reverse data\n");
    printf("5) Exit\n");
    printf("Please Choose >");
    scanf("%d",&choose);
    return choose;
}



int main()
{  
    struct rec *tmp,*node,*head=NULL;
    int x,a;
    x=menu();
    while(x!=5)
    {
         if(x==1)
         {
            printf("Please Enter Number : ");
            scanf("%d",&a);
            head=insert(head,a);
            x=menu();
                 
         }
         else if(x==2)
         {
              struct rec *node;
              node=head;
              while(node)
              {
              printf("%d ",node->value);
              node=node->next;
              }
              printf("\n");
              x=menu();
         }
         else if(x==3)
         {
              printf("%d ",head->value);
              tmp=head;
              while(tmp!=NULL)
              {
              tmp = tmp->next;
              if(tmp->next==NULL)
                  {
                  printf("%d",tmp->value);
                  break;
                  }
              }
              
              printf("\n");
              x=menu();
         }
         else if(x==4)
         {
               print(head); 
               printf("\n");
               x=menu();
         }
         else
         {
             printf("can't input more than 5\n");
             x=menu();
         }
    }

}
