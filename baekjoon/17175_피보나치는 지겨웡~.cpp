// https://www.acmicpc.net/problem/17175

#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int cache[51];

int fibonacci(int n) { // 호출
    if (n < 2) {
        return 1;
    }
    
    int& ret = cache[n];
    if (ret != -1) return ret;
    
    return ret = (1 + fibonacci(n - 2) + fibonacci(n - 1)) % MOD;
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    int n;
    cin >> n;
    
    cout << fibonacci(n);
    
    return 0;
}
