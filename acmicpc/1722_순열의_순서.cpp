#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;

bool used[21];
unsigned long cache[21];

int indexNums(unsigned long &value, int digit) {
    int ret = 0;
    
    int j = 0;
    for (int i = 1; i <= N; ++i) {
        if (used[i]) continue;
        
        if (value <= j * cache[digit])
            break;
        
        ++j;
        ret = i;
    }
    
    value -= (j - 1) * cache[digit];
    
    return ret;
}

int countNums(int value) {
    int ret = 0;
    
    for (int i = 1; i < value; ++i)
        if (!used[i])
            ++ret;
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, 0, sizeof(cache));
    memset(used, false, sizeof(used));
    cache[1] = 1;
    for (int i = 2; i <= 20; ++i) {
        cache[i] = i * cache[i - 1];
    }
    
    int k;
    cin >> N >> k;
    
    if (k == 1) {
        unsigned long n; cin >> n;
        
        vector<int> ret;
        
        for (int i = N - 1; 0 <= i; --i) {
            int idx = indexNums(n, i);
            ret.push_back(idx);
            used[idx] = true;
        }
        
        for (int i : ret)
            cout << i << ' ';
        cout << '\n';
    }
    else {
        unsigned long ret = 0;
        
        int n;
        for (int i = 0; i < N; ++i) {
            cin >> n;
            ret += countNums(n) * cache[N - 1 - i];
            used[n] = true;
        }
        
        cout << ret + 1 << '\n';
    }
    
    return 0;
}
