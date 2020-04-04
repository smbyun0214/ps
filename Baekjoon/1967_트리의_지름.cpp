#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int cache[10001];

struct TreeNode {
    int idx, weight;
    
    vector<TreeNode*> childeren;
    
    TreeNode (int idx, int weight) : idx(idx), weight(weight) {}
};

int maxDiameter(const TreeNode *node) {
    if (node == NULL)
        return 0;
    
    if (node->childeren.empty())
        return node->weight;
    
    vector<int> weights;
    
    for (TreeNode *subNode : node->childeren) {
        weights.push_back(maxDiameter(subNode));
    }
    
    sort(weights.begin(), weights.end(), greater<int>());
    
    int &ret = cache[node->idx];
    
    if (weights.size() > 1)
        ret = weights[0] + weights[1];
    else
        ret = weights[0];
    
  return node->weight + weights[0];
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    int N; cin >> N;
    
    TreeNode *rootNode = NULL;
    queue<TreeNode*> waiting;
    
    int parentIdx, childIdx, weight;
    
    for (int i = 1; i < N; ++i) {
        cin >> parentIdx >> childIdx >> weight;
        
        if (rootNode == NULL) {
            rootNode = new TreeNode(parentIdx, 0);
            waiting.push(rootNode);
        }
        
        while (waiting.front()->idx != parentIdx)
            waiting.pop();
        
        TreeNode *node = waiting.front();
        TreeNode *child = new TreeNode(childIdx, weight);
        
        node->childeren.push_back(child);
        waiting.push(child);
    }
    
    maxDiameter(rootNode);
    
    int ret = 0;
    
    for (int i = 1; i <= N; ++i)
        ret = max(ret, cache[i]);
    
    cout << ret << '\n';
    
    return 0;
}
