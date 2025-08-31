// https://www.acmicpc.net/problem/1660

#include <iostream>
#include <cstring>

using namespace std;

const int INF = 987654321;

int bullet[130];
int bullet2[130];

int cache[300001];

int solve(int n) {
    if (n == 0) return 0;
    
    int& ret = cache[n];
    if (ret != -1) return ret;
    
    ret = INF;
    
    for (int step = 1; bullet2[step] <= n; ++step) {
        ret = min(ret, 1 + solve(n - bullet2[step]));
    }
    
    return ret;
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    for (int i = 1; i < 130; ++i) {
        bullet[i] = bullet[i - 1] + i;
        bullet2[i] = bullet2[i - 1] + bullet[i];
    }
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        solve(i);
    }

    cout << solve(n);
    
    return 0;
}
