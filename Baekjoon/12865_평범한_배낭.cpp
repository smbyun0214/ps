#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int cache[101][100001];

int bagPacking(int idx, const vector<pair<int, int>> &goods, int capacity) {
    int &ret = cache[idx][capacity];
    
    if (ret != -1)
        return ret;
    
    ret = 0;
    
    for (int start = idx; start < goods.size(); ++start) {
        ret = max(ret, bagPacking(start, goods, capacity));
        
        if (goods[start].second <= capacity)
            ret = max(ret, (-goods[start].first) + bagPacking(start + 1, goods, capacity - goods[start].second));
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    int N, K;
    cin >> N >> K;
    
    vector<pair<int, int>> goods(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> goods[i].second >> goods[i].first;
        goods[i].first *= -1;
    }
    
    sort(goods.begin(), goods.end());
    
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        ret = max(ret, bagPacking(i, goods, K));
    }
    
    cout << ret << '\n';
    
    return 0;
}
