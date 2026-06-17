// #include <bits/stdc++.h>
// using namespace std;
// const int INF = 1e9;

// int main() {
//     int N, E, T, M;
//     cin >> N >> E >> T >> M;
//     vector<vector<pair<int, int>>> adj(N + 1); // 1-based
//     for (int i = 0; i < M; ++i) {
//         int a, b, w;
//         cin >> a >> b >> w;
//         adj[b].push_back({a, w}); // reverse edge
//     }

//     vector<int> dist(N + 1, INF);
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
//     dist[E] = 0;
//     pq.push({0, E});

//     while (!pq.empty()) {
//         auto [d, u] = pq.top(); pq.pop();
//         if (d > dist[u]) continue;
//         for (auto [v, w] : adj[u]) {
//             if (dist[v] > dist[u] + w) {
//                 dist[v] = dist[u] + w;
//                 pq.push({dist[v], v});
//             }
//         }
//     }

//     int ans = 0;
//     for (int i = 1; i <= N; ++i) {
//         if (dist[i] <= T) ans++;
//     }
//     cout << ans << endl;
//     return 0;
    
// }



#include <bits/stdc++.h>
using namespace std;
#define long long int;
const int INF = 1e9;
    int n, m, k;
vector<vector<pair<int, int>>> adj;


vector<vector<int>> dijitra() {
    vector<vector<int>> dist(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (dist[u].size() >= k) continue;
        dist[u].push_back(cost);
        for (auto [v, w] : adj[u]) {
            if (dist[v].size() < k) {
                pq.push({cost + w, v});
            }
        }
    }
    return dist;
}

int32_t main() {

    cin >> n >> m >> k;
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b; int c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<vector<int>> dist = dijitra();

    sort(dist[n].begin(), dist[n].end());

    for (int i = 0; i < k; ++i) {
        cout << dist[n][i] << " ";
    }
    cout << endl;
    return 0;
}