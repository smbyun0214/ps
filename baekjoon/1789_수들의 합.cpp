// https://www.acmicpc.net/problem/1789

#include <iostream>

using namespace std;

// i(i+1)/2 <= N < (i+1)(i+2)/2
bool inSeries(long long i, long long N) {
    
    return i * (i + 1) <= 2 * N && 2 * N < (i + 1) * (i + 2);
}

int main (int argc, char *argv[]) {
    
    long long N;
    cin >> N;
    
    long long ret = 0;
    while (!inSeries(ret, N)) {
        ++ret;
    }
    
    cout << ret;
    
    return 0;
}
