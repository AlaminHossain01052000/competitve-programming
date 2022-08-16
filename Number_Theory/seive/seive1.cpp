#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const long long int N=1e8+10;
vector<long long int> primeNumbersContainer;// Contain all the prime numbers and it's size tell us the total number of prime's between 1 to N
vector<long long int> isPrime(N,1);//Suppose isPrime[3]=1 and isPrime[12]=0 as 3 is prime and 12 is non-prime


//Easy
//Time Complexity-O(root(n))
bool seive1(ll n){
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
//Medium
//Time Complexity-O(n log(log n))
//More Preferreble
void seive2(){
    isPrime[0]=isPrime[1]=0;
    for(ll i=2;i<=N;++i){
        if(isPrime[i]){
            primeNumbersContainer.push_back(i);
            for(ll j=2*i;j<=N;j+=i){
                isPrime[j]=0;
            }
        }
    }
}

//Difficult
void seive3(){
    //As there are no prime divisors exist which is grater then root(n)

    ll limit=sqrt(1*N)+1;//To avoid preicision 1*N is used

    primeNumbersContainer.push_back(2);//As 2 is a Prime Number
    isPrime[0]=isPrime[1]=0;// O and 1 are not prime number so mark them as looser
    isPrime[2]=1;// Marking 2 as a winner or prime number
    //Disqualify all the even numbers except 2

    for(ll i=4;i<=N;i+=2)isPrime[i]=0;

    //Iterates over odd numbers only as evens are not prime
    for(ll i=3;i<=N;i+=2){
        //Check whether i is prime or not
        if(isPrime[i]){
            //As i is prime so putting i in primeNumbersContainer Vector
            primeNumbersContainer.push_back(i);

            //Check whether i is in limit or not. Since, all the non prime numbers greater then limit must be disqualified by previous primes
            if(i<=limit){

                //J is starting from i*i as numbers less then i*i has a prime divisor less than i
                //j is increasing by 2*i as it only iterating through the odd multiples of i
                for(ll j=i*i;j<=N;j+=2*i){
                    //Marking all multiples of i as non prime
                    isPrime[j]=0;
                }
            }
            
        }
    }



}
int main(){
seive2();


//Print n is prime or not
ll n=100;
cout<<isPrime[100]<<endl;

//Print Prime Numbers between 1 to n

for(ll i=0;i<primeNumbersContainer.size();++i){
    if(primeNumbersContainer[i]>n){
        break;
    }
    cout<<primeNumbersContainer[i]<<" ";

}
cout<<endl;
//How many Prime Numbers are between a to b

ll a=200;
ll b=300;
ll count=0;
for(ll i=0;i<primeNumbersContainer.size();++i){
    if(primeNumbersContainer[i]>b){
        break;
    }
    if(primeNumbersContainer[i]>=a){
        cout<<primeNumbersContainer[i]<<" ";
        count++;
    }

}
cout<<endl;
cout<<count<<endl;

}