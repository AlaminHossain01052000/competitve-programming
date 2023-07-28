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
//Check whether there is a loop or not
bool floydsHasCycle(Node *head){
    if(head==NULL)return false;
    Node* slow=head;
    Node* first=head;
    while(slow!=NULL&&first!=NULL){
        slow=slow->next;
        first=first->next;
        if(first!=NULL){
            first=first->next;
        }
        if(slow==first)return true;
        
    }
    return false;

}
//Remove the cycle from the loop

//find the node which is start of the loop
Node* findInterSectedNode(Node* head,Node* slow){
    Node* temp=head;
    while(temp!=slow){
        temp=temp->next;
        slow=slow->next;
    }
    return temp;
}
//Detect start node of loop
Node* floydDetectFirstNodeOfLoop(Node *head){
    if(head==NULL){
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL && fast!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL)fast=fast->next;
        if(slow==fast){
            Node* intersectedNode=findInterSectedNode(head,slow);
            return intersectedNode;
        }
    }
    return NULL;

}
Node* floydRemoveLoop(Node* &head){
    Node* startingNodeOfLoop=floydDetectFirstNodeOfLoop(head);
    if(startingNodeOfLoop==NULL){
        return head;
    }
    Node* temp=startingNodeOfLoop;
    while(temp->next!=startingNodeOfLoop){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;

}
int main(){
    Node* node1=new Node(10);
    Node* node2=new Node(20);
    Node* node3=new Node(30);
    Node* node4=new Node(40);
    Node* node5=new Node(50);
    Node* node6=new Node(60);
    // Node* node5=new Node(50);
    node6->next=node2;
    node5->next=node6;
    node4->next=node5;
    node3->next=node4;
    node2->next=node3;
    node1->next=node2;
    Node* head=node1;

    //finding head of loop in a Linked List
    Node* intersectedNode=floydDetectFirstNodeOfLoop(head);
    if(intersectedNode==NULL)
        cout<<"There is no loop\n";
    else cout<<"Loop is exist at value"<<intersectedNode->data<<endl;

    //remove loop using floyd's cycle algoritm        
    head=floydRemoveLoop(head);
    cout<<floydsHasCycle(head)<<endl;
    
}