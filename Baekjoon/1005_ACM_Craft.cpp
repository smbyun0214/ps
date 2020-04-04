#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Solution 1
/*
vector<bool> visited;
vector<int> times;
vector<priority_queue<pair<int, int> > > adjacent;

void dfs(int start, int parent, vector<pair<int, int>> &path) {
    visited[start] = true;
    
    while (!adjacent[start].empty()) {
        int next = adjacent[start].top().second;
        adjacent[start].pop();
        
        dfs(next, start, path);
    }
    
    path.push_back(make_pair(parent, start));
}

vector<int> bfs(const vector<pair<int, int>> &path) {
    vector<int> cost(visited.size(), 0);

    queue<pair<int, int>> q;
    for (pair<int, int> p : path)
        q.push(p);
    
    while (!q.empty()) {
        int parent = q.front().first;
        int here = q.front().second;
        q.pop();
        
        cost[here] = max(cost[here], cost[parent] + times[here]);
    }

    return cost;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T; cin >> T;
    
    int V, E;
    while (T--) {
        cin >> V >> E;
        
        visited = vector<bool>(V + 1, false);
        times = vector<int>(V + 1, 0);
        adjacent = vector<priority_queue<pair<int, int> > >(V + 1);
        
        for (int i = 1; i <= V; ++i)
            cin >> times[i];
        
        int u, v;
        for (int i = 0; i < E; ++i) {
            cin >> u >> v;
            adjacent[v].push(make_pair(times[u], u));
        }
        
        int end; cin >> end;
        vector<pair<int, int>> path;
        dfs(end, end, path);
        
        reverse(path.begin(), path.end());
        
        vector<int> cost = bfs(path);
        
        int ret = 0;
        
        for (int i : cost) {
            ret = max(ret, i);
        }
        
        cout << ret << '\n';
    }
    
    return 0;
}
*/

// Solution 2

vector<int> indegree;
vector<int> times;
vector<vector<int> > adjacent;

int V, E;

vector<int> bfs(queue<int> &q) {
    vector<int> visited(V + 1, false);
    vector<int> cost(V + 1, 0);
    
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        
        visited[here] = true;
        
        if (cost[here] == 0) cost[here] = times[here];
        
        for (int i = 0; i < adjacent[here].size(); ++i) {
            int next = adjacent[here][i];
            
            if (cost[next] < cost[here] + times[next]) {
                cost[next] = max(cost[next], cost[here] + times[next]);
                q.push(next);
            }
        }
    }
    
    return cost;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T; cin >> T;
    
    while (T--) {
        cin >> V >> E;
        
        times = vector<int>(V + 1, 0);
        indegree = vector<int>(V + 1, 0);
        adjacent = vector<vector<int> >(V + 1);
        
        for (int i = 1; i <= V; ++i)
            cin >> times[i];
        
        int u, v;
        for (int i = 0; i < E; ++i) {
            cin >> u >> v;
            adjacent[u].push_back(v);
            ++indegree[v];
        }
        
        int end; cin >> end;
        vector<pair<int, int>> path;
        
        queue<int> candidate;
        for (int i = 1; i <= V; ++i)
            if (indegree[i] == 0)
                candidate.push(i);
        
        vector<int> cost = bfs(candidate);
        
        cout << cost[end] << '\n';
    }
    
    return 0;
}
