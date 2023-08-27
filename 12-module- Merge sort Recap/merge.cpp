#include <bits/stdc++.h>

using namespace std;


void merge(int arr[], int l, int m, int r )
{
    int left_array_size = m-l +1;
    int right_array_size = r-m;

    int left_array[left_array_size];
    int right_array[right_array_size];

    int k =0; 
    for (int i =l; i<=m; i++)
    {
        left_array[k]=arr[i];
        k++;
    }
    k=0;
    for(int i=m+1; i<=r; i++)
    {
        right_array[k]= arr[i];
        k++;
    }

    int i=0,j=0,cur=l;
    while(i< left_array_size && j< right_array_size)
    {
        if(left_array[i]<= right_array[j])
        {
            arr[cur] = left_array[i];
            i++;
            cur++;
        }
        else
        {
            arr[cur] = right_array[j];
            j++;
            cur++;
        }
    }

    while(i<left_array_size)
    {
        arr[cur] = left_array[i];
        cur++;
        i++;
    }
    while(j<right_array_size)
    {
        arr[cur]= right_array[j];
        cur++;
        j++;
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    merge(arr, 0, 3, n-1);

    for (int i=0; i<n ;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}