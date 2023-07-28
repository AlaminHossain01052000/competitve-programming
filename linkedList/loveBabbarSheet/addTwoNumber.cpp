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
Node* sum(Node* head1,Node* head2){

    Node* a=reverseLL(head1);
    Node* b=reverseLL(head2);
    Node* temp1=a;
    Node* temp2=b;
    int carry=0;
    while(temp1!=NULL&&temp2!=NULL){
        int x=temp1->data;
        int y=temp2->data;
        // cout<<x<<" "<<y<<endl;
        temp1->data=(x+y+carry)%10;
        temp2->data=(x+y+carry)%10;
        carry=(x+y+carry)/10;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    // cout<<temp1->data<<endl;
        if(temp2==NULL&&temp1!=NULL){
            while(temp1!=NULL){
                // cout<<temp1->data<<" "<<carry<<endl;
                int x=temp1->data;
                temp1->data=(x+carry)%10;
                carry=(x+carry)/10;
                temp1=temp1->next;
            }
        }
        if(temp1==NULL&&temp2!=NULL){
            while(temp2!=NULL){
            int x=temp1->data;
            temp2->data=(x+carry)%10;
            carry=(x+carry)/10;
            temp2=temp2->next;
            }
        }
        
    temp1=a;
    temp2=b;
    int count=0;
    while(temp1!=NULL){
        count++;
        temp1=temp1->next;
    }
    int count2=0;
    while(temp2!=NULL){
        count2++;
        temp2=temp2->next;
    }
    if(count>=count2){
        return reverseLL(a);
    }
    else{
        return reverseLL(b);
    }
    
    
}
int main(){
    Node* node1=new Node(6);
    Node* node2=new Node(8);
    Node* node3=new Node(9);
    Node* node4=new Node(1);
    Node* node5=new Node(8);
    Node* node6=new Node(2);
    
    
    node5->next=NULL;
    node4->next=node5;
    node3->next=node6;
    node2->next=node3;
    node1->next=node2;
    Node* head1=node1;
    Node* head2=node4;
    
    printll(head1);
    printll(head2);
    printll(sum(head1,head2));
  
    
}