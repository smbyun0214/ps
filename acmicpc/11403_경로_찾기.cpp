#include <iostream>
#include <cstring>

using namespace std;

int N;

bool visited[100];
int adjacent[100][100];

void dfs(int here) {
//    visited[here] = true;
    
    for (int there = 0; there < N; ++there) {
        if (!visited[there] && adjacent[here][there]) {
            visited[there] = true;
            dfs(there);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> adjacent[i][j];
        }
    }
    
    for (int here = 0; here < N; ++here) {
        memset(visited, false, sizeof(visited));
        dfs(here);
        
        for (int there = 0; there < N; ++there) {
            if (visited[there]) {
                adjacent[here][there] = 1;
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << adjacent[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
