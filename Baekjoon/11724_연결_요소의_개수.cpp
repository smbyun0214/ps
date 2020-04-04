#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, E;
vector<int> adjacent[1000];
bool visited[1000];

void dfs(int here) {
    visited[here] = true;
    for (int i = 0; i < adjacent[here].size(); ++i) {
        int there = adjacent[here][i];
        if (!visited[there]) {
            dfs(there);
        }
    }
}
int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(visited, false, sizeof(visited));
    
    cin >> N >> E;
    
    int A, B;
    for (int i = 0; i < E; ++i) {
        cin >> A >> B;
        adjacent[A - 1].push_back(B - 1);
        adjacent[B - 1].push_back(A - 1);
    }
    
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(i);
            ++ret;
        }
    }
    
    cout << ret << '\n';
    
    return 0;
}
