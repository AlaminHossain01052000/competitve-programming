// https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
#include<bits/stdc++.h>
using namespace std;
//here k is the window size
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define endl '\n'
int search(string pat, string txt) {
    int k=pat.size();
    int n=txt.size();
	    // code here
    vector<int>v1(26,0);
    for(int i=0;i<k;++i)v1[pat[i]-'a']++;
    int j=0;
    int ans=0;
    vector<int> cnt(26,0);
    for(int i=0;i+k-1<n;++i){
        
        while(j-i+1<=k){
            cnt[txt[j]-'a']++;
            j++;
        }
        bool pos=1;
        for(int l=0;l<=25;++l){
            if(cnt[l]==0&&v1[l]==0)continue;
            else if(cnt[l]!=v1[l]){
                pos=false;
                break;
            }
        }
        if(pos)ans++;
        cnt[txt[i]-'a']--;

    }
    return ans;
}
int main(){
    fast
    int t=1;
    // cin>>t;
    cout<<search("aaba","aabaabaa");
   
}