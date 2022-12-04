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
bstNode* findMin(bstNode* root){
    if(root->left==NULL){
        return root;
    }
    return findMin(root->left);
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
bstNode* findNode(bstNode* root,int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        return root;
    }
    else if(root->data>data){
        root=findNode(root->left,data);
    }
    else if(root->data<data){
        root=findNode(root->right,data);
    }
    return root;
}
bstNode* inorderSuccessor(bstNode* root,int data){
    bstNode* current=findNode(root,data);
    if(current==NULL)return NULL;
    if(current->right!=NULL){
        return findMin(current->right);
    }
    bstNode* successor=NULL;
    bstNode* ancestor=root;
    while(ancestor!=current){
        if(ancestor->data>current->data){
            successor=ancestor;
            ancestor=ancestor->left;
        }
        else ancestor=ancestor->right;
    }
    return successor;
}
int main(){
    bstNode* root=new bstNode(15);
    root=insert(root,10);
    root=insert(root,8);
    root=insert(root,12);
    root=insert(root,6);
    root=insert(root,25);
    root=insert(root,18);
    root=insert(root,11);
    root=insert(root,20);
    root=insert(root,16);
    root=insert(root,28);
    cout<<"Inorder Traversal : ";
    inOrderTraverse(root);
    cout<<endl;
    cout<<inorderSuccessor(root,12)->data<<endl;
    cout<<inorderSuccessor(root,20)->data<<endl;
    cout<<inorderSuccessor(root,10)->data<<endl;
    cout<<inorderSuccessor(root,16)->data<<endl;
    // inOrderTraverse(Delete(root,20));
}