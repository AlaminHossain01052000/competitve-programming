#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin>>x;
    vector<string> v;
    while(x!=-1){
        if(x==0){
            v.clear();
            int size;
            cin>>size;
            for(int i=0;i<size;++i){
                string name;cin>>name;
                v.push_back(name);
            }
        }
        else if(x==1){
            string name;
            cin>>name;
            v.push_back(name);
        }
        else if(x==2){
            int position;
            cin>>position;
            if(position<=v.size()){
                v.erase(v.begin()+(position-1));
            }
        }
        else if(x==3){
            reverse(v.begin(),v.end());
        }
        else if(x==4){
            int position,numberOfFrnds;
            cin>>position>>numberOfFrnds;
            auto it=v.begin()+(position-1);
            v.erase(it,it+numberOfFrnds);
        }
        else if(x==5){
            int position;
            string name;
           
            cin>>position;
             cin>>name;
            auto it=v.begin()+(position-1);
            v.insert(it,name);
        }
        else if(x==6){
            string name1,name2;
            cin>>name1>>name2;
            v.push_back(name1);
            v.push_back(name2);
        }
        else if(x==7){
            string nick,pet;
            cin>>nick>>pet;
            for(int i=0;i<v.size();++i){
                if(v[i]==nick){
                    v[i]=pet;
                    break;
                }
            }
        }
        else if(x==8){
            int pos1,pos2;
            cin>>pos1>>pos2;
            if(pos1>=1&&pos1<=v.size()&&pos2>=1&&pos2<=v.size())
                swap(v[pos1-1],v[pos2-1]);
        }
        else if(x==9){
            v.clear();
        }
        else if(x==10){
            int newSize;
            cin>>newSize;
            v.resize(newSize);
        }
        else if(x==11){
            v.pop_back();
        }
        cout<<x<<". ";
        for(int i=0;i<v.size();++i){
            cout<<v[i]<<" ";
        }cout<<endl;
        cin>>x;
    }
}