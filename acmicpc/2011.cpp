#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MOD = 1000000;

int cache[5001];

bool is2Digits(int idx, const string &num) {
    int first = num[idx] - '0';
    int second = num[idx + 1] - '0';
    
    if (first == 2) {
        if (second <= 6)
            return true;
        
        return false;
    }
    
    if (first > 2 || first == 0)
        return false;
    
    return true;
}

int password(int start, const string &number) {
    if (start >= number.size()) return 1;
    if (number[start] == '0') return 0;
    
    int &ret = cache[start];
    if (ret != -1)
        return ret;
    
    if (start < number.size() - 1 && is2Digits(start, number))
        ret = ((password(start + 1, number) % MOD) + (password(start + 2, number) % MOD)) % MOD;
    else
        ret = password(start + 1, number) % MOD;
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    string number;
    cin >> number;
    
    cout << password(0, number) << '\n';
    
    return 0;
}
