#include <iostream>
#include <queue>

using namespace std;

bool inRange(int pos) {
    return 0 <= pos && pos <= 100000;
}

int hideAndSeek(int older, const int younger) {
    vector<int> dist(100001, -1);
    dist[older] = 0;
    
    queue<int> q;
    q.push(older);
    
    while (!q.empty()) {
        int older = q.front();
        q.pop();
        
        if (older == younger)
            return dist[older] + 1;
        
        if (inRange(older + 1) && dist[older + 1] == -1) {
            dist[older + 1] = dist[older] + 1;
            q.push(older + 1);
        }
        
        if (inRange(older - 1) && dist[older - 1] == -1) {
            dist[older - 1] = dist[older] + 1;
            q.push(older - 1);
        }
        
        if (inRange(2 * older) && dist[2 * older] == -1) {
            dist[2 * older] = dist[older] + 1;
            q.push(2 * older);
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int older, younger;
    cin >> older >> younger;
    
    cout << hideAndSeek(older, younger) - 1 << '\n';
    
    return 0;
}
