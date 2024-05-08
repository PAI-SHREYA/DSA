
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE;
NODE *head=0;
NODE *newnode=0;
void insert(int x)
{
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=x;
    newnode->next=0;
    newnode->prev=0;
    if(head==0)
    {
        head=newnode;
    }
    else
    {
        NODE *temp=head;
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}
void display(NODE *head)
{
    NODE *temp;
    if(head==0)
    {
        printf("Linked list empty\n");
    }
    else
    {
        temp=head;
        while(temp!=0)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
void duplicate(NODE *head)
{
    if(head==0)
    {
        printf("Linked list empty\n");
    }
    else
    {
        int found=0;
        NODE *temp1;
        NODE *temp2;
        printf("\nPrinting the duplicates:\n");
        for(temp1=head;temp1!=0;temp1=temp1->next)
        {
            for(temp2=temp1->next;temp2!=0;temp2=temp2->next)
            {
                if(temp1->data == temp2->data)
                {
                    found=1;
                    printf("%d\t",temp1->data);
                    break;
                }
            }
        }
        if(found==0)
        {
            printf("No duplicates\n");
        }
    }
}
void sort(NODE *head)
{
    if(head==0)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        int temp;
        NODE *temp1;
        NODE *temp2;
        for(temp1=head;temp1!=0;temp1=temp1->next)
        {
            for(temp2=temp1->next;temp2!=0;temp2=temp2->next)
            {
                if(temp2->data > temp1->data)
                {
                    temp=temp2->data;
                    temp2->data=temp1->data;
                    temp1->data=temp;
                }
            }
        }
    }
}
int main()
{
    int n,x;
    printf("Enter the number of nodes in the linked list:\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter the element to be inserted:\n"); scanf("%d",&x);
        insert(x);
    }
    display(head);
    duplicate(head);
    printf("\nThe linked list in descending order is :\n");
    sort(head);
    display(head);

}
