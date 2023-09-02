// #include <bits/stdc++.h>

// using namespace std;

// class Edge
// {
// public:
//     int a, b, w;
//     Edge(int a, int b, int w)
//     {
//         this->a = a;
//         this->b = b;
//         this->w = w;
//     }
// };

// bool cmp(Edge a, Edge b)
// {
//     return (a.w < b.w);
// }

// const int N = 1e5+3;
// long long parent[N];
// long long parentSize[N];

// void dsu_set(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         parent[i] = -1;
//         parentSize[i] = 1;
//     }
// }

// int dsu_find(int node)
// {

//     while (parent[node] != -1)
//     {
//         node = parent[node];
//     }
//     return node;
// }

// void dsu_union(int a, int b)
// {
//     int leaderA = dsu_find(a);
//     int leaderB = dsu_find(b);
//     if (leaderA != leaderB)
//     {
//         if (parentSize[leaderA] > parentSize[leaderB])
//         {
//             parent[leaderB] = leaderA;
//             parentSize[leaderA] += parentSize[leaderB];
//         }
//         else
//         {
//             parent[leaderA] = leaderB;
//             parentSize[leaderB] += parentSize[leaderA];
//         }
//     }
// }

// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     dsu_set(n);
//     vector<Edge> v;
//     vector<Edge> ans;

//     while (e--)
//     {
//         int a, b;
//         long long w;
//         cin >> a >> b >> w;
//         v.push_back(Edge(a, b, w));
//     }
//     sort(v.begin(), v.end(), cmp);
//     for (Edge val : v)
//     {
//         int a = val.a;
//         int b = val.b;
//         long long w = val.w;

//         int leaderA = dsu_find(a);
//         int leaderB = dsu_find(b);

//         if (leaderA == leaderB)
//             continue;
//         ans.push_back(val);
//         dsu_union(a, b);
//     }

//     int cost = 0;
//     for (auto val : ans)
//     {
//         cost += (long long )val.w;
//     }
//     if (ans.size() == n - 1)
//     {

//         cout << cost << endl;
//     }
//     else
//     {
//         cout << -1 << endl;
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b, w;
    Edge(int a, int b, int w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b) {
    return (a.w < b.w);
}

const int N = 100005; 
int parent[N];
int parentSize[N];

void dsu_set(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

int dsu_find(int node) {
    while (parent[node] != -1) {
        node = parent[node];
    }
    return node;
}

void dsu_union(int a, int b) {
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB) {
        if (parentSize[leaderA] > parentSize[leaderB]) {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        } else {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    dsu_set(n);
    vector<Edge> v;
    vector<Edge> ans;

    while (e--) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }

    sort(v.begin(), v.end(), cmp);

    for (Edge val : v) {
        int a = val.a;
        int b = val.b;
        long long w = val.w;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA == leaderB)
            continue;
        ans.push_back(val);
        dsu_union(a, b);
    }

    int cost = 0;
    for (auto val : ans) {
        cost += val.w;
    }

    if (ans.size() == n - 1) {
        cout << cost << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
