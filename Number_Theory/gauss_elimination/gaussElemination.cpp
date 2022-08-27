#include<bits/stdc++.h>
using namespace std;
void convertAugmentedMatrixToUppedTriangularMatrix(vector<float> *a,int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(j>i){
                float ratio=a[j][i]/a[i][i];
                for(int k=0;k<n+1;k++){
                    a[j][k]=a[j][k]-(ratio*a[i][k]);
                }
            }
        }
    }
    

    
    
}
void applyBackSubtitution(vector<float>* a,vector<float> &ans,int n){
    ans[n-1]=a[n-1][n]/a[n-1][n-1];
    
    for(int i=n-2;i>=0;--i){
        float sum=0;
        for(int j=i+1;j<n;++j){
            sum+=a[i][j]*ans[j];   
            
        }
        ans[i]=(a[i][n]-sum)/a[i][i];
        
    }


}
int main(){
    cout<<"Enter the number of unknown variable\n";
    int n;
    cin>>n;
    vector<float> A[n+1],ans(n);
    cout<<"Enter the values of augmented matrix\n";

    for(int i=0;i<n;++i){
        for(int j=0;j<n+1;j++){
            printf("A[%d][%d] : ",i,j);
            float x;
            cin>>x;
            A[i].push_back(x);
        }
        cout<<endl;
    }
    convertAugmentedMatrixToUppedTriangularMatrix(A,n);
    applyBackSubtitution(A,ans,n);
    for(int i=0;i<n;++i){
        cout<<ans[i]<<" ";
    }

cout<<endl;
}




