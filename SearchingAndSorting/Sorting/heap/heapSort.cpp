#include<bits/stdc++.h>
using namespace std;
vector<int> ans;

//heapify take an array and an index as arguments and convert the array as a max heap
//The heap data structure is a binary tree where each node of each subtree is lesser(max heap) of greater(min heap) than the root node

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
//the heapSort algorithm swap the last or smallest element of a max heap with the root or gratest node and heapify the data structure after the again
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
            cout<<"The Array before Sorting is: ";
            for(int i=0;i<n;++i){
                cout<<v[i]<<" ";
            }
            cout<<endl;
            heapSort(v);
            cout<<"The Array After Sorting is: ";
            reverse(ans.begin(),ans.end());
            for(int i=0;i<ans.size();++i){
                cout<<ans[i]<<" ";
            }
            cout<<endl;

        }


}