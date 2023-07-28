#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int data){
            val=data;
            next=NULL;
        }

};
void printLL(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
ListNode* reverse(ListNode* node){
    // if(node==NULL)return node;
    ListNode* semiHead=NULL;
    ListNode* back=NULL;
    ListNode* front=node;
    while(front->next!=NULL){
        if(front==NULL)break;
        ListNode* temp=front->next;
        front->next=back;
        back=front;
        front=temp;
        
        if(front->next==NULL){
            semiHead=front;
            // cout<<semiHead->val<<" ";
        }
    }
    front->next=back;

    // cout<<semiHead->val<<endl;
    
    return semiHead;
}
void reorderList(ListNode* head) {
    if(head==NULL)return;
        int countOfNodes=0;
        ListNode* temp=head;
        while(temp!=NULL){
            countOfNodes++;
            temp=temp->next;
        }
        temp=head;
        if(countOfNodes==3){
            ((head->next)->next)->next=head->next;
            ListNode* t=head->next;
            head->next=t->next;
            t->next=NULL;
            return;
        }
        int numberOfLeftNodes=countOfNodes%2==0?countOfNodes/2:(countOfNodes/2)+1;
        int numberOfRightNodes=countOfNodes-numberOfLeftNodes;
        // cout<<numberOfLeftNodes<<" "<<numberOfRightNodes<<endl;

        int l=0;
        temp=head;
        if(numberOfLeftNodes%2==0){
            while(l<numberOfLeftNodes){
            if(temp==NULL)break;
            temp=temp->next;
            l++;
            
            }
        }
        else{
            while(l<numberOfLeftNodes-1){
            if(temp==NULL)break;
            temp=temp->next;
            l++;
            
            }
        }
        
        ListNode* semihead=reverse(temp);
        cout<<semihead->val<<endl;
        printLL(semihead);
        // cout<<temp->val<<endl;
        temp=head;
        ListNode* temp2=semihead;

        int k=0;
        while(k<numberOfLeftNodes-1){
            if(temp2==NULL||temp==NULL){
                break;
            }
            ListNode* a=temp->next;
            ListNode* b=temp2->next;
            
            temp2->next=temp->next;
            temp->next=temp2;
            temp=a;
            temp2=b;
            k++;
        }
        // printLL(head);
}

int main(){
    ListNode* node1=new ListNode(10);
    ListNode* node2=new ListNode(20);
    ListNode* node3=new ListNode(30);
    ListNode* node4=new ListNode(40);
    ListNode* node5=new ListNode(50);
    ListNode* node6=new ListNode(60);
    // ListNode* node5=new ListNode(50);
    node5->next=node6;
    node4->next=node5;
    node3->next=node4;
    node2->next=node3;
    node1->next=node2;
    ListNode* head=node1;
    printLL(head);
    reorderList(head);
    printLL(head);
}