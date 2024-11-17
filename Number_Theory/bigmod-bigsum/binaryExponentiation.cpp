#include<bits/stdc++.h>
using namespace std;
const int m=1e9+7;
// calculate a^b
long long binExpo(long long a, long long b) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}


int main(){
cout<<binExpo(12,13)<<endl;


}
