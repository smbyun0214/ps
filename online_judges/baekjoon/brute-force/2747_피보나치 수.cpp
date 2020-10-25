// https://www.acmicpc.net/problem/2747

#include <iostream>
#include <cstring>

using namespace std;

int cache[46];

int fibonacci(int);

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    int n;
    cin >> n;
    
    cout << fibonacci(n) << '\n';
    
    return 0;
}

int fibonacci(int n) {
    if (n < 1) return 0;
    if (n == 1) return 1;
    
    int& ret = cache[n];
    if (ret != -1)
        return ret;
    
    return ret = fibonacci(n-1) + fibonacci(n-2);
}
