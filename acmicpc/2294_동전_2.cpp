#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int INF = 987654321;

int N, K;
int cache[10001];

int countCoin(int idx, int k, const vector<int> &prices) {
    if (k == 0)
        return 0;

    int &ret = cache[k];
    if (ret != -1)
        return ret;
    
    ret = INF;
    
    for (int add = 0; idx + add < prices.size(); ++add) {
        int next = idx + add;
        if (k - prices[next] >= 0)
            ret = min(ret, 1 + countCoin(next, k - prices[next], prices));
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N >> K;
    
    vector<int> prices(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }
    
    for (int k = 0; k <= K; ++k)
        countCoin(0, k, prices);
    
    cout << (cache[K] != INF ? cache[K] : -1) << '\n';
    
    return 0;
}
