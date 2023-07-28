#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void addition(string a,string b){
    string ans;
    std::reverse(a.begin(),a.end());

    std::reverse(b.begin(),b.end());
    ll length=min(a.size(),b.size());
    ll carry=0;
    for(ll i=0;i<length;++i){
        ll value=((b[i]-'0')+(a[i]-'0'))+carry;
        carry=value/10;
        string temp=to_string(value%10);
        ans+=temp;

    }
    if(a.size()>length){
        for(int i=0;i<a.size();++i){
            ll value=(a[i]-'0')+carry;
            carry=value/10;
            string temp=to_string(value%10);
            ans+=temp;
        }
    }
    if(b.size()>length){
        for(int i=0;i<b.size();++i){
            ll value=(b[i]-'0')+carry;
            carry=value/10;
            string temp=to_string(value%10);
            ans+=temp;
        }
    }
    while(carry){
       
        
        string temp=to_string(carry%10);
        ans+=temp;
        carry=carry/10;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;

}

int main(){
string a,b;
cin>>a>>b;
addition(a,b);
}