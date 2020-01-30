#include <iostream>
#include <cmath>

using namespace std;

int digits(int N) {
    int ret = 0;
    
    while (N) {
        ++ret;
        N /= 10;
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    int ret = 0;
    int digit = digits(N);
    
    for (int i = 0; i < digit - 1; ++i) {
        ret += (i + 1) * (9 * pow(10, i));
    }
    
    ret += digit * (N - pow(10, digit - 1) + 1);
    
    cout << ret << '\n';
    
    return 0;
}
