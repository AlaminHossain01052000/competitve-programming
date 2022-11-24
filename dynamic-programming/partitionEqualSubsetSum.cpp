#include<bits/stdc++.h>
using namespace std;
int dp[210][20010];
int solve(int remainingSum,vector<int>& nums,int ind){
    if(remainingSum==0){
        return 1;
    }
    //remainingSum>0 but there is no index or element is left of the array to make the remaining sum. So the answer is false
    if(ind<0){
        return 0;
    }
    if(dp[ind][remainingSum]!=-1)return dp[ind][remainingSum];
    //exclude
    int a=solve(remainingSum,nums,ind-1);
    //include
    int b=0;
    if(remainingSum-nums[ind]>=0)
        b=solve(remainingSum-nums[ind],nums,ind-1);
    //if any of a or b is true then the answer is true
    if(a||b){
        return dp[ind][remainingSum]=1;
    }
    else return dp[ind][remainingSum]=0;
}
bool canPartition(vector<int>& nums) {
    memset(dp,-1,sizeof(dp));
     int n=nums.size();
    int sum=0;
    for(int i=0;i<n;++i){
        sum+=nums[i];
    } 
    //The Partitions of an array is equal is the sum of the both of them is even
    if(sum%2==0){
        //let if leftSubarray=rightSubarray of an array then sum of their one part is equal to other. So sum of every part together make total sum
        
        if(solve(sum/2,nums,n-1)){
            return true;
        }
        else return false;
    }
    else return false;
}
int main(){
    vector<int> nums = {1,5,11,5};
    int n=4;
    cout<<canPartition(nums)<<endl;
    
}