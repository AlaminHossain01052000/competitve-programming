#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e6+10;
vector<bool> isPrime(N,true);
vector<int> tPrimes;
void seive(){
    isPrime[1]=false;
    isPrime[0]=false;
    isPrime[2]=true;
    tPrimes.push_back(2*2);
    for(int i=4;i<=N;i+=2){
        isPrime[i]=false;
    }
    for(int i=3;i<=N;i+=2){
        if(isPrime[i]){
            tPrimes.push_back(i*i);
            for(int j=i*i;j<=N;j+=2*i){
                isPrime[j]=false;
            }
        }
    }
}

signed main(){
    

    seive();
    
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i)cin>>v[i];
    for(int i=0;i<n;++i){
        int x=v[i];
        int low=0;
        int high=tPrimes.size()-1;
        while(high-low>1){
            int mid=(low+high)/2;
            if(tPrimes[mid]<=x){
                low=mid;
            }
            else{
                high=mid-1;
            }
        }
        if(tPrimes[high]==x||tPrimes[low]==x){
            cout<<"YES\n";
        }
        else cout<<"NO\n";

    }
}