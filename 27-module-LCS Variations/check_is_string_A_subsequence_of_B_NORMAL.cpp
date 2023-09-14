//O(n+m)

#include <bits/stdc++.h>

using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = a.size();

    // NORMAL
    bool ans = false;
    int i = 0;
    for (char c : b)
    {
        if (c == a[i])
        {
            i++;
        }
        if (i == a.size())
        {
            ans = true;
            break;
        }
    }

    if (ans)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}