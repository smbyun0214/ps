// https://www.acmicpc.net/problem/15900

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N;

bool isUsed[500001];
vector<int> adj[500001];

int sumOfHeights = 0;

void traversal(int parent, int height) {
    isUsed[parent] = true;
    
    bool isLeaf = true;
    for (int i = 0; i < adj[parent].size(); ++i) {
        int child = adj[parent][i];
        if (!isUsed[child]) {
            isLeaf = false;
            traversal(child, 1 + height);
        }
    }

    if (isLeaf) sumOfHeights += height;
}

int main (int argc, char *argv[]) {
    
    cin >> N;

    int u, v;
    for (int i = 0; i < N; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    traversal(1, 0);

    cout << (sumOfHeights % 2 ? "Yes" : "No") ;
    
    return 0;
}
