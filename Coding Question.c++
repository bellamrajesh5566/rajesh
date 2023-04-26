#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int N = 52;

int n, r;
int x[N], y[N], q[N];
vector<pair<int, int>> adj[N];
int ans_q, ans_x, ans_y;

void dfs(int node, int cur_q, int cur_x, int cur_y, vector<bool>& vis) {
    vis[node] = true;
    if (cur_q > ans_q || (cur_q == ans_q && make_pair(cur_x, cur_y) < make_pair(ans_x, ans_y))) {
        ans_q = cur_q;
        ans_x = cur_x;
        ans_y = cur_y;
    }
    for (auto i : adj[node]) {
        int v = i.first, w = i.second;
        if (!vis[v]) {
            dfs(v, cur_q + w, cur_x + x[v], cur_y + y[v], vis);
        }
    }
}

int main() {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> q[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (d <= r * r) {
                int w1 = q[i] / (1 + sqrt(d));
                int w2 = q[j] / (1 + sqrt(d));
                adj[i].pb({j, w2});
                adj[j].pb({i, w1});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        vector<bool> vis(n + 1, false);
        dfs(i, q[i], x[i], y[i], vis);
    }
    cout << ans_x << " " << ans_y << endl;
    return 0;
}
