#include<bits/stdc++.h>
using namespace std;


void solve(vector<int>&v,int index,vector<int> output,vector<vector<int>> &ans){
    if(index==v.size()){
        ans.push_back(output);
        return;
    }
    //exlude
    solve(v,index+1,output,ans);

    //include
    int element=v[index];
    output.push_back(element);
    solve(v,index+1,output,ans);
    
}
int main(){
    vector<int> v={2,12,1};
    int n=3;
    vector<vector<int>> ans;
    vector<int> output;
    solve(v,0,output,ans);

    for(auto vec:ans){
        for(auto ele:vec){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

}