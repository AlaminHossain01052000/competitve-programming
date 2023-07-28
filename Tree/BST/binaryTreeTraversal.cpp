#include<bits/stdc++.h>
using namespace std;
class bstNode{
    public:
        char data;
        bstNode* left;
        bstNode* right;
        bstNode(int data){
            this->data=data;
            left=NULL;
            right=NULL;
        }
};
void levelOrderTraversal(bstNode* root){
    if(root==NULL){
        return;
    }
    queue<bstNode*> q;
    q.push(root);
    while(!q.empty()){
        bstNode* currentNode=q.front();
        cout<<currentNode->data<<" ";
        if(currentNode->left!=NULL)
            q.push(currentNode->left);
        if(currentNode->right!=NULL)
            q.push(currentNode->right);
        q.pop();
    }
    cout<<endl;
}
void preOrder(bstNode* root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(bstNode* root){
    if(root==NULL)return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(bstNode* root){
    if(root==NULL)return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    bstNode* root=new bstNode('F');
    bstNode* node1=new bstNode('D');
    bstNode* node2=new bstNode('J');
    root->left=node1;
    root->right=node2;
    bstNode* node3=new bstNode('B');
    bstNode* node4=new bstNode('E');
    node1->left=node3;
    node1->right=node4;
    bstNode* node5=new bstNode('G');
    bstNode* node6=new bstNode('K');
    node2->left=node5; 
    node2->right=node6;
    bstNode* node7=new bstNode('A');
    bstNode* node8=new bstNode('C');
    node3->left=node7;
    node3->right=node8;
    bstNode* node9=new bstNode('T');
    node5->right=node9;
    bstNode* node10=new bstNode('H');
    node9->left=node10;
    levelOrderTraversal(root);

    cout<<"PREORDER : ";
    preOrder(root);
    cout<<endl;
    cout<<"INORDER : ";
    inOrder(root);
    cout<<endl;
    cout<<"POSTORDER : ";
    postOrder(root);
    cout<<endl;
}