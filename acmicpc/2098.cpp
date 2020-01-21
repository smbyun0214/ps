#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int INF = 1987654321;

int n;

int dist[16][16];

int shortestPath(vector<int>& path, vector<bool>& visited, int currentLength) {
    if (path.size() == n) {
        if (dist[path.back()][path.front()])
            return currentLength + dist[path.back()][path.front()];
        
        return INF;
    }
    
    int ret = INF;
    
    for (int next = 0; next < n; ++next) {
        if (visited[next]) continue;
        
        int here = path.back();
        
        if (dist[here][next]) {
            path.push_back(next);
            visited[next] = true;
            
            int cand = shortestPath(path, visited, currentLength + dist[here][next]);
            ret = min(ret, cand);
            
            visited[next] = false;
            path.pop_back();
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(dist, 0, sizeof(dist));
    
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }
    
    vector<int> path;
    vector<bool> visited(n, false);
    
    path.push_back(0);
    visited[0] = true;
    cout << shortestPath(path, visited, 0) << '\n';
    
    return 0;
}
