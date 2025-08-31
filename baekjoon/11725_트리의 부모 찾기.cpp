// https://www.acmicpc.net/problem/11725

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N;

struct Node {
    int key;
    vector<Node*> adj;

    Node(int _key) : key(_key) { }
};

bool isUsed[100001];
Node* cache[100001];

map<int, int> nodes;     // (자식, 부모)

void makeTree(int root) {
    for (Node* node : cache[root]->adj) {
        if (!isUsed[node->key]) {
            isUsed[node->key] = true;
            nodes.insert(make_pair(node->key, root));
            makeTree(node->key);
        }
    }
}

int main (int argc, char *argv[]) {
    cin >> N;

    int u, v;
    for (int i = 0; i < N; ++i) {
        cin >> u >> v;
        if (cache[u] == NULL) cache[u] = new Node(u);
        if (cache[v] == NULL) cache[v] = new Node(v);
        cache[u]->adj.push_back(cache[v]);
        cache[v]->adj.push_back(cache[u]);
    }

    makeTree(1);

    for (int i = 2; i <= N; ++i) {
        cout << nodes[i] << '\n';
    }
    
    return 0;
}
