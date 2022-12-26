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
//bubbleSort function will take an array as reference as an argument and sort that array
void bubbleSort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; ++i)
    {
        //isSwapped is used to detect whether any swapping is happened or not. If no swapping is happend then the array is sorted and we do not need any further iteration
        int isSwapped = 0;
        //in every iteration the n-1-i th index to n-1 th index will be sorted. So we do not need to iterate that portion again
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                isSwapped = 1;
            }
        }
        if (!isSwapped)
            break;
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

        bubbleSort(v);
        // BubbleSort(v,n);

        cout << "The array after sorting is : ";
        printArray(v);
    }
}