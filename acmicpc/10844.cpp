#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000000;

int N;
long long cache[101][10];

void easyStairStep(int digit) {
    if (digit <= 0)
        return;

    for (int i = 0; i < 10; ++i) {
        long long &ret = cache[digit][i];
        
        if (i == 0)
            ret = ret + cache[digit - 1][i + 1];
        else if (i == 9)
            ret = ret + cache[digit - 1][i - 1];
        else
            ret = ret + cache[digit - 1][i - 1] + cache[digit - 1][i + 1];
        
        ret %= MOD;
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    memset(cache, 0, sizeof(cache));
    
    for (int i = 1; i < 10; ++i)
        cache[1][i] = 1;
    
    cin >> N;

    for (int i = 2; i <= N; ++i) {
        easyStairStep(i);
    }
    
    long long ret = 0;
    
    for (int i = 0; i < 10; ++i) {
        ret += cache[N][i];
    }
    
    cout << ret % MOD << '\n';

    return 0;
}
