// https://www.acmicpc.net/problem/4097

#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

long long cache[250001];
long long earnings[250001];

int N;

long long solve(int day) {
    if (day == N) return 0;
    
    long long& ret = cache[day];
    if (ret != numeric_limits<long long>::min()) return ret;
    
    ret = earnings[day];
    return ret = max(ret, earnings[day] + solve(day + 1));
//    return ret = max(earnings[day], earnings[day] + solve(day + 1));
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while (true) {
        for (int i = 0; i < 250001; ++i) {
            cache[i] = numeric_limits<long long>::min();
        }
        
        cin >> N;
        if (N == 0) break;
        
        for (int i = 0; i < N; ++i) {
            cin >> earnings[i];
        }
        
        long long ret = numeric_limits<long long>::min();
        for (int i = N - 1; 0 <= i; --i) {
            ret = max(ret, solve(i));
        }
        
        cout << ret << '\n';
    }
    
    return 0;
}
