// if n=(p1 ^ a1)*(p2 ^ a2)...

//NOD = Number Of Divisors=(a1+1)*(a2+1)
//SOD = Sum Of Divisors(p^(i+1)-1)/p-1

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int> isPrime(N,1);
int hp[N];
int lp[N];

// To count highest Prime
void seive(){
    for(int i=2;i<N;++i){
        if(isPrime[i]){
            hp[i]=lp[i]=i;
            for(int j=2*i;j<N;j+=i){
                isPrime[j]=0;
                hp[j]=i;
            }
        }
    }
}

map<int,int> primeFactorsCalc(int &n){
    map<int,int> m;
    while(n>1){
        int h=hp[n];
        while(n%h==0){
            m[h]++;
            n/=h;
        }
    }
    
    return m;
}

int binaryExpo(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=ans*a;
        }
        a=a*a;
        b=b>>1;
    }
    return ans;
}
int main(){
    
    seive();
    
        int n;
        cin>>n;
        auto m=primeFactorsCalc(n);
        // Check the power of embarsand n
        // cout<<n<<endl;

        // Number of divisor
        int ans=1;
        for(auto pair:m){
            ans*=pair.second+1;
        }
        cout<<ans<<endl;
        // Sum of divisor
        long long int result=1;
        for(auto pair:m){
            int p=(binaryExpo(pair.first,pair.second+1)-1)/(pair.first-1);
            
            result*=p;
        }
        cout<<result<<endl;

    
    
//12=(2^2)*(3^1)=(2^0+2^1+2^2)*(3^0+3^1)
}
