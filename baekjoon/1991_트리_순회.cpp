#include <iostream>

using namespace std;

struct TreeNode {
    char c;
    TreeNode *parent;
    TreeNode *left, *right;
    
    TreeNode(char c) : c(c) {
        left = NULL;
        right = NULL;
    }
};

TreeNode* search(const char c, TreeNode *node) {
    if (node == NULL)
        return NULL;
    
    if (node->c == c)
        return node;
    
    TreeNode *left = search(c, node->left);
    if (left) return left;
    
    TreeNode *right = search(c, node->right);
    if (right) return right;
        
    return NULL;
}

void printPreOrder(const TreeNode *root) {
    if (root == NULL)
        return;
    
    cout << root->c;
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(const TreeNode *root) {
    if (root == NULL)
        return;
    
    printInOrder(root->left);
    cout << root->c;
    printInOrder(root->right);
}

void printPostOrder(const TreeNode *root) {
    if (root == NULL)
        return;
    
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->c;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N; cin >> N;
    
    TreeNode* rootNode = NULL;
    
    char root, left, right;
    
    for (int i = 0; i < N; ++i) {
        cin >> root >> left >> right;
        
        if (rootNode == NULL) rootNode = new TreeNode(root);
        
        TreeNode *node = search(root, rootNode);

        if (left != '.') node->left = new TreeNode(left);
        if (right != '.') node->right = new TreeNode(right);
    }
    
    printPreOrder(rootNode); cout << '\n';
    printInOrder(rootNode); cout << '\n';
    printPostOrder(rootNode); cout << '\n';
    
    return 0;
}
