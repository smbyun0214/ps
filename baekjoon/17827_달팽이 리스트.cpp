// https://www.acmicpc.net/problem/17827

#include <iostream>

using namespace std;

int loopSize;
int cache[200001];

int N, V;

int solve(int toStep) {
    int cacheIndex = (toStep < N ? toStep : V - 1 + ((toStep - (V - 1)) % loopSize));
    return cache[cacheIndex];
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int M;
    cin >> N >> M >> V;
    
    for (int i = 0; i < N; ++i) {
        cin >> cache[i];
    }
    
    loopSize = N - V + 1;
    
    int toStep;
    while (M--) {
        cin >> toStep;
        cout << solve(toStep) << '\n';
    }
    
    return 0;
}
