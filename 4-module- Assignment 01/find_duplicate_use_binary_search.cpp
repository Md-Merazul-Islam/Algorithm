#include <bits/stdc++.h>
using namespace std;


int find_num(const vector<int> &v, int k)
{
    int l = 0;
    int r = v.size() - 1;
    int count; // index count korar jonno


    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (v[mid] == k)
        {
            count = mid;
            r = mid - 1;
        }
        else if (v[mid] < k)
        {
            l = mid + 1;
        }
        else
        {


            r = mid - 1;
        }
    }
    return count;
}


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


    int ans = find_num(v, k);
    // cout<<ans<<endl;


    if (v[ans + 1] == k)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }


    return 0;
}
