#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    Node* head=NULL;
    Node* temp=NULL;

    for(int i=1; i<=n; i++){
        Node* newnode= new Node();
        cout<<"Enter data of node "<<i<<": ";
        cin>>newnode->data;
        newnode->next=NULL;

        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }

    Node* display=head;
    cout<<"Linked List: "<<endl;
    while(display!=NULL){
        cout<<display->data<<" -> ";
        display=display->next;
    }
    cout<<"NULL"<<endl;
    
    int value;
    cout<<"Enter the value, after which you want to insert data: ";
    cin>>value;

    Node* insertnode= new Node();
    cout<<"Enter data of the new node, you want to insert after "<<value<<": ";
    cin>>insertnode->data;
    
    Node* temp1=head;
    while(temp1->data!=value){
        temp1=temp1->next;
    }
    Node* temp2=temp1->next;
    temp1->next=insertnode;
    insertnode->next=temp2;
    
    Node* displayinsert=head;
    cout<<"Linked List, after we insert at the end: "<<endl;
    while(displayinsert!=NULL){
        cout<<displayinsert->data<<" -> ";
        displayinsert=displayinsert->next;
    }
    cout<<"NULL"<<endl;

    return 0;
}