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

void dijkstra(const int &start, const vector<vector<pair<int, long long> > > &list, vector<long long> &dist) {
    set <pair<long long, int>> unvisited; // { dist[v], v }
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
    vector<vector<pair<int, long long> > > list(NumOfStorage);

    for (size_t i = 0; i < m; ++i) {
        long long u, v, cost;
        cin >> u >> v >> cost;
        list[u - 1].push_back({v - 1, cost});
    }


    for (int i = 0; i < n; ++i) {
        vector<long long> dist(n, INF);
        dijkstra(i, list, dist);
        for (size_t i = 0; i < n; ++i) {
            cout << dist[i] << " ";
        }
        cout << endl;
    }
    return 0;
}