#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include <climits>

const long long INF = LLONG_MAX;
const int NumOfStorage = 20;

using namespace std;

void dijkstra(const int &start, const vector<vector<pair<int, long long> > > &list, vector<long long> &dist,
              vector<int> &prev) {
    set<pair<long long, int>> unvisited; // { dist[v], v }
    int u = start;
    dist[u] = 0;
    unvisited.insert({0, u});
    while (!unvisited.empty()) {
        long long u = unvisited.begin()->second;
        unvisited.erase(unvisited.begin());
        for (auto &e : list[u]) {
            long long v = e.first, w = e.second;
            if (dist[u] + w < dist[v]) {
                unvisited.erase({dist[v], v});
                dist[v] = dist[u] + w;
                prev[v] = u;
                unvisited.insert({dist[v], v});
            }
        }
    }
}

int main() {
    //freopen("pathbgep.in", "r", stdin);
    //freopen("pathbgep.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long> > > list(n);

    for (size_t i = 0; i < m; ++i) {
        long long u, v, cost;
        cin >> u >> v >> cost;
        list[u - 1].push_back({v - 1, cost});
        list[v - 1].push_back({u - 1, cost});
    }


    for (int i = 0; i < n; ++i) {
        vector<long long> dist(n, INF);
        vector<int> prev(n, -1);
        dijkstra(i, list, dist, prev);
        for (size_t j = 0; j < n; ++j) {
            cout << dist[j] << " ";
            vector<int> path;
            int y = j;
            while (y != -1) {
                path.push_back(y);
                y = prev[y];
            }
            reverse(path.begin(), path.end());
            for (int k = 0; k != path.size(); ++k) {
                cout << path[k] + 1;
                if (k != path.size() - 1) {
                    cout << "->";
                }
            }
            cout << endl;
        }

        cout << endl;
    }
    return 0;
}