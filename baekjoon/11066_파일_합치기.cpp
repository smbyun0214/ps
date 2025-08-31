#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 987654321;

int cacheMax[500][500];

int mergeBooks(int left, int right, const vector<int> &cost, const vector<int> &psum) {
    if (left == right)
        return 0;
    else if (left + 1 == right)
        return cost[left] + cost[right];
    
    int &ret = cacheMax[left][right];
    if (ret != -1)
        return ret;
    
    ret = INF;
    
    for (int mid = left; mid <= right; ++mid) {
        int leftCost = mergeBooks(left, mid, cost, psum);
        int rightCost = mergeBooks(mid + 1, right, cost, psum);
        
        ret = min(ret, leftCost + rightCost) ;
    }
    
    ret += psum[right + 1] - psum[left];
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T; cin >> T;
    
    while (T--) {
        memset(cacheMax, -1, sizeof(cacheMax));
        
        int N;
        cin >> N;
        
        vector<int> cost(N);
        vector<int> psum(N + 1, 0);
        
        for (int i = 1; i <= N; ++i) {
            cin >> cost[i - 1];
            psum[i] = psum[i - 1] + cost[i - 1];
        }
        
        cout << mergeBooks(0, N - 1, cost, psum) << '\n';
    }
    
    return 0;
}
