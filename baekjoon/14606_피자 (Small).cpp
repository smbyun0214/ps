// https://www.acmicpc.net/problem/14606

#include <iostream>
#include <cstring>

using namespace std;

int cache[11];

int pizza(int n) {
    if (n == 1) return 0;
    
    int& ret = cache[n];
    if (ret != -1) return ret;
    
    ret = 0;
    for (int i = 1; i < n; ++i) {
        ret = max(ret, i * (n - i) + pizza(i) + pizza(n - i));
    }
    
    return ret;
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    int n;
    cin >> n;
    
    cout << pizza(n);
    
    return 0;
}
