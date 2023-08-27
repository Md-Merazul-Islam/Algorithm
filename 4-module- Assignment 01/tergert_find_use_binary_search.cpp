#include <bits/stdc++.h>


using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int k;
    cin >> k;


    int l = 0;
    int r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (v[mid] == k)
        {
            cout << mid << endl;
            break;
        }
        else if (v[mid] < k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid-1;
        }
    }
    if (l > r)
    {
        cout << "Not Found" << endl;
    }


    return 0;
}
