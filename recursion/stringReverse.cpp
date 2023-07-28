#include<bits/stdc++.h>
using namespace std;

void stringReverser(string &s,int left,int right){
    if(left>right)return;
    if(left<=right){
        swap(s[left],s[right]);
    }
    stringReverser(s,left+1,right-1);

}

int main(){
    string s;
    cin>>s;
    
    stringReverser(s,0,s.length()-1);
    cout<<s<<endl;
}