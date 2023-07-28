#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N = 1e8 + 10;
vector<ll> isPrime(N, 1);
ll highestPrime[N];
ll lowestPrime[N];

void seive()
{
    isPrime[0] = isPrime[1] = 0;

    for (ll i = 2; i < N; ++i)
    {
        if (isPrime[i])
        {
            lowestPrime[i] = highestPrime[i] = i;
            for (ll j = 2 * i; j < N; j += i)
            {
                isPrime[j] = 0;
                highestPrime[j] = i;
                if (lowestPrime[j] == 0)
                {
                    lowestPrime[j] = i;
                }
            }
        }
    }
}
map<ll,ll> primeFactorsFunction(ll n){
        //If count of prime factors is needed then use map
        //If distince prime factors is needed then use vector
        map<ll,ll> primeFactors;
        vector<ll> distinctPrimeFactors;
        
        while(n>1){
            //Determine prime factor using highest prime
            ll hp=highestPrime[n];

            //If n is divisible by hp then hp is a primefactor of n
            while(n%hp==0){
            //Count the number of distinct prime factors
                primeFactors[hp]++;
                n/=hp;
            }
            distinctPrimeFactors.push_back(hp);
            //Divide n untill it become 0
            
        }

        return primeFactors;

        // For 36
        // Outer loop 1:
        //     hp=3
        //         Inner Loop 1:
        //             n=12
        //         Inner Loop 2:
        //             n=4
        // Outer loop 2:
        //     hp=2
        //         Inner Loop 1:
        //             n=2
        //         Inner Loop 2:
        //             n=1
                


    
}
int main(){
    cout<<"Hello\n";
 seive();

 auto prmFctrs=primeFactorsFunction(100);

 for(auto pair:prmFctrs){
    cout<<pair.first<<" "<<pair.second<<endl;
    
 }
}