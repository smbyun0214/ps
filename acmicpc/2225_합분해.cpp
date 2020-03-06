#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000000;

int N, K;
int cache[201][201];

int disjointingSum(int step, int remainder) {
    if (remainder == 0) return 1;
    if (step == 0) return 0;
    
    int &ret = cache[step][remainder];
    if (ret != -1) return ret;
    
    ret = 0;
    for (int num = 0; num <= N; ++num) {
        ret = (ret + (disjointingSum(step - 1, remainder - num)) % MOD ) % MOD;
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N >> K;
    
    cout << disjointingSum(K, N) << '\n';
    
    return 0;
}
