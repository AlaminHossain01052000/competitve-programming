//Problem:https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
//Video Solution:https://www.youtube.com/watch?v=KtpqeN0Goro&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=3
// You are given an array a, and window size k. You have to find maximum sum of each k size subarray(contiguous) of the array.
// Let a={2,3,1,4,5} and k=3
// 2+3+1=6
// 3+1+4=8
// 1+4+5=10
// ans=max({6,8,10})=10
#include<bits/stdc++.h>
using namespace std;
long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long sum=0;
        long ret=LONG_MIN;
        int j=0;
        for(int i=0;i+K-1<N;++i){
            while(j-i+1<=K)sum+=0LL+Arr[j++]; //Sum of all values of the array within the window
            ret=max(ret,sum);
            sum-=Arr[i];//Excluding the first element to add new value in the end
        }
        return ret;
}
int main(){
    vector<int>Arr={2,3,1,4,5};
    int K=3;//window size
    int N=5;
    cout<<maximumSumSubarray(K,Arr,N);
}