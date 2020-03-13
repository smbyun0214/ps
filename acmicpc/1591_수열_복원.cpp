#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<vector<int>, vector<vector<int>>> adjacent;
map<vector<int>, int> indegree, outdegree;
map<pair<vector<int>, vector<int>>, int> used;

void eulerPath(const vector<int> &here, vector<vector<int>> &path) {
    vector<vector<int>> adj = adjacent[here];
    for (int i = 0; i < adj.size(); ++i) {
        vector<int> next = adjacent[here][i];
        pair<vector<int>, vector<int>> p = make_pair(here, next);
        
        if (used[p] > 0) {
            --used[p];
            eulerPath(next, path);
        }
    }
    
    path.push_back(here);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> vertex;
    
    for (int i = 0; i < N - M + 1; ++i) {
        vertex = vector<int>(M);
        
        for (int j = 0; j < M; ++j)
            cin >> vertex[j];
        
        vector<int> u(vertex.begin(), vertex.end() - 1);
        vector<int> v(vertex.begin() + 1, vertex.end());
        
        adjacent[u].push_back(v);
        
        if (!outdegree.count(u)) outdegree[u] = 0;
        if (!outdegree.count(v)) outdegree[v] = 0;
        
        if (!indegree.count(u)) indegree[u] = 0;
        if (!indegree.count(v)) indegree[v] = 0;
        
        ++outdegree[u];
        ++indegree[v];
        
        pair<vector<int>, vector<int>> p = make_pair(u, v);
        if (!used.count(p)) used[p] = 0;
        ++used[p];
    }
    
    vector<vector<int>> path;
    
    map<vector<int>, int>::iterator it = indegree.begin();
    
    while (it != indegree.end()) {
        if (outdegree[it->first] == indegree[it->first] + 1) {
            eulerPath(it->first, path);
            break;
        }
        
        ++it;
    }
    
    if (path.empty())
        eulerPath(indegree.begin()->first, path);
    
    reverse(path.begin(), path.end());
    
    for (int i = 0; i < path.size() - 1; ++i)
        cout << path[i][0] << ' ';
    for (int i = 0; i < path[path.size() - 1].size(); ++i)
        cout << path[path.size() - 1][i] << ' ';
    cout << '\n';
    
    return 0;
}
