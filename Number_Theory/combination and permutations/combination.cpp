#include<bits/stdc++.h>
using namespace std;
#define in(n) cin>>n
#define out(n) cout<<n<<"\n"
#define ll long long int
#define flus ios_base::sync_with_stdio(false)
#define tie cin.tie(NULL)
#define sint signed int
int ncr[11][11];

void lucas(){
    ncr[0][0]=0;
    for(int i=1;i<=10;++i){
        for(int j=0;j<=10;++j){
            if(j>i) ncr[i][j]=0;
            else if(j==i || j==0) ncr[i][j]=1;
            else ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
        }
    }


}
signed main(){
    flus;
    tie;
    lucas();
    
        int p,q;
        cin>>p>>q;
        
        cout<<p<<" C "<<q<<" ==> ";
        cout<<ncr[p][q];
    
    
return 0;

}