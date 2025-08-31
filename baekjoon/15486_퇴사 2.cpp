// https://www.acmicpc.net/problem/15486

#include <iostream>
#include <cstring>

using namespace std;

int N;
int days[1500001];
int prices[1500001];
int cache[1500001];

int solve(int here) {
    if (here >= N) return 0;
    
    int& ret = cache[here];
    if (ret != -1) return ret;
    
    int there = here + days[here];
    int price = there <= N ? prices[here] : 0;
    
    return ret = max(solve(here + 1), price + solve(there));
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        cin >> days[i] >> prices[i];
    }
    
    int ret = 0;
    for (int here = N - 1; 0 <= here; --here) {
        ret = max(ret, solve(here));
    }
    cout << ret;
    
    return 0;
}
