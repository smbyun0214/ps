#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int V, E;

vector<int> adjacent[1001];

void dfs(int here, vector<bool> &visited, vector<int> &path) {
    visited[here] = true;
    path.push_back(here);
    
    for (int i = 0; i < adjacent[here].size(); ++i) {
        int there = adjacent[here][i];
        if (!visited[there])
            dfs(there, visited, path);
    }
}

void bfs(int start, vector<bool> &visited, vector<int> &path) {
    visited[start] = true;
    path.push_back(start);
    
    queue<int> q;
    q.push(start);
    
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        
        for (int i = 0; i < adjacent[here].size(); ++i) {
            int there = adjacent[here][i];
            if (!visited[there]) {
                q.push(there);
                
                visited[there] = true;
                path.push_back(there);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int S;
    cin >> V >> E >> S;
    
    int A, B;
    for (int i = 0; i < E; ++i) {
        cin >> A >> B;
        adjacent[A].push_back(B);
        adjacent[B].push_back(A);
    }
    
    for (int i = 1; i <= V; ++i) {
        sort(adjacent[i].begin(), adjacent[i].end());
    }
    
    vector<bool> dfsVisited(V + 1, false), bfsVisited(V + 1, false);
    vector<int> dfsPath, bfsPath;
    
    dfs(S, dfsVisited, dfsPath);
    bfs(S, bfsVisited, bfsPath);
    
    for (int i : dfsPath)
        cout << i << ' ';
    cout << '\n';
    for (int i : bfsPath)
        cout << i << ' ';
    cout << '\n';
    
    
    return 0;
}
