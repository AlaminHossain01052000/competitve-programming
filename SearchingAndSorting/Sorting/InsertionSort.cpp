#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Print the array in O(n) complexity
void printArray(vector<int> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Time complexity is O(n),O(n^2),O(n^2)
void insertionSort(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n;++i){
        int value=v[i];
        int hole=i;
        while(hole>0&&v[hole-1]>value){
            v[hole]=v[hole-1];

            hole--;

        }
        v[hole]=value;
    }

}
int main()
{
    int t;
    cout << "Enter Number of Testcases : ";
    cin >> t;
    while (t--)
    {
        int n;
        cout << "Enter Number of Elements of the array : ";
        cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; ++i)
        {
            cout << "Enter " << i + 1 << " no element of the array : ";
            cin >> v[i];
        }

        cout << "The array before sorting is : ";
        printArray(v);

        insertionSort(v);
        // BubbleSort(v,n);

        cout << "The array after sorting is : ";
        printArray(v);
    }
}