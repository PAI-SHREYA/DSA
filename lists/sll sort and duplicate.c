#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE *head=0;
NODE *newnode=0;
void insert(int x)
{
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=x;
    newnode->next=0;
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
    }
}
void display()
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
        printf("\nThe duplicate elements are:\n");
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
            printf("No duplicates!!");
        }
    }
}
void sort(NODE *head)
{
    NODE *temp1;
    NODE *temp2;
    int temp;
    for(temp1=head;temp1!=0;temp1=temp1->next)
    {
        for(temp2=temp1->next;temp2!=0;temp2=temp2->next)
        {
            if(temp1->data > temp2->data)
            {
                temp=temp1->data;
                temp1->data=temp2->data;
                temp2->data=temp;
            }
        }
    }
}
int main()
{
    insert(23);
    insert(2);
    insert(22);
    insert(893);
    insert(-1);
    insert(0);
    insert(0);
    display();
    duplicate(head);
    sort(head);
    printf("\nLinked list after sorting\n");
    display();

}
