#include <bits/stdc++.h>
using namespace std;

bool com(pair<int,int> a,pair<int,int> b){
    if(a.first!=b.first){
        return a.first<b.first;
    }
    return a.second>b.second;
}
int main()
{
    // *******************************************************************************
    int n=8;
    vector<pair<int, int>> v={{2,3},{11,65},{23,43},{2,9},{1,15},{2,1},{9,0},{12,45}};
    cout<<"Before Sorting of pairs"<<endl;
    for(int i=0;i<n;++i){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    cout<<endl;
    //If a have a pair of some points(x,y) and need to sort the points in acsending order of x and descending order of y then i can use my own compare function.
    //If I return something false then compare funtion will swap the elements else don't
    sort(v.begin(),v.end(),com);

    cout<<"After Sorting of pairs"<<endl;
    for(int i=0;i<n;++i){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    cout<<endl;



    // *******************************************************************************
    vector<long long int> myV={12,65,3,-110,11,999999999991112,3,54,119,-12345691011};

    //Sorting a function in descending order
    cout<<"Before Sorting of Elements : ";
    for(int i=0;i<myV.size();++i){
        cout<<myV[i]<<" ";
    }
    cout<<endl;
    sort(myV.begin(),myV.end(),greater<long long int>());
    cout<<"After Sorting of Elements : ";
    for(int i=0;i<myV.size();++i){
        cout<<myV[i]<<" ";
    }
    cout<<endl;
    // *******************************************************************************
    vector<string> strings={"alamin","john","boltu","noltu","jahn","naltu"};
    cout<<"Before Sorting of Strings : ";
    for(auto str:strings){
        cout<<str<<" ";
    }
    cout<<endl;
    sort(strings.begin(),strings.end());
    for(auto str:strings){
        cout<<str<<" ";
    }
    cout<<endl;
}