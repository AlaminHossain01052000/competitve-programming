// Given a string you need to print the size of the longest possible substring that has exactly K unique characters.If s="aabacbebebe" and k=3 then answer=7 and the answer string is "cbebebe" which has K unique character 'c','b','e'
// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
#include <bits/stdc++.h>
using namespace std;
int cnt(unordered_map<int, int> &mp)
{
    return mp.size();
}
int longestKUniqueSubstr(string &s, int k)
{
    // your code here
    int n = s.length();

    int ans = 0;
    unordered_map<int, int> mp;
    int i = 0;
    int j = 0;
    while (i < n && j < n)
    {
        mp[s[j] - 'a']++;
        int cntmp = cnt(mp);
        if (cntmp == k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (cntmp < k)
            j++;
        else
        {
            while (i < n && cntmp > k)
            {
                mp[s[i] - 'a']--;
                if (mp[s[i] - 'a'] == 0)
                    mp.erase(s[i] - 'a');
                i++;
                cntmp = cnt(mp);
            }
            cntmp = cnt(mp);
            if (cntmp == k)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
            else if (cntmp < k)
                j++;
        }
    }
    return ans;
}
int main()
{
    string s="aabacbebebe";
    int k=3;
    cout<<longestKUniqueSubstr(s,k)<<"\n";
}