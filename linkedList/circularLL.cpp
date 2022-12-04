#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data=data;
            this->next=NULL;
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
void insert(Node* &tail,int value,int leftValue){
    //empty list
    if(tail==NULL){
        Node* newNode=new Node(value);
        newNode->next=newNode;
        tail=newNode;
        return;
    }
    Node *temp=tail;
    while(temp->data!=leftValue){
        temp=temp->next;
        if(temp==tail){
            cout<<"This element is not exist in the list\n";
            return;
        }
    }

    Node* newNode=new Node(value);
    
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
void deleteNode(Node* &tail,int value){
    if(tail==NULL){
        cout<<"Nothing to delete\n";
    }
    Node* temp=tail;
    do{
        if((temp->next)->data==value){
            break;
        }
        temp=temp->next;
    }while(temp!=tail);
    if(temp->next==tail){
        Node* deletedNode=temp->next;
        temp->next=tail->next;
        tail=temp;
        deletedNode->next=NULL;
        delete deletedNode;
        return;
    }
    Node* deletedNode=temp->next;
    temp->next=(temp->next)->next;
    deletedNode->next=NULL;
    delete deletedNode;
    
}
int main(){
    Node* tail=NULL;
    insert(tail,5,-1);
    insert(tail,10,5);
    insert(tail,15,10);
    insert(tail,18,-1);
    insert(tail,20,15);
    printLL(tail);
    cout<<tail->data<<endl;
    deleteNode(tail,5);

    // cout<<tail->data<<endl;
    insert(tail,30,20);
    
    printLL(tail);
}