#include<bits/stdc++.h>
using namespace std;
struct ListNode{
   
        int data;
        ListNode* next;
        ListNode(int x) : data(x), next(nullptr) {}
};
void printLL(ListNode* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void traverseUsingRecur(ListNode *node){
    if(node==NULL){
        
        return;
    }
    traverseUsingRecur(node->next);    
    cout<<node->data<<" ";
    
}
void reverseUsingRecur(ListNode* front,ListNode* back,ListNode* &head){
    if(front==NULL){ 
        head=back;
        return;
    }
    ListNode* temp=front->next;
    front->next=back;
    back=front;
    reverseUsingRecur(temp,front,head);

}
ListNode* reverseList(ListNode* head) {
    if(head==NULL){
        return NULL;
    }
    ListNode* one=NULL;
    ListNode* two=head;
    
    while((two->next)!=NULL){
       ListNode* temp=two->next;

       two->next=one;
      
        one=two;
        two=temp;
        
    }
    head=two;
    two->next=one;
    return head;
}
int main(){
    ListNode* node1=new ListNode(10);
    ListNode* node2=new ListNode(20);
    ListNode* node3=new ListNode(30);
    ListNode* node4=new ListNode(40);
    ListNode* node5=new ListNode(50);
    ListNode* head=node1;
    ListNode* tail=node5;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    printLL(head);
    // traverseUsingRecur(reverseList(head));
    reverseUsingRecur(head,NULL,head);
    printLL(head);
    
}