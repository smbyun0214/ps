// https://www.acmicpc.net/problem/17266

#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N, M;
    cin >> N >> M;
    
    vector<int> lamps(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> lamps[i];
    }
    
    int width = 0;
    for (int i = 1; i < lamps.size(); ++i) {
        width = max(width, lamps[i] - lamps[i - 1]);
    }
    
    cout << max(lamps.front(),
            max(N - lamps.back(),
                (width + 1) / 2));
    
    return 0;
}
