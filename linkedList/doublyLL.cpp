#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int data){
            this->data=data;
            this->prev=NULL;
            this->next=NULL;
        }
        //destructor
        ~Node(){
            int val=this->data;
            if(next!=NULL){
                delete next;//deleting next node from memory
                this->next=NULL;
                this->prev=NULL;
            }
            cout<<"Node containing "<<val<<" is deleted successfully\n";
        }

};
void printLL(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void insertAtPosition(int position,int data,Node* &head,Node* &tail){
    Node* newBornNode=new Node(data);
    if(position==1){
        if(head==NULL){
            head=newBornNode;
            tail=newBornNode;
            return;
        }
        head->prev=newBornNode;
        newBornNode->next=head;
        head=newBornNode;
        return;
    }
    Node* temp=head;
    for(int i=1;i<position-1;++i){
        temp=temp->next;
        if(temp==NULL){
            return;
        }
    }
    if(temp->next==NULL){
        newBornNode->prev=temp;
        temp->next=newBornNode;
        tail=newBornNode;
        return;
    }

    newBornNode->next=temp->next;
    newBornNode->prev=temp;
    (temp->next)->prev=newBornNode;
    temp->next=newBornNode;
}
void deleteAtPosition(int position,Node* &head,Node* &tail){
    if(head==NULL||tail==NULL){
        return;
    }
    if(position==1){
        Node* deletableNode=head;
        if(head->next==NULL){
            head=NULL;
            tail=NULL;

        }
        else{
            (head->next)->prev=NULL;
            head=head->next;
        }

        deletableNode->next=NULL;
        deletableNode->prev=NULL;
        delete deletableNode;
        return;
    }
    Node* temp=head;
    for(int i=1;i<position;++i){
        temp=temp->next;
    }
    if(temp->next==NULL){
        Node* deletableNode=temp;
        (temp->prev)->next=NULL;
        tail=temp->prev;
        deletableNode->prev=NULL;
        deletableNode->next=NULL;
        delete deletableNode;
        return;
    }
    Node* deletableNode=temp;
    (temp->prev)->next=temp->next;
    (temp->next)->prev=temp->prev;
    deletableNode->prev=NULL;
    deletableNode->next=NULL;
    delete deletableNode;
    return;
}
int main(){
    // Node* node1=new Node(10);
    Node* head=NULL;
    Node* tail=NULL;
    // printLL(head);
    insertAtPosition(1,5,head,tail);
    // deleteAtPosition(1,head,tail);
    insertAtPosition(1,4,head,tail);
    
    insertAtPosition(1,3,head,tail);

    insertAtPosition(4,10,head,tail);
    insertAtPosition(5,11,head,tail);
    insertAtPosition(6,14,head,tail);
    insertAtPosition(6,13,head,tail);

    // insertAtPosition(500,1500,head,tail);
    printLL(head);
    deleteAtPosition(1,head,tail);
    printLL(head);
    deleteAtPosition(6,head,tail);
    printLL(head);
    deleteAtPosition(3,head,tail);
    printLL(head);
    cout<<head->data<<" "<<tail->data<<endl;
    


}