//Problem:https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
//Video Solution:https://www.youtube.com/watch?v=uUXXEgK2Jh8&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=4
// You are given an array a, and window size k. You have to find first negative element of each k size subarray(contiguous) of the array.
// Let a={2,-3,-1,4,5} and k=2
//  {2,-3}=-3
// {-3,-1}=-3
// {-1,4}=-1
// {4,5}=0 As No negative number is exist

#include<bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
        
        
        int j=0;
        
        list<int>l;
        vector<long long> ret;
        for(int i=0;i+K-1<N;++i){
         
            while(j-i+1<=K){
                if(A[j]<0){
                   l.push_back(A[j]);
                }
                j++;
            }
            if(l.empty()){
                ret.push_back(0);
            }
            else{
                ret.push_back(l.front());
            }
            if(A[i]<0)l.pop_front();
        }
        return ret;                                        
}
int main(){
    long long int A[5] = {-1,-2,3,4,5};
    long long int K=3;//window size
    long long int N=5;
    auto ret=printFirstNegativeInteger(A,N,K);
    for(auto &ele:ret)cout<<ele<<" ";
    cout<<endl;
}