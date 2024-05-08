typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE *head=0;
NODE *newnode=0;
NODE *temp=0;
NODE* Getnode()
{
    newnode=(NODE*)malloc(sizeof(NODE));
    if(newnode==0)
    {
        printf("node can not be created\n");
        exit(0);
    }
    printf("Enter the data part of newly created node:\n");
    scanf("%d",&newnode->data);
    newnode->next=newnode;

    return newnode;
}
NODE* InsertEnd(NODE *head)
{
    newnode=Getnode();
    if(head==0)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next != head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
    return head;
}
NODE* InsertFront(NODE *head)
{
    newnode=Getnode();
    if(head==0)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next != head)
        {
            temp=temp->next;
        }
        newnode->next=head;
        temp->next=newnode;
        head=newnode;

    }
    return head;
}
void display(NODE *head)
{
    temp=head;
    if(head==0)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp->next != head)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
NODE* DeleteEnd(NODE *head)
{
    NODE *prev=0;
    temp=head;
    if(head==0)
    {
        printf("node cannot be deleted as list is empty\n");
    }
    else if(head->next == head)
    {
        printf("item deleted is %d\n",head->data);
        free(temp);
        head=0;
    }
    else
    {
        while(temp->next !=head)
        {
            prev=temp;
            temp=temp->next;
        }
        printf("item deleted is %d\n",temp->data);
        prev->next=temp->next;
        free(temp);
    }
    return head;
}
NODE* DeleteFront(NODE *head)
{
    if(head==0)
    {
        printf("node cannot be deleted as list is empty\n");
    }
    else if(head->next == head)
    {
        printf("item deleted is %d\n",head->data);
        free(temp);
        head=0;
    }
    else
    {
        temp=head;
        NODE *del=head;
        while(temp->next != head)
        {
            temp=temp->next;
        }
        head=head->next;
        temp->next=head;
        printf("Item deleted is %d\n",del->data);
        free(del);
    }
    return head;
}
NODE* DeletePos(NODE *head,int pos)
{
    temp=head;
    NODE *prev=0;
    if(head==0)
    {
        printf("list is empty\n");
    }
    else if(head->next == head)
    {
        printf("item deleted is %d\n",head->data);
        free(temp);
        head=0;
    }
    else if(pos==1)
    {
        head=DeleteFront(head);
    }
    else
    {
        int count=1;
        while(temp->next != head  && count!=pos)
        {
            prev=temp;
            temp=temp->next;
            count++;
        }
        if(pos ==count)
        {
            prev->next=temp->next;
            printf("item deleted is %d\n",temp->data);
            free(temp);
        }
        else if(pos == count+1)
        {
            prev->next=head;
            printf("item deleted is %d\n",temp->data);
            free(temp);
        }
        else
        {
            printf("Enter a valid position\n");
        }
    }
    return head;
}
NODE* InsertPos(NODE *head,int pos)
{
    if(head==0)
    {
        newnode=Getnode();
        head=newnode;
    }
    else if(pos==1)
    {
        head=InsertFront(head);
    }
    else
    {
        int count=1;
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
            count++;
        }
        if(pos > count+1)
        {
            printf("Enter valid position,less than %d\n",count+1);
        }
        else if(pos == count+1)  //insert at end
        {
            head=InsertEnd(head);
        }
        else
        {
            newnode=Getnode();
            int i=1;
            temp=head;
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    return head;
}
int main()
{
    int choice;
    int pos;
    for(;;)
    {
        printf("\n\nOPERATIONS ON CIRCULAR SINGLY LINKED LIST\n\n");
        printf("1.Insert at beginning\n2.Insert at end\n3.Insert at specified position\n4.Delete from Front\n5.Delete from end\n6.Delete from specified position\n7.Display circular linked list\n8.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:head=InsertFront(head);
            break;
            case 2:head=InsertEnd(head);
            break;
            case 3:printf("Enter position where node is to be inserted:\n");
            scanf("%d",&pos);
            head=InsertPos(head,pos);
            break;
            case 4:head=DeleteFront(head);
            break;
            case 5:head=DeleteEnd(head);
            break;
            case 6:printf("Enter position from where node is to be deleted:\n");
            scanf("%d",&pos);
            head=DeletePos(head,pos);
            break;
            case 7:display(head);
            break;
            default:printf("Enter valid choice\n");
            break;
        }
    }

}
