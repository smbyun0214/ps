// https://www.acmicpc.net/problem/2302

#include <iostream>
#include <vector>

bool vips[41];
bool isUsed[41];

using namespace std;

int solve(int left, int right) {
    if (right <= left) return 1;
    
    return solve(left + 2, right) + solve(left + 1, right);
}

int main (int argc, char *argv[]) {
    int N, M;
    cin >> N >> M;
    
    vector<int> range;
    
    while (M--) {
        int i;
        cin >> i;
        vips[i] = true;
        isUsed[i] = true;
        
        if (range.empty() && i != 0)
            range.push_back(0);
        range.push_back(i);
    }
    
    if (!range.empty() && range.back() != N)
        range.push_back(N + 1);
    
    int ret = 1;
    if (range.empty()) {
        ret *= solve(1, N);
    }
    else {
        for (int i = 1; i < range.size(); ++i) {
            int left = range[i - 1], right = range[i];
            ret *= solve(left + 1, right - 1);
        }
    }
    
    cout << ret;
    
    return 0;
}
