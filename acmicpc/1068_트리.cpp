#include <iostream>
#include <list>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node {
    Node* parent;
    list<Node*> children;
    
    Node() {
        parent = NULL;
    }
    
    void insert(Node* node) {
        node->parent = this;
        
        list<Node*>::iterator it = find(children.begin(), children.end(), node);
        
        if (it == children.end())
            children.push_back(node);
    }
};

void removeNode(Node* a, Node* b) {
    list<Node*>::iterator it = find(a->children.begin(), a->children.end(), b);
    
    if (it != a->children.end()) {
        a->children.erase(it);
    }
}

int countLeaf(Node* root) {
    if (root->children.empty())
        return 1;
    
    int ret = 0;
    
    for (Node *child : root->children) {
        ret += countLeaf(child);
    }
    
    return ret;
}

Node* cache[50];

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, NULL, sizeof(cache));
    
    int N, parentIdx, removeIdx;
    cin >> N;
    
    for (int i = 0; i < N; ++i) cache[i] = new Node();
    
    list<Node*> roots;
    
    for (int i = 0; i < N; ++i) {
        cin >> parentIdx;
        
        if (parentIdx == -1) {
            roots.push_back(cache[i]);
        }
        else {
            cache[parentIdx]->insert(cache[i]);
        }
    }
    
    cin >> removeIdx;
    
    if (cache[removeIdx]->parent == NULL) {
        cout << 0 << '\n';
        return 0;
    }
    
    removeNode(cache[removeIdx]->parent, cache[removeIdx]);
    
    int ret = 0;

    for (Node* root : roots)
        ret += countLeaf(root);
    
    cout << ret << '\n';
    
    return 0;
}

