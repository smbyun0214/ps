//https://www.acmicpc.net/problem/2110

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countRouter(int step, const vector<int> &houses) {
    int ret = 1;
    
    int start = houses[0];
    
    for (int i = 1; i < houses.size(); ++i) {
        if (houses[i] - start >= step) {
            start = houses[i];
            ++ret;
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, C;
    
    cin >> N >> C;
    
    vector<int> houses(N);
    
    for (int i = 0; i < N; ++i)
        cin >> houses[i];
    
    sort(houses.begin(), houses.end());
    
    int ret = 0;
    int lo = 1, hi = houses.back();
    
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        
        int count = countRouter(mid, houses);
        
        if (C <= count) {
            ret = max(ret, mid);
            lo = mid + 1;
        }
        else
            hi = mid - 1;
            
    }
    
    cout << ret << '\n';
    
    return 0;
}
