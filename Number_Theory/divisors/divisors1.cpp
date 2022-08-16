#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const long long int N=1e6+10;
vector<ll> divisors[N];
vector<ll> sum(N,0);
int main(){
   //Complexity O(n logn)
    for(ll i=2;i<N;i++){
        //As 1 is divisors of all numbers
        divisors[i].push_back(1);
        sum[i]+=1;
        //for 2,4,6,8,... push 2 as one of their divisor
        for(ll j=i;j<N;j+=i){
            
            divisors[j].push_back(i);
            sum[j]+=i;
        }
        
    }
    ll n;
    n=24;
    cout<<n<<endl;
    cout<<"SUM of divisors ====> "<<sum[n]<<endl;
    cout<<"Count of divisors ====> "<<divisors[n].size()<<endl;
    cout<<"Divisors of "<<n<<" ===>"<<endl;
    for(auto vect:divisors[n]){
        cout<<vect<<" ";
    
    }
    cout<<endl;

}