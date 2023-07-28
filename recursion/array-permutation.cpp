#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &ans,int index,vector<int>& nums ){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=index;j<nums.size();++j){
            swap(nums[j],nums[index]);
            solve(ans,index+1,nums);
            swap(nums[j],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(ans,0,nums);
        return ans;
    }
int main(){
    vector<int> nums={1,2,3};
    auto ans=permute(nums);
    for(auto vec:ans){
        for(auto ele:vec){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}