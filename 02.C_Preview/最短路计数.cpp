#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MOD = 100003;

int main() {
    int n, m;
    cin >> n >> m;

 
    vector<vector<int> > adj;
    adj.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> dist(n + 1, -1);
    vector<int> cnt(n + 1, 0);
    dist[1] = 0;
    cnt[1] = 1;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

       
        for (vector<int>::size_type j = 0; j < adj[u].size(); ++j) {
            int v = adj[u][j];
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                cnt[v] = cnt[u];
                q.push(v);
            } else if (dist[v] == dist[u] + 1) {
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << endl;
    }

    return 0;
}



