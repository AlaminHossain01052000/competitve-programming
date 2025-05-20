// https://www.interviewbit.com/problems/sliding-window-maximum/
//You are given an array {3,1,2,1}. You have to tell the maximul element of each k size window.For example
// if k=2 then
// max{3,1}=3
// max{1,2}=2
// max{2,1}=2
// answer={3,2,2}
#include<bits/stdc++.h>
using namespace std;
//complexity O(n+k)-Not Proved
vector<int> slidingWindowMaximum(vector<int>&v,int k){
    vector<int>ret;
    int n=v.size();
    
    if(k>=n){
        ret.push_back(*max_element(v.begin(),v.end()));
        return ret;
    }
    if(n==1){
        ret.push_back(v[0]);
        return ret;
    }
    deque<int>dq;
    int j=0;
    for(int i=0;i+k-1<n;++i){
        while(j-i+1<=k){
            while(dq.size()>0&&dq.back()<v[j])dq.pop_back();//Delete all the element of the dq which are less than current j so that j can sit in the front of dq
            dq.push_back(v[j]);
            j++;
        }
        ret.push_back(dq.front());
        if(dq.front()==v[i])dq.pop_front();

    }
    return ret;
}
int main(){
    vector<int>v={1, 3, -1, -3, 5, 3, 6, 7};
    int k=3;
    vector<int>ret;
    ret=slidingWindowMaximum(v,k);
    for(auto &ele:ret)cout<<ele<<" ";
    cout<<endl;
}