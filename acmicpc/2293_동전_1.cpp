#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, K;

long long cache[10001];

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, 0, sizeof(cache));
    cache[0] = 1;
    
    cin >> N >> K;
    
    vector<int> coins(N);
    
    for (int i = 0; i < N; ++i) cin >> coins[i];
    
    for (int value : coins) {
        for (int k = 1; k <= K; ++k)
            if (k >= value) {
                cache[k] += cache[k - value];
            }
    }
    
    cout << cache[K] << '\n';
    
    return 0;
}
