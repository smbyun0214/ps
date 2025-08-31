#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// range : [)
void printPostOrder(const pair<int, int>& preRange, const pair<int, int>& inRange, const vector<int> &preorder, const vector<int> &inorder) {
    if (preRange.first == preRange.second)
        return;
    
    int root = preorder[preRange.first];
    int step = find(inorder.begin(), inorder.end(), root) - inorder.begin() - inRange.first;
    
    printPostOrder(make_pair(preRange.first + 1, preRange.first + 1 + step), make_pair(inRange.first, inRange.first + step), preorder, inorder);
    printPostOrder(make_pair(preRange.first + 1 + step, preRange.second), make_pair(inRange.first + 1 + step, inRange.second), preorder, inorder);
    cout << root << ' ';
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T; cin >> T;
    
    int N;
    vector<int> preorder, inorder;
    
    while (T--) {
        cin >> N;
        
        preorder = inorder = vector<int>(N);
        
        for (int i = 0; i < N; ++i) cin >> preorder[i];
        for (int i = 0; i < N; ++i) cin >> inorder[i];
        
        printPostOrder(make_pair(0, N), make_pair(0, N), preorder, inorder);
        cout << '\n';
    }
    
    return 0;
}
