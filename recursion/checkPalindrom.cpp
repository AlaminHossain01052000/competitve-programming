#include<bits/stdc++.h>
using namespace std;


string convertToBinaryString(long long N){
    string ans="";
    while(N){
         int reminder=N%2;
       ans+=reminder+'0';
        N/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
bool isPalindrom(string s,int i){
    int n=s.length();
    int j=n-i-1;
    if(i>j)return true;
    if(s[i]==s[j]){
        return isPalindrom( s, i+1);
    }
    else return false;

}
bool checkPalindrome(long long N)
{
	// Write your code here.
    string binaryString=convertToBinaryString(N);
    return isPalindrom(binaryString,0);
}

int main(){

    // cout<<isPalindrom(s,0)<<endl;
    cout<<checkPalindrome(15)<<endl;
}