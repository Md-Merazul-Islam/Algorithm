#include <bits/stdc++.h>
using namespace std;
void merge(int arr1[],  int arr2[], int n, int m, int ans[])
{


    int x = 0, y = 0, k = 0;
    while (x < n && y < m)
    {
        if (arr1[x] > arr2[y])
        {
            ans[k++] = arr1[x++];
        }
        else
        {
            ans[k++] = arr2[y++];
        }
    }
    while (x < n)
    {
        ans[k++] = arr1[x++];
    }


    while (y < m)
    {
        ans[k++] = arr2[y++];
    }
}


int main()
{


    int n1;
    cin >> n1;
    int arr1[n1];
   
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }


    int n2;
    cin >> n2;
    int arr2[n2];
   
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }


    int ans[n1 + n2];
 


    merge(arr1, arr2, n1, n2, ans);


    for(int i=0; i<n1+n2;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}