// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1988
// https://www.youtube.com/watch?v=UBJICmkiAPs&list=PLoa_roVVsxA094Nb0xdyXmI0yTsj42zDz&index=16
#include<bits/stdc++.h>
using namespace std;
const int N=200;
const int INF=1e9;
int dist[N][N];
int nxt[N][N];
void reset(int n){
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j){
            if(i==j)dist[i][j]=0;
            else dist[i][j]=INF;
            nxt[i][j]=j;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    reset(n);
    vector<string> employeeNames(n);
    map<string,int> emp_id;
    // map<string,int> emp_id;
    for(int i=0;i<n;++i){
        cin>>employeeNames[i];
        emp_id[employeeNames[i]]=i;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int x;
            cin>>x;
            if(x==-1)dist[i][j]=INF;
            else dist[i][j]=x;
        }
    }
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    nxt[i][j]=nxt[i][k];
                }
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        string employeeNo,employee1,employee2;
        cin>>employeeNo>>employee1>>employee2;
        int src=emp_id[employee1];
        int dst=emp_id[employee2];
        if(dist[src][dst]==INF){
            cout<<"Sorry Mr "<<employeeNo<<" you can not go from "<<employee1<<" to "<<employee2<<endl;
            continue;
        }
        cout<<"Mr "<<employeeNo<<" to go from "<<employee1<<" to "<<employee2<<", you will receive "<<dist[src][dst]<<" euros"<<endl;
        vector<int> path;
        path.push_back(src);
        int cur=src;
        while(cur!=dst){
            cur=nxt[cur][dst];
            path.push_back(cur);
        }
        if(path.size()==1)path.push_back(path[0]);
        cout<<"Path:"<<employeeNames[path[0]];
        for(int i=1;i<path.size();++i){
            cout<<" "<<employeeNames[path[i]];
        }
        cout<<endl;

    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
/*
Input:
2
6
Ofi1 Ofi2 Ofi3 ofi4 ofi5 ofi6
0 4 1 -1 4 -1
4 0 -1 2 3 4
1 -1 0 -1 3 -1
-1 2 -1 0 -1 1
4 3 3 -1 0 2
-1 4 -1 1 2 0
1
emp1 Ofi1 ofi4
3
Murcia Alicante Albacete
0 3 -1
-1 0 4
-1 -1 0
2
Dofyl Murcia Albacete
Dofyl Albacete Murcia

Output:
Mr emp1 to go from Ofi1 to ofi4, you will receive 6 euros
Path:Ofi1 Ofi2 ofi4
Mr Dofyl to go from Murcia to Albacete, you will receive 7 euros
Path:Murcia Alicante Albacete
Sorry Mr Dofyl you can not go from Albacete to Murcia
*/