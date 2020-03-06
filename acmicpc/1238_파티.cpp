#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

const int INF = 987654321;

int V, E, X;
vector<vector<pair<int, int>> > adjIn, adjOut;

vector<int> dijkstra(int start, const vector<vector<pair<int, int>> > &adjacent) {
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
            int nextDist = cost + adjacent[here][i].first;
            int there = adjacent[here][i].second;
            
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
    
    cin >> V >> E >> X;
    
    adjIn.resize(V + 1);
    adjOut.resize(V + 1);
    
    int u, v, weight;
    for (int i = 0; i < E; ++i) {
        cin >> u >> v >> weight;
        adjIn[u].push_back(make_pair(weight, v));
        adjOut[v].push_back(make_pair(weight, u));
    }
    
    vector<int> distIn = dijkstra(X, adjIn);
    vector<int> distOut = dijkstra(X, adjOut);
    
    int ret = 0;
    
    for (int i = 1; i <= V; ++i) {
        ret = max(ret, distIn[i] + distOut[i]);
    }
    
    cout << ret << '\n';
    
    return 0;
}
