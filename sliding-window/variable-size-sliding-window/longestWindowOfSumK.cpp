//You are given an array {1,2,-4,4,2,-2}.You have to find the longest window of sum 4.Here the answer is {2,-4,4,2}  or i=2 to j=4(1-based indexing).The sum=(2-4+4+2)=4. As total number of elements are 4 hence the answer is 4
//https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestWindowOfSumK(vector<int> &v, int k){ 
    int n=v.size();
    long long int prefixSum=0;
    unordered_map<long long int,int> mp;
    int ans=0;
    for(int i=0;i<n;++i){
        prefixSum+=v[i];
        if(prefixSum==k)ans=max(ans,i+1);
        if(mp[prefixSum]==0)mp[prefixSum]=i+1;
        if(mp[prefixSum-k]!=0){
            ans=max(ans,i+1-mp[prefixSum-k]);
        }
    }
    return ans;
} 
int main(){
    vector<int>v={1,2,-4,4,2,-2};
    int k=4;
    cout<<lengthOfLongestWindowOfSumK(v,k)<<"\n";
}