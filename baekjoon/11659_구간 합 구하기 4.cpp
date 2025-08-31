// https://www.acmicpc.net/problem/11659

#include <iostream>
#include <cstring>

using namespace std;

long long cache[100001];

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, 0, sizeof(cache));

    int M, N;
    cin >> M >> N;

    for (int i = 1; i <= M; ++i) {
        cin >> cache[i];
        if (i > 0) {
            cache[i] += cache[i - 1];
        }
    }

    int i, j;
    while (N--) {
        cin >> i >> j;
        cout << cache[j] - cache[i-1] << '\n';
    }

    return 0;
}
