#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
void heapify(vector<int> &v,int i){
    int n=v.size();
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n&&v[left]>v[largest]){
        largest=left;
    }
    if(right<n&&v[right]>v[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(v[i],v[largest]);
        heapify(v,largest);
    }

}

void heapSort(vector<int> &v){
   int size=v.size();
   while(size>0){
    
    swap(v[size-1],v[0]);
    ans.push_back(v[size-1]);
    v.pop_back();
    heapify(v,0);
    size=v.size();
   }
    


}

int main(){
        int t;
        cout<<"Enter Number of testcase : ";
        cin>>t;
        while(t--){
            int n;
            cout<<"Enter number of elements : ";
            cin>>n;
            vector<int> v(n);
            cout<<"Enter some space separated integer as element of the array"<<endl;

            for(int i=0;i<n;++i){
                cin>>v[i];
            }
            for(int i=n/2-1;i>=0;--i){
                heapify(v,i);
            }
            for(int i=0;i<n;++i){
                cout<<v[i]<<" ";
            }
            cout<<endl;
            heapSort(v);
            for(int i=0;i<ans.size();++i){
                cout<<ans[i]<<" ";
            }
            cout<<endl;

        }


}