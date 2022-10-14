#include<bits/stdc++.h>
using namespace std;

//Complexity=O(numberOfDigits*(n+range));
//It is a combination of count sort
//We can not sort an array greater then 1e9 using count sort but radix sort overcome this obstacle
void countSort(vector<int> &v,int base){
    int n=v.size();
    //As digits are from 0 to 9 so 10th size count array is perfect
    vector<int> count(10,0);
    //v[i]/base%10 return the 1st,2nd or 3rd index
    //if v[i]=634 then the 1st digit is(base=1) (634/1)%10=4(1st digit)
    //if v[i]=634 then the 2nd digit is(base=10) (634/10)%10=63%10=3(2nd digit)
    //if v[i]=634 then the 3rd digit is(base=100) (634/100)%10=6%10=6(3rd digit)

    //Store the count of the digits in count array
    for(int i=0;i<n;++i){
        count[(v[i]/base)%10]++;
    }

    //Calculate prefix some of count array
    for(int i=1;i<10;++i){
        count[i]+=count[i-1];
    }
    vector<int> output(n);
    //Input the value of v[i] in appropiate position of output[i] using count[i]
    for(int i=n-1;i>=0;--i){
        output[--count[(v[i]/base)%10]]=v[i];
    }
    v=output;
}
void redixSort(vector<int> &v){
    int maxElement=*max_element(v.begin(),v.end());

    for(int base=1;maxElement/base>0;base*=10){
        countSort(v,base);
    }
}
void printVector(vector<int> &v){
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> v={97,57,208,699,125,734};
    int n=v.size();
    cout<<"Before Sorting : ";
    printVector(v);

    redixSort(v);
    cout<<"After Sorting : ";
    printVector(v);
}