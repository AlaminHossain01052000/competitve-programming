// https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data=val;
        left=NULL;
        right=NULL;
    }
};
unordered_map<string,int>m;
//tree serealization
string solve(Node* root){
        //if current node is NULL then return $
        if(!root)return "$";
        string s="";
        //if the node is leaf node then do not add this at map rather return the value of the root->data only
        if(!root->left&&!root->right){
            s+=root->data;
            return s;
        }
        
        s+=root->data;//Add root->data to the string
        s+=solve(root->left);//Add root->left->data to the string
        s+=solve(root->right);//Add root->right->data to the string
        m[s]++;//Increase the count of the string by 1
        return s;
        
    }
    int dupSub(Node *root) {
         // code here
         
         m.clear();
         solve(root);
         int ans=0;//Number of duplicate subtree in the tree
         //Count each memer of the map and if we find the count any string more than 1 then it has duplicate subtree in the tree
         for(auto it:m){
             if(it.second>=2){
                 ans++;
             }
         }
         return ans;
         
    }
int main(){
    Node* root=new Node(1);
    Node* node1=new Node(2);
    Node* node2=new Node(3);
    Node* node3=new Node(4);
    Node* node4=new Node(5);
    //subtree
    Node* node5=new Node(2);
    Node* node6=new Node(4);
    Node* node7=new Node(5);
    root->left=node1;
    root->right=node2;
    node1->left=node3;
    node1->right=node4;
    node2->right=node5;
    node5->left=node6;
    node5->right=node7;
    cout<<dupSub(root)<<endl;
}
//Level order traversal of given tree: 1 2 3 4 5 N 2 4 5
//output=1