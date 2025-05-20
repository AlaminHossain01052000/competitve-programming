#include<bits/stdc++.h>
using namespace std;
//modular arithmetic starts here
const long long int MOD=1e9+7;
inline void normal(long long &a) { a %= MOD; (a < 0) && (a += MOD); }
inline long long modMul(long long a, long long b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline long long modAdd(long long a, long long b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline long long modSub(long long a, long long b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline long long modPow(long long b, long long p) { long long r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline long long modInverse(long long a) { return modPow(a, MOD-2); }
inline long long modDiv(long long a, long long b) { return modMul(a, modInverse(b)); }
//modular arithmetic ends here
int main(){
  
    
}