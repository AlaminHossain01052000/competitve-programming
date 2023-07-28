#include<bits/stdc++.h>
using namespace std;
class bstNode{
    public:
        int data;
        bstNode* left;
        bstNode* right;
        bstNode(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};
bstNode* insert(bstNode* root,int data){
    if(root==NULL){
        bstNode* newNode=new bstNode(data);
        root=newNode;
        
    }
    else if(root->data>=data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}
void inOrderTraverse(bstNode* root){
    if(root==NULL){
        return;
    }
    inOrderTraverse(root->left);
    cout<<root->data<<" ";
    inOrderTraverse(root->right);
}
bool isBst(bstNode* root,int minimum,int maximum){
    if(root==NULL){
        return true;
    }
    if(root->data>minimum&&root->data<=maximum){
        return isBst(root->left,minimum,root->data);
        return isBst(root->right,root->data,maximum);
    }
    else return false;
}

int main(){
    bstNode* root=new bstNode(15);
    root=insert(root,10);
    root=insert(root,8);
    root=insert(root,8);
    root=insert(root,12);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,18);
    cout<<"Inorder Traversal : ";
    inOrderTraverse(root);
    cout<<endl;
    cout<<isBst(root,INT_MIN,INT_MAX)<<endl;
    
}