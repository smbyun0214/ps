// https://www.acmicpc.net/problem/13172

#include <iostream>

using namespace std;

long long N[10000];
long long S[10000];

long long MOD = 1000000007;

long long square(long long b, int n) {
    if (n == 0) {
        return 1;
    }

    if (n % 2 == 1) {
        return (b * square(b, n - 1)) % MOD;
    }
    
    long long half = square(b, n / 2) % MOD;
    return (half * half) % MOD;
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int M;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        cin >> N[i] >> S[i];
    }

    long long ret = 0;
    for (int i = 0; i < M; ++i) {
        ret = (ret + S[i] * square(N[i], MOD - 2)) % MOD;
    }

    cout << ret << '\n';

    return 0;
}
