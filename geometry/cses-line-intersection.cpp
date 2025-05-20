// https://www.youtube.com/watch?v=BiN7seIFLEM&list=PL-Jc9J83PIiH0l9IZvdeC55dbFQpdMDSS&index=2
// https://cses.fi/problemset/task/2190
#include <bits/stdc++.h>
using namespace std;
int orientation(long x1, long y1, long x2, long y2, long x3, long y3)
{
    long val = ((y2 - y1) * (x3 - x2)) - ((y3 - y2) * (x2 - x1));
    if (val > 0) return 2; //(x3,y3) is in the right position
    else if (val < 0) return 1; //(x3,y3) is in the left position
    else return 0;          //(x3,y3) lies in the same line
}
bool doesOnSegment(long x1, long y1, long x2, long y2, long x3, long y3 ){
    return (max(x1,x2)>=x3 && min(x1,x2)<=x3 && max(y1,y2)>=y3 && min(y1,y2)<=y3);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        int or1=orientation(x1,y1,x2,y2,x3,y3);
        int or2=orientation(x1,y1,x2,y2,x4,y4);
        int or3=orientation(x3,y3,x4,y4,x1,y1);
        int or4=orientation(x3,y3,x4,y4,x2,y2);
        if(or1!=or2 && or3!=or4) cout<<"YES\n";
        else if(or1==0&&doesOnSegment(x1,y1,x2,y2,x3,y3))cout<<"YES\n";
        else if(or2==0&&doesOnSegment(x1,y1,x2,y2,x4,y4))cout<<"YES\n";
        else if(or3==0&&doesOnSegment(x3,y3,x4,y4,x1,y1))cout<<"YES\n";
        else if(or4==0&&doesOnSegment(x3,y3,x4,y4,x2,y2))cout<<"YES\n";
        else cout<<"NO\n";
    }
}