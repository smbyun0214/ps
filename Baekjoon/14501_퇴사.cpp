#include <iostream>
#include <cstring>

using namespace std;

int N;
int times[16], prices[16];

int maxIncome(int lastFree, int currentPrice) {
    if (lastFree > N + 1)
        return 0;
    if (lastFree == N + 1)
        return currentPrice;
    
    int ret = currentPrice;
    
    for (int next = lastFree; next <= N; ++next) {
        int nextFree = next + times[next];
        
        ret = max(ret, maxIncome(nextFree, currentPrice + prices[next]));
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(times, 0, sizeof(times));
    memset(prices, 0, sizeof(prices));
    
    times[0] = 1;
    
    cin >> N;
    
    for (int i = 1; i <= N; ++i) {
        cin >> times[i] >> prices[i];
    }
    
    cout << maxIncome(0, 0) << '\n';
    
    return 0;
}
