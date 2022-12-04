#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data=val;
            next=NULL;
        }
};
void printll(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
Node* getMiddle(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node* reverseLL(Node* head){
    Node* temp1=head;
    Node* temp2=NULL;
    while(temp1!=NULL){
        Node* temp3=temp1->next;
        temp1->next=temp2;
        temp2=temp1;
        temp1=temp3;
    }
    return temp2;
}
bool isPalindrome(Node* head){
    if(head==NULL||head->next==NULL)return true;
    Node* middle=getMiddle(head);
    middle->next=reverseLL(middle->next);
    printll(head);
    Node* temp1=head;
    Node* temp2=middle->next;
    while(temp2!=NULL){
        if(temp1->data!=temp2->data){
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}

int main(){
    Node* node1=new Node(10);
    Node* node2=new Node(20);
    Node* node3=new Node(30);
    Node* node4=new Node(30);
    Node* node5=new Node(20);
    Node* node6=new Node(10);
    // Node* node5=new Node(50);
    node6->next=NULL;
    node5->next=node6;
    node4->next=node5;
    node3->next=node4;
    node2->next=node3;
    node1->next=node2;
    Node* head=node1;
    printll(head);
    //finding head of loop in a Linked List
   cout<<isPalindrome(head)<<endl;
    
}