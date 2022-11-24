#include <bits/stdc++.h> 
using namespace std;
void solve(vector<string> &ans,int index,string output,string s){
    if(index>=s.length()){
        if(output.length()>=1){
            ans.push_back(output);
        }
        return;
    }
    solve(ans,index+1,output,s);
    
    output+=s[index];
    solve(ans,index+1,output,s);
}
vector<string> subsequences(string str){
	
	// Write your code here
    vector<string> ans;
    string output="";
	solve(ans,0,output,str);
    
    return ans;
}
int main(){
    string s="abc";
    auto ans=subsequences(s);
    for(auto str:ans){
            cout<<str<<" ";
        
    }
    cout<<endl;

}