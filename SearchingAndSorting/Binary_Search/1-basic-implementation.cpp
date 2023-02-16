#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        int to_find;
        cin >> to_find;
        // binary search
        int lo = 0;
        int hi = n - 1;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            if (v[mid] < to_find)
            {
                lo = mid + 1;
            }
            else
            {
                // v[mid]==to_find || v[mid]>to_find
                hi = mid;
            }
        }
        
        if (v[lo] == to_find){
            cout<<"Element is found at index : ";
            cout << lo << endl;
        }
            
        else if (v[hi] == to_find){
            cout<<"Element is found at index : ";
            cout << hi << endl;
        }
        else
            cout << "Element is not found\n";
    }
}
// 3
// 9
// 2 4 6 8 10 12 14 16 18
// 8
// 3
// 9
// 2 4 6 8 10 12 14 16 18
// 14
// 6
// 9
// 2 4 6 8 10 12 14 16 18
// 20
// Element is not found