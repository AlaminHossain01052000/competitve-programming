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
void multiplication(string a, string b) {
    int n = a.size();
    int m = b.size();
    vector<int> result(n + m, 0); // Result array to store intermediate results
    
    // Reverse the strings to multiply from least significant digits
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    // Perform multiplication digit by digit
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int prod = (a[i] - '0') * (b[j] - '0');
            result[i + j] += prod;
            result[i + j + 1] += result[i + j] / 10; // Handle carry
            result[i + j] %= 10;
        }
    }

    // Remove leading zeros from the result
    while (result.size() > 1 && result.back() == 0)
        result.pop_back();

    // Convert result array to a string
    string ans;
    for (int i = result.size() - 1; i >= 0; --i) {
        ans += (result[i] + '0');
    }

    cout << ans << endl;
}
int main(){
string a,b;
cin>>a>>b;
addition(a,b);
multiplication(a,b);
}