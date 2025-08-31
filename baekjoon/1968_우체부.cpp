#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int degree[1001];
int adj[1001][1001];
priority_queue<pair<int, int>> pAdj[1001];

int V, E;

void eularPath(int here, vector<int> &path) {
    while (!pAdj[here].empty()) {
        int there = pAdj[here].top().second;
        pAdj[here].pop();
        
        if (adj[here][there] > 0) {
            --adj[here][there];
            --adj[there][here];
            eularPath(there, path);
        }
    }
    
    path.push_back(here);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(adj, 0, sizeof(adj));
    
    cin >> V >> E;
    
    int u, v, w, here = -1, maxWeight = 0;
    
    for (int i = 0; i < E; ++i) {
        cin >> u >> v >> w;
        
        pAdj[u].push(make_pair(w, v));
        pAdj[v].push(make_pair(w, u));
        
        ++adj[u][v];
        ++adj[v][u];
        
        ++degree[u];
        ++degree[v];
        
        if (maxWeight < w) {
            here = u;
            w = maxWeight;
        }
    }
    
    vector<int> path;
    
    int odd = -1, oddMaxWeight = 0;
    for (int i = 1; i <= V; ++i) {
        if ((degree[i] % 2) == 1 && oddMaxWeight < pAdj[i].top().first) {
            odd = i;
            oddMaxWeight = pAdj[i].top().first;
        }
    }
    
    if (odd != -1)
        eularPath(odd, path);
    else
        eularPath(here, path);
    
    reverse(path.begin(), path.end());
    
    for (int i : path)
        cout << i << '\n';
    cout << -1 << '\n';
    
    return 0;
}
