#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 87654321;

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
    
    cin >> V >> E;
    
    adjacent.resize(V + 1);
    
    int u, v, weight;
    
    for (int i = 0; i < E; ++i) {
        cin >> u >> v >> weight;
        adjacent[u].push_back(make_pair(weight, v));
        adjacent[v].push_back(make_pair(weight, u));
    }
    
    int betA, betB;
    
    cin >> betA >> betB;
    
    vector<int> distStart = dijkstra(1);
    vector<int> distBetA = dijkstra(betA);
    vector<int> distBetB = dijkstra(betB);
    
//    (Start -> BetA - BetB -> End) vs. (Start -> BetB - BetA -> End)
    int ret = min(distStart[betA] + distBetA[betB] + distBetB[V], distStart[betB] + distBetB[betA] + distBetA[V]);
    
    cout << (ret >= INF ? -1 : ret) << '\n';
    
    return 0;
}
