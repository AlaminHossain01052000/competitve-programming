#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data){
            this->data=data;
            this->next=NULL;
            this->prev=NULL;
        }
        ~Node(){
            int deletedValue=this->data;
            if(this->next!=NULL){
                delete next;
                this->next=NULL;

            }
            cout<<deletedValue<<" is deleted successfully\n";
        }
};
//Insert after a particular value
void insert(Node* &tail,int position,int value){
    Node* newNode=new Node(value);
    //empty list
    if(tail==NULL){
        
        newNode->next=newNode;
        tail=newNode;
        return;
    }
    Node *temp=tail->next;
    for(int i=1;i<position-1;++i){
        temp=temp->next;
        if(temp==tail->next)return;
    }

    newNode->prev=temp;
    (temp->next)->prev=newNode;
    newNode->next=temp->next;
    temp->next=newNode;
}
void printLL(Node *tail){
    Node* temp=tail->next;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;

    }while(temp!=tail->next);
    cout<<endl;

}
void reversePrint(Node *tail){
    while(tail->prev!=NULL){
        cout<<tail->data<<" ";
        tail=tail->prev;
    }cout<<endl;
}
void deleteNode(Node* &tail,int position){
    if(tail==NULL){
        cout<<"Nothing to delete\n";
    }
    Node* temp=tail->next;
    for(int i=1;i<position;++i){

        temp=temp->next;
        if(temp==tail->next){
            return;
        }
    }
    if(temp==tail){
        Node* deletableNode=temp;
        (temp->prev)->next=temp->next;
        tail=temp->prev;
        deletableNode->next=NULL;
        deletableNode->prev=NULL;
        delete deletableNode;

    }
    else{
        (temp->prev)->next=temp->next;
        (temp->next)->prev=temp->prev;
        Node* deletableNode=temp;
        deletableNode->prev=NULL;
        deletableNode->next=NULL;
        delete deletableNode;
    }
    
}
int main(){
    Node* tail=NULL;
    insert(tail,-1,100);
    insert(tail,1,10);
    insert(tail,2,20);
    insert(tail,3,500);
    // insert(tail,20,1);
    printLL(tail);
    cout<<tail->data<<endl;
    deleteNode(tail,3);
    printLL(tail);
    cout<<tail->data<<endl;
    // reversePrint(tail);

   
}