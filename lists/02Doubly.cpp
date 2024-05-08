#include<iostream>
using namespace std;
int size=0;
class Node
{
    public:
      int data;
      Node* prev;
      Node* next;
    Node(int data)
    {
       this->data=data;
       this->prev=NULL;
       this->next=NULL;
    }

};
void displayList(Node* head)
{
    if(head==NULL) cout<<"list is empty"<<endl;
    Node* temp=head;
    while(temp)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int getLength(Node* head)
{
    Node* temp=head;
    int count =0;
    while (temp)

    {
        count++;
        temp=temp->next;
    }
    return count;
    
}
void insertAtHead(Node* &head,Node* &tail,int data)
{
    
    Node* node=new Node(data);
    if(head==NULL)
    {
        head=node;
        tail=node;
        return;
    }
    node->next=head;
    head->prev=node;
    head=node;
}
void insertAtEnd(Node* &head,Node* &tail,int data)
{
    
    Node* node=new Node(data);
    if(tail==NULL)
    {
        tail=node;
        head=node;
        return;
    }
    tail->next=node;
    node->prev=tail;
    tail=node;
}
void InsertAtPos(Node* &head,Node* &tail,int data,int pos)
{
    if(pos>getLength(head)) 
    {
        cout<<"Out of range";
        return;

    }
    else if(pos==0) 
    {
        insertAtHead(head,tail,data);
        return;
    }
    else if(pos==getLength(head))
    {
        insertAtEnd(head,tail,data);
        return;
    }
    else
    {
        Node* node=new Node(data);
        Node* curr=head;
        Node* prev=NULL;
        for(int i=0;i<pos;i++)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=node;
        node->prev=prev;
        node->next=curr;
        curr->prev=node;
    }
}
void displayReverse(Node* &tail)
{
    Node* curr=tail;
    cout<<"Reverse List: ";
    while(curr)
    {
        cout<<curr->data<<"  ";
        curr=curr->prev;
    }
    cout<<endl;
}
void deleteHead(Node* &head)
{   
    if(head==NULL)
    {
        cout<<"List empty\n";
        return;
    }
    Node* curr=head;
    
    head=curr->next;
    head->prev=NULL;
    free(curr);

}
void deleteTail(Node* &tail)
{
    Node* temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
}
void deletePos(Node* head,Node* tail,int pos)
{
    if(pos>=getLength(head))
    {
        cout<<"Invalid position\n";
    }
    else if(pos==0)
    {
        deleteHead(head);
        return;

    }
    else if(pos==getLength(head)-1)
    {
        deleteTail(tail);
        return;
    }
    else
    {
        Node* prev=NULL;
        Node* curr=head;
        for(int i=0;i<pos;i++)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        curr->next->prev=prev;
        free(curr);
    }
    
}
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    //   displayList(head);
    Node* node=new Node(10);
    head=node;  
    tail=node;
    // displayList(head);
    // cout<<getLength(head);
    insertAtHead(head,tail,1);

    // displayList(head);
    // cout<<getLength(head);

    insertAtEnd(head,tail,23);
    InsertAtPos(head,tail,500,3);
    InsertAtPos(head,tail,2,1);
    InsertAtPos(head,tail,0,0);

     displayList(head);
    cout<<getLength(head);
    deleteHead(head);
    cout<<"After delete head\n";
    displayList(head);
    cout<<getLength(head);
     cout<<"After delete tail\n";
     deleteTail(tail);
    displayList(head);
    cout<<getLength(head);
     cout<<"After delete at position\n";
     deletePos(head,tail,2);
    displayList(head);
    cout<<getLength(head);

    // displayReverse(tail);
    return 0;
}