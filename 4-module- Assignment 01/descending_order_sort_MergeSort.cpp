#include <bits/stdc++.h>
using namespace std;


void merge(int a[], int l, int r, int mid)
{
    int left_size = mid - l + 1;
    int Left_arr[left_size + 1];


    int rigth_size = r - mid;
    int right_arr[rigth_size + 1];


    // for left array ----------->
    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        Left_arr[j] = a[i];
    }


    // for right array ---------------->
    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        right_arr[j] = a[i];
    }


    Left_arr[left_size] = INT_MIN;
    right_arr[rigth_size] = INT_MIN;


    int lp = 0, rp = 0;


    for (int i = l; i <= r; i++)
    {
        if (Left_arr[lp] >= right_arr[rp])
        {
            a[i] = Left_arr[lp];
            lp++;
        }
        else
        {
            a[i] = right_arr[rp];
            rp++;
        }
    }
}
void mergesort(int a[], int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;


    mergesort(a, l, mid);
    mergesort(a, mid + 1, r);
    merge(a, l, r, mid);
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


    mergesort(a, 0, n - 1);


    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
