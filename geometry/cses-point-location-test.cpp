// https://www.youtube.com/watch?v=Twcp9Vdq88Y&list=PL-Jc9J83PIiH0l9IZvdeC55dbFQpdMDSS
// https://cses.fi/problemset/task/2189
#include<bits/stdc++.h>
using namespace std;
// Slop is simply what is the angle a line creating against x-axis
// for a line p1-p2 the slop of the line is (y2-y1)/(x2-x1) where p1(x1,y1) and p2(x2,y2) are 2 points of the line
int main(){
    int t;
    cin>>t;
    while(t--){
        long long x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        long long p=(y2-y1)*(x3-x2);
        long long q=(y3-y2)*(x2-x1);
        if(p>q) cout<<"RIGHT\n";
        
        else if(p<q) cout<<"LEFT\n";
        else cout<<"TOUCH\n";
    }
}