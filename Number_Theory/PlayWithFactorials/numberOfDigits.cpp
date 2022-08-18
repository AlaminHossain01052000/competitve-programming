//Total How Many Digits in n!

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define out(n) cout<<n<<endl
#define in(n) cin>>n
const ll M=1e6+7;
const ll N=1e8+10;
vector<ll> factorials(N);

void factor(){
    factorials[0]=1;
    factorials[1]=1;
    for(ll i=2;i<N;++i){
        factorials[i]=(i*factorials[i-1])%M;
    }

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    in(n);
    double result =0;
    for(ll i=1;i<=n;++i){
        result+=log10(i);
        
    }
    
    out(floor(result)+1);

}