#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

int V, E;
vector<int> adjacent[20001];

vector<int> dijkstra(int start) {
    vector<int> dist(V + 1, INF);
    vector<bool> visited(V + 1, false);
    
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if (dist[here] < cost) continue;
        
        visited[here] = true;
        
        for (int i = 0; i < adjacent[here].size(); ++i) {
            int nextDist = cost + 1;
            int there = adjacent[here][i];
            
            if (nextDist < dist[there] && !visited[there]) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    
    return dist;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> V >> E;
    
    int u, v;
    for (int i = 0; i < E; ++i) {
        cin >> u >> v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
    
    vector<int> dist = dijkstra(1);
    
    int maxDist = 0;
    vector<int> ret;
    
    for (int i = 1; i <= V; ++i) {
        if (dist[i] != INF) {
            if (maxDist < dist[i]) {
                ret.clear();
                maxDist = dist[i];
            }
            
            if (maxDist == dist[i]) ret.push_back(i);
        }
    }
    
    cout << ret.front() << ' ' << maxDist << ' ' << ret.size() << '\n';
    
    return 0;
}
