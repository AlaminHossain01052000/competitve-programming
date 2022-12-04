#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next; //pointer to node

        //constructor
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
        //destructor
        ~Node(){
            int val=this->data;
            if(this->next!=NULL){
                delete next;//deleting next node from memory
                this->next=NULL;
            }
            cout<<"Node containing "<<val<<" is deleted successfully\n";
        }

};

void printLinedList(Node* node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}
void deleteAtPosition(Node* &head,Node* &tail,int position){
    //deleting first position
    if(position==1){
        Node* deletableNode=head;
        head=head->next;
        // As deletable->next is pointing to the head->next right now so we should point deletable to NULL before deleting it
        deletableNode->next=NULL;
        delete deletableNode;
        return;
    }
    Node *temp=head;
    for(int i=1;i<position-1;++i){
        temp=temp->next;
        if(temp->next==NULL||temp==NULL){
            return;
        }
    }
    //Deleting node at last position
    if((temp->next)->next==NULL){
        Node* deletableNode=temp->next;
        temp->next=NULL;
        tail=temp;
        delete deletableNode;
        return;
    }
    //deleting a node from any middle positions
    
    Node* deletableNode=temp->next;
    temp->next=(temp->next)->next;
    deletableNode->next=NULL;
    delete deletableNode;

}
void deleteByValue(Node* &head,Node* &tail,int data){
    //Deleting First Node
    if(head->data==data){
        Node* deletebleNode=head;
        head=head->next;
        deletebleNode->next=NULL;
        delete deletebleNode;
        return;
    }
    Node* temp=head;
    
    while( (temp->next)->data !=data&&temp!=NULL){
        
        temp=temp->next;
    }
    if(temp==NULL||temp->next==NULL){
        return;
    }
    //deleting last node
    if((temp->next)->next==NULL){
        Node* deletebleNode=temp->next;
        temp->next=NULL;
        tail=temp;
        delete deletebleNode;
        return;

    }
    //deleting any middle node
    Node* deletableNode=temp->next;
    temp->next=(temp->next)->next;
    deletableNode->next=NULL;
    delete deletableNode;
   
}

void insertionAtStart(Node* &head,int data){
    Node* node1=new Node(data);
    node1->next=head;
    head=node1;
}
void insertionAtEnd(Node* &tail,int data){
    Node* newBornNode=new Node(data);
    Node* oldTail=tail;
    oldTail->next=newBornNode;
    tail=newBornNode;

}

void insertAtPosition(Node* &tail,Node* &head,int position,int data){
    if(position==1){
        insertionAtStart(head,data);
        return;
    }
    Node* newNode=new Node(data);
    Node* temp=head;

    for(int i=1;i<position-1;++i){
        temp=temp->next;
        if(temp==NULL){
            return;
        }
    }
    if(temp->next==NULL){
        insertionAtEnd(tail,data);
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    insertionAtStart(head,15);
    insertionAtStart(head,20);
    insertionAtStart(head,25);

    insertionAtEnd(tail,100);
    insertionAtEnd(tail,200);
    insertionAtEnd(tail,300);

    insertAtPosition(tail,head,3,500);
    insertAtPosition(tail,head,3,-3);
    printLinedList(head);
    deleteAtPosition(head,tail,1);
    printLinedList(head);
    deleteAtPosition(head,tail,3);
    printLinedList(head);
    deleteAtPosition(head,tail,7);
    printLinedList(head);
    
    deleteByValue(head,tail,15);
    printLinedList(head);
    cout<<"Head : "<<head->data<<" and tail : "<<tail->data;
}