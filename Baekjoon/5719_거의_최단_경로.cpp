//https://www.acmicpc.net/problem/5719

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int start, finish;

vector<vector<pair<int, int>> > adj;

void dijkstra(int start, vector<int> &dist, vector<int> &parent) {
    parent[start] = start;
    dist[start] = 0;
    
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if (here == -1 || dist[here] < cost) continue;
        
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].second;
            int nextDist = cost+ adj[here][i].first;
            
            if (nextDist < dist[there]) {
                parent[there] = here;
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
}

void dfs(int here, int cost, int minCost, vector<bool> &used, vector<int> &path, vector<vector<int> > &result) {
    if (minCost < cost) return;
    
    if (here == finish) {
        if (cost == minCost)
            result.push_back(path);
        return;
    }
    
    for (int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i].second;
        int thereDist = cost + adj[here][i].first;
        
        if (!used[there]) {
            used[there] = true;
            path.push_back(there);
            dfs(there, thereDist, minCost, used, path, result);
            path.pop_back();
            used[there] = false;
        }
    }
}

vector<int> shortestPath(int v, const vector<int> &parent) {
    vector<int> path(1, v);
    
    while (parent[v] != v) {
        v = parent[v];
        path.push_back(v);
    }
    
    reverse(path.begin(), path.end());
    
    return path;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int V, E;
    int u, v, weight;
    
    while (true) {
        cin >> V >> E;
        
        if (V == 0 && E == 0) break;
        
        cin >> start >> finish;
        
        adj.clear();
        adj.resize(V);
        
        for (int i = 0; i < E; ++i) {
            cin >> u >> v >> weight;
            adj[u].push_back(make_pair(weight, v));
        }
        
        vector<int> dist(V, INF);
        vector<int> parent(V, -1);
        
        dijkstra(start, dist, parent);
        
        int minCost = dist[finish];
        
        vector<bool> used(V, false);
        vector<int> path(1, start);
        vector<vector<int> > result;
        
        dfs(start, 0, minCost, used, path, result);
        
        for (int i = 0; i < result.size(); ++i) {
            vector<int> &path = result[i];
            
            for (int j = 1; j < path.size(); ++j) {
                int u = path[j - 1], v = path[j];
                
                for (int k = 0; k < adj[u].size(); ++k) {
                    if (adj[u][k].second == v)
                        adj[u][k].second = -1;
                }
            }
        }
        
        dist = vector<int>(V, INF);
        parent = vector<int>(V, -1);
        
        dijkstra(start, dist, parent);
        
        if (parent[finish] == -1)
            cout << -1 << '\n';
        else
            cout << dist[finish] << '\n';
    }
    
    return 0;
}
