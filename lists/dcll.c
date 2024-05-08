#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;

}NODE;
NODE *head=0;
NODE *newnode=0;
NODE *tail=0;
NODE *temp=0;
NODE* Getnode()
{
    newnode=(NODE *)malloc(sizeof(NODE));
    if(newnode==0)
    {
        printf("Node not created\n");9k
        exit(0);
    }
    else
    {
        printf("Enter the data of newly created node:\n");
        scanf("%d",&newnode->data);

        newnode->prev=newnode;
        newnode->next=newnode;
    }
    return newnode;
}
NODE* InsertBeginning(NODE *head)
{
    newnode=Getnode();
    if(head==0)
    {
        head=tail=newnode;
    }
    else
    {
        newnode->prev=tail;
        newnode->next=head;
        head->prev=newnode;
        tail->next=newnode;
        head=newnode;
    }
    return head;
}
NODE* InsertEnd(NODE *head)
{
    newnode=Getnode();
    if(head==0)
    {
        head=tail=newnode;
    }
    else
    {
        newnode->prev=tail;
        newnode->next=tail->next;
        tail->next=newnode;
        head->prev=newnode;
        tail=newnode;
    }
    return head;
}
void displayForward()
{
    if(head==0)
    {
        printf("Linked list empty\n");
    }
    else
    {
        temp=head;
        while(temp->next != head)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
void displayBackward()
{
    if(head==0)
    {
        printf("Linked list empty\n");
    }
    else
    {
        temp=tail;
        while(temp->prev!=tail)
        {
            printf("%d\t",temp->data);
            temp=temp->prev;
        }
        printf("%d\n",temp->data);
    }
}
NODE* DeleteBeginning(NODE *head)
{
    if(head==0)
    {
         printf("Linked list empty\n");
    }
    else if(head->prev==head && head->next==head)
    {
        temp=head;
        printf("The item deleted is %d\n",temp->data);
        head=tail=0;
        free(temp);
    }
    else
    {
        temp=head;
        printf("The item deleted is %d\n",temp->data);
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
    }
    return head;
}
NODE* DeleteEnd(NODE *head)
{
     if(head==0)
    {
         printf("Linked list empty\n");
    }
    else if(head->prev==head && head->next==head)
    {
        temp=head;
        printf("The item deleted is %d\n",temp->data);
        head=tail=0;
        free(temp);
    }
    else
    {
        temp=tail;
        printf("The item deleted is %d\n",temp->data);
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(temp);
    }
    return head;

}
NODE* DeletePos(NODE *head)
{
     int pos; printf("Enter position from which node is to be deleted:\n"); scanf("%d",&pos);
     if(pos==1)
     {
         head=DeleteBeginning(head);
     }
     else if(head==0)
     {
         printf("Linked list  empty!\n");
     }
     else if(head->next==0 && head->prev==0)
     {
         head=0;
     }
     else
     {
         int count=0;
         temp=head;
         while(temp->next!=head)
         {
             count++;
             temp=temp->next;
         }
         if(pos>count)
         {
             printf("Enter valid position\n");
         }
         else if(pos==count)
         {
             head=DeleteEnd(head);
         }
         else
         {
             temp=head;
             for(int i=1;i<pos;i++)
             {
                 temp=temp->next;
             }
             temp->prev->next=temp->next;
             temp->next->prev=temp->prev;
             printf("The node deleted is having data :%d\n",temp->data);
             free(temp);
         }
     }
    return head;
}
NODE* InsertPosition(NODE *head)
{
    int pos; printf("Enter position at which node is to be inserted:\n"); scanf("%d",&pos);
    if(head==0 && pos>1)
    {
        printf("Invalid position\n");
    }
    else if(pos==1)
    {
        head=InsertBeginning(head);
    }
    else
    {
        int count=0;
        temp=head;
        while(temp->next !=head)
        {
            count++;
            temp=temp->next;
        }
        count++;  //for last node
        if(pos == count+1)
        {
            head=InsertEnd(head);
        }
        else if(pos > count+1)
        {
            printf("Enter valid position\n");
        }
        else
        {
        newnode=Getnode();
        temp=head;
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        temp->next->prev=newnode;
        }
    }
    return head;
}
int main()
{
   int choice;
   for(;;)
   {
       printf("Operations of Doubly Circular Linked List:\n");
       printf("1.Insert at Beginning\n2.Insert at end\n3.Delete Beginning\n4.Delete End\n5.Display in forward direction\n6.Display in backward direction\n7.Insert at position\n8.Delete from position\n9..Exit\n");
       printf("Enter your choice:\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:head=InsertBeginning(head);
           break;
           case 2:head=InsertEnd(head);
           break;
           case 3:head=DeleteBeginning(head);
           break;
           case 4:head=DeleteEnd(head);
           break;
           case 5:displayForward();
           break;
           case 6:displayBackward();
           break;
           case 7:head=InsertPosition(head);
           break;
           case 8:head=DeletePos(head);
           break;
           case 9:exit(0);
       }
   }

}
