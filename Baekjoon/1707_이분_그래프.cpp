#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;

vector<int> visited, bipartite;
vector<vector<int> > adjacent;

bool bipartiteGraph(int start) {
    visited[start] = true;
    bipartite[start] = 1;
    
    queue<int> q;
    q.push(start);
    
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        
        for (int i = 0; i < adjacent[here].size(); ++i) {
            int there = adjacent[here][i];
            if (!visited[there]) {
                visited[there] = true;
                bipartite[there] = -bipartite[here];
                q.push(there);
            }
            else if (bipartite[here] == bipartite[there])
                return false;
        }
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T; cin >> T;
    
    int A, B;
    while (T--) {
        cin >> V >> E;
        
        adjacent.clear();
        visited.clear();
        bipartite.clear();
        
        adjacent.resize(V + 1);
        visited.resize(V + 1);
        bipartite.resize(V + 1);
        
        for (int i = 0; i < E; ++i) {
            cin >> A >> B;
            adjacent[A].push_back(B);
            adjacent[B].push_back(A);
        }
        
        bool ret = true;
        for (int i = 1; i <= V; ++i) {
            if (!visited[i])
                ret &= bipartiteGraph(i);
        }
        
        cout << (ret ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
