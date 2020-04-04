#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 987654321;

bool button[10];

int minDiff(int N, int square) {
    if (square == -1)
        return N;
    
    int diff = MAX;
    
    for (int i = 0; i < 10; ++i) {
        if (!button[i]) continue;
        
        int add = i * pow(10, square);
        int diff2 = minDiff(N - add, square - 1);
        
        if (abs(diff) > abs(diff2)) {
            diff = diff2;
        }
    }
    
    return diff;
}

int digitCount(int num) {
    if (num == 0)
        return 1;
    
    int ret = 0;
    
    while (num) {
        ++ret;
        num /= 10;
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    for (int i = 0; i < 10; ++i) button[i] = true;
    
    int N, M, m;
    cin >> N >> M;
    
    while (M--) {
        cin >> m;
        button[m] = false;
    }
    
    int baseDiff = abs(100 - N);
    
    int digit = digitCount(N);
    
    int diff0 = minDiff(N, digit);
    int diff1 = minDiff(N, digit - 1);
    
    int diff = abs(diff0) < abs(diff1) ? diff0 : diff1;
    
    if (digit > 1) {
        int diff0 = minDiff(N, digit - 2);
        diff = abs(diff) < abs(diff0) ? diff : diff0;
    }
    
    int closest = abs(N - diff);
    int newDiff = abs(closest - N);
    
    cout << min(baseDiff, digitCount(closest) + newDiff) << '\n';
    
    return 0;
}
