#include<bits/stdc++.h>
using namespace std;

int ncr[11][11];
int npr[11][11];
int fact[11];
void lucas(){
    ncr[0][0]=0;
    for(int i=1;i<=10;++i){
        for(int j=0;j<=10;++j){
            if(j>i) ncr[i][j]=0;
            else if(j==i||j==0) ncr[i][j]=1;
            else ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
        }
    }
}
void factorial(){
     fact[0]=1;
     for(int i=1;i<=10;++i){
        fact[i]=fact[i-1]*i;
     }

}
void findPermutation(){
 
    for(int i=1;i<=10;++i){
        for(int j=0;j<=10;++j){
            npr[i][j]=ncr[i][j]*fact[j];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lucas();
    factorial();
    findPermutation();
    int x,y;
    cin>>x>>y;
    cout<<x<<" P "<<y<<" :- ";
    cout<<ncr[x][y]<<"\n";
    cout<<npr[x][y]<<"\n";
    return 0;

}


