// https://www.acmicpc.net/problem/13301

#include <iostream>
#include <cstring>

using namespace std;

long long cache[83];

long long fibo(int n) {
    if (n == 1 || n == 2) return 1;
    
    long long &ret = cache[n];
    if (ret != -1) return ret;
    
    return ret = fibo(n - 2) + fibo(n - 1);
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    int N;
    cin >> N;
    
    cout << 2 * fibo(N + 2);
    
    return 0;
}
