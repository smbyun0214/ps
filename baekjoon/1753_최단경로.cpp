#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

int V, E;
vector<vector<pair<int, int>> > adjacent;

vector<int> dijkstra(int start) {
    vector<int> dist(V + 1, INF);
    dist[start] = 0;
    
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if (dist[here] < cost) continue;
        
        for (int i = 0; i < adjacent[here].size(); ++i) {
            int there = adjacent[here][i].second;
            int nextDist = cost + adjacent[here][i].first;
            
            if (nextDist < dist[there]) {
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
    adjacent.resize(V + 1);
    
    int start; cin >> start;
    
    int u, v, w;
    for (int i = 0; i < E; ++i) {
        cin >> u >> v >> w;
        adjacent[u].push_back(make_pair(w, v));
    }
    
    vector<int> dist = dijkstra(start);
    
    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
    
    return 0;
}
