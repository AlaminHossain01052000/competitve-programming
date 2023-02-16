// https://www.geeksforgeeks.org/minimum-swap-required-convert-binary-tree-binary-search-tree/
// Given an array of Complete Binary Tree. Find Minumum number of swaps to convert it into a Binary Search Tree.
// In Complete Binary Tree Index 2*i+1 is the left child and index 2*i+2 is the right child of the node i
#include<bits/stdc++.h>
using namespace std;
vector<int> nums;//given/input array
vector<int> temp;//store the result of inorder traversal of given array
void inorderTraversal(int i,int n){
    if(i>=n)return;
    //Left
    inorderTraversal((2*i+1),n);
    //root
    temp.push_back(nums[i]);
    //right
    inorderTraversal((2*i+2),n);

}
int numberOfSwaps(){
    vector<pair<int,int>> v(temp.size()); //store the inordered traversed given array along with their corresponding index
    int n=temp.size();
    // cout<<n<<endl;
    for(int i=0;i<n;++i){
        // cout<<temp[i]<<" ";
        v[i].first=temp[i]; //as v[i] is a pair
        v[i].second=i;
    }
    sort(v.begin(),v.end());//sort the pair storage vector in the order of increasing number of element not in the order of the index

    //Now my aim is to count the number of swapping to convert the sorted array as their previous unsorted state using the index with each element
    
    // for(auto pr:v)cout<<pr.first<<" "<<pr.second<<endl;
    int ans=0;
    for(int i=0;i<n;++i){
        if(i==v[i].second)continue;//If the sorted element already placed in the right order
        else{
            swap(v[i].first,v[v[i].second].first); //swapping the element only
            swap(v[i].second,v[v[i].second].second);//swapping the index now
            //After the swapping operations if I can't get the element at index i at the right position the I will decrease i by one and will do the same operation again till I get my desired pair in desired location
            if(v[i].second!=i){
                i--;
            }
            ans++;
        }
    }
    // cout<<ans<<endl;
    return ans;
}
int main(){
    nums={5,6,7,8,9,10,11}; //Output Array={8,6,9,5,10,7,11} which is conquired by swapping three elements (8,5),(7,9),(7,10). So the answer is 3
    for(auto ele:nums)cout<<ele<<" ";
    cout<<endl;
    inorderTraversal(0,nums.size());
    cout<<numberOfSwaps()<<endl;
}