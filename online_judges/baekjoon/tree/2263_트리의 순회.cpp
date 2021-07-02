// https://www.acmicpc.net/problem/2263

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void printPreorder(vector<int>::iterator inFrom, vector<int>::iterator inTo, vector<int>::iterator postFrom, vector<int>::iterator postTo) {
    if (inFrom == inTo) {
        return;
    }

    int root = *prev(postTo);;
    int nextTo = find(inFrom, inTo, root) - inFrom;

    cout << root << ' ';
    printPreorder(inFrom, next(inFrom, nextTo), postFrom, next(postFrom, nextTo));
    printPreorder(next(inFrom, nextTo + 1), inTo, next(postFrom, nextTo), prev(postTo));
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> inorder(n);
    vector<int> postorder(n);

    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }

    printPreorder(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    
    return 0;
}
