#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool visited[101];
int cache[101], cost[101];
vector<int> adjacent[101];

int V, E;

void bfs(int start) {
    int ret = 0;
    
    visited[start] = true;
    
    queue<int> q;
    q.push(start);
    
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        
        for (int i = 0; i < adjacent[here].size(); ++i) {
            int there = adjacent[here][i];
            
            if (!visited[there]) {
                visited[there] = true;
                cache[there] = cache[here] + 1;
                ret += cache[there];
                q.push(there);
            }
        }
    }
    
    cost[start] = ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> V >> E;
    
    int A, B;
    for (int i = 0; i < E; ++i) {
        cin >> A >> B;
        adjacent[A].push_back(B);
        adjacent[B].push_back(A);
    }
    
    for (int i = 1; i <= V; ++i) {
        if (adjacent[i].size()) {
            memset(visited, false, sizeof(visited));
            memset(cache, 0, sizeof(cache));
            
            bfs(i);
        }
    }
    
    int ret = V, costMin = V * V;
    
    for (int i = V; 0 < i; --i) {
        if (cost[i] <= costMin) {
            costMin = cost[i];
            ret = i;
        }
    }
    
    cout << ret << '\n';
    
    return 0;
}
