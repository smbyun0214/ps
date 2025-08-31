// https://www.acmicpc.net/problem/17212

#include <iostream>
#include <cstring>

using namespace std;

const int INF = 987654321;

int coins[4] = {1, 2, 5, 7};
int cache[100001];

int solve(int n) {
    if (n == 0) return 0;
    
    int& ret = cache[n];
    if (ret != -1) return ret;
    
    ret = INF;
    
    for (int i = 0; i < 4; ++i) {
        if (0 <= n - coins[i]) {
            ret = min(ret, 1 + solve(n - coins[i]));
        }
    }
    
    return ret;
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    int n;
    cin >> n;
    
    cout << solve(n);
    
    return 0;
}
