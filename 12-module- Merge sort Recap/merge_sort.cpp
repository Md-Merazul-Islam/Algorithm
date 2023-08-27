#include <bits/stdc++.h>

using namespace std;

void merge(int a[], int l, int mid, int r)
{
    int left_size = mid - l + 1;
    int right_size = r - mid;

    int left_arr[left_size];
    int right_arr[right_size];

    int k = 0;
    for (int i = l; i <= mid; i++)
    {
        left_arr[k] = a[i];
        k++;

    }
    k = 0;

    for (int i = mid+1; i <= r; i++)
    {
        right_arr[k] = a[i];
        k++;

    }

    int i = 0, j = 0, cur = l;
    while (i < left_size && i < right_size)
    {
        if (left_arr[i] <= right_arr[j])
        {
            a[cur] = left_arr[i];
            i++;
        }
        else
        {
            a[cur] = right_arr[j];
            j++;
        }
        cur++;
    }

    while (i < left_size)
    {
        a[cur] = left_arr[i];
        cur++;
        i++;
    }
    while (j < right_size)
    {
        a[cur] = right_arr[j];
        cur++;
        j++;
    }
}

void merge_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (r + l) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid+1, r);
        merge(a,l,mid,r);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    merge_sort(a, 0, n - 1);

    for (int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}