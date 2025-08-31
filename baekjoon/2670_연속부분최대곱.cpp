// https://www.acmicpc.net/problem/2670

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int n;
double real[10000];
double cache[10000];

double maxReal(int start) {
    double& ret = cache[start];
    if (!isnan(ret)) return ret;
    
    ret = real[start];
    if (start + 1 < n)
        ret = max(ret, real[start] * maxReal(start + 1));
    
    return ret;
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> real[i];
    }
    
    double ret = 0;
    for (int i = 0; i < n; ++i) {
        ret = max(ret, maxReal(i));
    }
    
    cout.precision(3);
    cout << fixed << ret;

    return 0;
}
