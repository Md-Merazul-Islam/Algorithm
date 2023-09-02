#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<pair<int, int>> plan;
int day = 0;

void dfs(int node, int parent) {
    vector<int> children;

    for (int child : graph[node]) {
        if (child != parent) {
            children.push_back(child);
        }
    }

    if (children.empty()) {
        return;
    }

    if (children.size() == 1) {
        dfs(children[0], node);
        return;
    }

    for (int i = 0; i < children.size() - 1; i++) {
        day++;
        plan.push_back({children[i], children[i + 1]});
        dfs(children[i], node);
    }

    dfs(children.back(), node);
}

int main() {
    int n;
    cin >> n;

    graph.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    cout << day << endl;
    for (pair<int, int> p : plan) {
        cout << p.first << " " << p.second << " " << p.first << " " << p.second << endl;
    }

    return 0;
}
