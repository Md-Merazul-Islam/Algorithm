#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    int t;
    cin >> t;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }
    while (!pq.empty())
    {
        pii ans =pq.top();
        pq.pop();
        cout<<ans.first << " "<< ans.second<<endl;

    }

    return 0;
}

// https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-03/challenges
