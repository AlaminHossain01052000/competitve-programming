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
bstNode* Delete(bstNode* root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			bstNode* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			bstNode* temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			bstNode* temp = findMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
bstNode* deleteNode(bstNode* root,int data){
    if(root==NULL){
        return root;
    }
    if(data>root->data)root->right=deleteNode(root->right,data);
    else if(data<root->data)root->left=deleteNode(root->left,data);
    else{
        if(root->left==NULL&&root->right==NULL){
        root=NULL;
        delete root;
        }
        else if(root->left==NULL){
            bstNode* deletableNode=root;
            root=root->right;
            delete deletableNode;
        }
        else if(root->right==NULL){
            bstNode* deletableNode=root;
            root=root->left;
            delete deletableNode;
        }
        else{
            bstNode* temp=findMin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,root->data);

        }
        return root;
    }

    return root;
}
int main(){
    bstNode* root=new bstNode(15);
    root=insert(root,10);
    root=insert(root,8);
    
    root=insert(root,12);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,18);
    cout<<"Inorder Traversal : ";
    inOrderTraverse(root);
    cout<<endl;
    cout<<isBst(root,INT_MIN,INT_MAX)<<endl;
    inOrderTraverse(deleteNode(root,20));
    // inOrderTraverse(Delete(root,20));
}