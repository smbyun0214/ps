#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int INF = 1987654321;

int n;

int dist[16][16];
int cache[65536][16];

int shortestPath(int here, int visited) {
    if (visited == ((1 << n) - 1)) {
        if (dist[here][0])
            return dist[here][0];
        
        return INF;
    }
    
    int &ret = cache[visited][here];
    if (ret != -1)
        return ret;

    ret = INF;

    for (int next = 0; next < n; ++next) {
        if (visited & (1 << next) || dist[here][next] == 0)
            continue;
        
        ret = min(ret, dist[here][next] + shortestPath(next, visited | (1 << next)));
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(dist, 0, sizeof(dist));
    memset(cache, -1, sizeof(cache));
    
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }
    
    cout << shortestPath(0, 1 << 0) << '\n';
    
    return 0;
}
