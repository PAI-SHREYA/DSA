#include<iostream>
using namespace std;
int size=0;
class Node
{
    public:
     int data;
     Node *next;
     Node(int data)
     {
        size++;
        this->data=data;
        this->next=NULL;

     }
};
void InsertAtHead(Node* &head,int data)
{
    Node* node=new Node(data);
    node->next=head;
    head=node;
    // cout<<node->data;

}
void printList(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        // cout<<"temp"<<endl;
        cout<<temp->data<<endl;
        temp=temp->next;

    }

}
void InsertAtEnd(Node* &tail,int data)
{
  Node* node= new Node(data);
  tail->next=node;
  tail=node;
}
void InsertAtMid(Node* &head,int data,int pos)
{


    if(pos==0)
    {
        InsertAtHead(head,data);
        return;
    } 
    else if (size<pos){
        cout<<"Out of Range size is "<<size<<endl;
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
        Node* node=new Node(data);
        prev->next=node;
        node->next=curr;
    }
}
void deleteHead(Node* &head)
{
    if(head==NULL) cout<<"List is empty"<<endl;
    Node* temp=head->next;
    cout<<head->data<<" deleted"<<endl;
    delete(head);
    head=temp;
    size--;
    // return;
}
void deletePos(Node* head,int pos)
{
  
    if(pos==0) deleteHead(head);
    else if(pos>=size)
    {
        cout<<"Out of range"<<endl;
        return;
    }
    else{
          Node* prev=NULL;
          Node* curr=head;
          for(int i=0;i<pos;i++)
          {
            prev=curr;
            curr=curr->next;
          }
          prev->next=curr->next;
          cout<<curr->data<<" deleted\n";
          delete(curr);
    }
}
int main(){
    Node* node1=new Node(10);     
   
    // node1->data=10;
    // node1->next=node1;
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    Node* head=node1;
    Node* tail=node1;
    // printList(head);
    InsertAtHead(head,15);
    InsertAtHead(head,20);
    InsertAtMid(head,16,1);
    printList(head);
    cout<<"Post delete"<<endl;
    deleteHead(head);
    printList(head);
    InsertAtEnd(tail,5);
    InsertAtEnd(tail,0);
    InsertAtMid(head,1,0);
    InsertAtMid(head,11,100);
    deletePos(head,1);
    deletePos(head,11);
    deletePos(head,4);
    printList(head);
    
}