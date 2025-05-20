// Problem Link: https://neetcode.io/problems/maximum-product-subarray
// Solution Youtube Video:https://www.youtube.com/watch?v=lXVy6YWFcRM

// given an array = [1,2,-1,4,5,-6,-7,-3];
// find the maximum sub array product of the array. Ans= 4*5*-6*-7 = 840
// Intituion: for each i track maximum subarray product till i-1 and minimum subarray production till i-1
// multiply arr[i]*max and arr[i]*min and update max and min till i. arr[i]*max may be the answer among all arr[i]*max where 0<=i<n
// if all elements are positive then [1,2,3,5] = 1*2*3*5=30
// but odd number of negative occurs problem. So we need dp approach. It is not a traditional dp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i)cin>>v[i];
    int res = *max_element(v.begin(),v.end()); //array may be [-1,-2,-3] or [-1,0] or[0,0,0] or[1,2,3] or [1,2,-1,3,-4,-5] etc
    int curMax = 1; //anything * 1 = anything
    int curMin = 1;
    for(int i=0;i<n;++i){
        if(v[i] == 0){
            //element may be 0 in the array. 0*anything = 0 will ruin our algorithm
            curMin = 1;
            curMax = 1;
            continue;//start a new life :)

        }
        int temp = curMax;
        curMax = max({curMax * v[i],curMin*v[i],v[i]}); // if v[i] > 0 then curMax*v[i]>0, if v[i]<0 and curMin<0 then curMin*v[i]>0 (-2*-3 = +6) for [-1,8] case and i = 1 or v[i]=8 we need to compare v[i]
        curMin = min({temp*v[i],curMin*v[i],v[i]});

        res = max(res,curMax);

    }
    cout<<res<<endl;
}
