#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getTreeHeight(const vector<int>& trees, int left, int right, int height) {
    if (left == right)
        return left;
    
    int mid = (left + right) / 2;
    
    if (trees[mid] > height)
        return getTreeHeight(trees, left, mid, height);
    else
        return getTreeHeight(trees, mid + 1, right, height);
}

long long getRemainder(const vector<int>& trees, int height) {
    int idx = getTreeHeight(trees, 0, trees.size() - 1, height);
    
    long long tmp = 0;
    for (int i = idx; i < trees.size(); ++i) {
        tmp += (long long)(trees[i] - height);
    }
    
    return tmp;
}

int maxHeight(const vector<int>& trees, int left, int right, long long wanted) {
    if (left == right) {
        if (getRemainder(trees, left) < wanted)
            return left - 1;
        
        return left;
    }
        
    
    int height = (left + right) / 2;
    
    if (getRemainder(trees, height) > wanted)
        return maxHeight(trees, height + 1, right, wanted);
    else
        return maxHeight(trees, left, height, wanted);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N; long long M;
    cin >> N >> M;
    
    vector<int> trees(N);
    
    for (int i = 0; i < N; ++i)
        cin >> trees[i];
    
    sort(trees.begin(), trees.end());
    
    cout << maxHeight(trees, 0, 1000000000, M) << '\n';
    
    return 0;
}
