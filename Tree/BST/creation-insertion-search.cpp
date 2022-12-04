#include<bits/stdc++.h>
using namespace std;
class bstNode{
    public:
        int data;
        bstNode* left;
        bstNode* right;
        bstNode(int data){
            this->data=data;
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
    else if(root->data<data){
        root->right=insert(root->right,data);
    }
    return root;

}
bool search(bstNode* root,int searchedData){
    if(root==NULL){
        return false;
    }
    else if(root->data==searchedData){
        return true;
    }
    else if(root->data>searchedData){
        return search(root->left,searchedData);
    }
    // root->data<searchedData
    else{
        return search(root->right,searchedData);
    }

}
int findMin(bstNode* root){
    if(root->left==NULL){
        return root->data;
    }
    return findMin(root->left);
}
int findMax(bstNode* root){
    if(root->right==NULL){
        return root->data;
    }
    return findMax(root->right);
}
//height of tree = maximum possible path from root to a leaf node which is far from the root node
int heightOfTree(bstNode* root){
    if(root==NULL){
        return -1;
    }
    return max(heightOfTree(root->left),heightOfTree(root->right))+1;
}
int main(){
    bstNode* root=new bstNode(15);
    root=insert(root,10);
    root=insert(root,8);
    root=insert(root,12);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,18);
    if(search(root,19)){
        cout<<"Found\n";
    }
    else cout<<"Not Found!404";
    cout<<"Minimum element is : "<<findMin(root)<<endl;
    cout<<"Maximum element is : "<<findMax(root)<<endl;
    cout<<"Height of the tree is : "<<heightOfTree(root)<<endl;
    return 0;
}