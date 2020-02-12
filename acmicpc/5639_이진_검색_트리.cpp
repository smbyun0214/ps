#include <iostream>

using namespace std;

struct TreeNode {
    int idx;
    TreeNode *left, *right;
    
    TreeNode (int idx) : idx(idx) {
        left = right = NULL;
    }
};

void createTree(TreeNode *root, const int n) {
    if (root->idx < n) {
        if (root->right == NULL)
            root->right = new TreeNode(n);
        else
            createTree(root->right, n);
    }
    else {
        if (root->left == NULL)
            root->left = new TreeNode(n);
        else
            createTree(root->left, n);
    }
}

void printPostOrder(TreeNode *root) {
    if (root == NULL)
        return;
    
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->idx << '\n';
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n; TreeNode *root = NULL;
    
    while (cin >> n) {
        if (root == NULL)
            root = new TreeNode(n);
        else
            createTree(root, n);
    }
    
    printPostOrder(root);
    
    return 0;
}
