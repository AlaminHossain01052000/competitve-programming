//How many zero after n!???

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int M=1e8+7;
long long int factorial[N];

void factCal(){
    factorial[0]=1;
    factorial[1]=1;
    for(long long i=2;i<N;++i){
        factorial[i]=(i*factorial[i-1])%M;
    }

}
signed main(){
    factCal();
    while(1){
        int n;
        cin>>n;
        long long int ans=0;
        long long int p=5;
        long long int power=1;
        //(n/p)+(n/p^2)+(n/p^3)+....while(p^x<=n)
        long long int q=pow(p,power);
        while(q<=n){

            ans+=n/q;
            power++;
            q=pow(q,power);

        }
        cout<<factorial[n]<<endl;
        cout<<ans<<endl;
    }
}