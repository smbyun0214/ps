// https://www.acmicpc.net/problem/11867

#include <iostream>
#include <cstring>

using namespace std;

int cache[101][101];

int isWin(int n, int m) {
    if (n == 1 && m == 1) return -1;
    
    int& ret = cache[n][m];
    if (ret != 0) return ret;
    
    ret = -1;
    for (int i = 1; i < n; ++i) {
        ret = max(ret, -isWin(i, n - i));
    }
    for (int j = 1; j < m; ++j) {
        ret = max(ret, -isWin(j, m - j));
    }
    
    return ret;
}

int main (int argc, char *argv[]) {
    memset(cache, 0, sizeof(cache));
    
    int N, M;
    cin >> N >> M;
    
    cout << (isWin(N, M) == 1 ? "A" : "B");
    
    return 0;
}
