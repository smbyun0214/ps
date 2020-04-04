#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int cache[101];

int eraseStrings(int start, const vector<pair<int, int>> &strings) {
    int &ret = cache[start + 1];
    
    if (ret != -1)
        return ret;
    
    ret = 1;
    for (int next = start + 1; next < strings.size(); ++next) {
        if (start == -1 || strings[start].second < strings[next].second)
            ret = max(ret, 1 + eraseStrings(next, strings));
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    int N; cin >> N;
    
    vector<pair<int, int>> strings(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> strings[i].first >> strings[i].second;
    }
    
    sort(strings.begin(), strings.end());
    
    cout << N - (eraseStrings(-1, strings) - 1) << '\n';
    
    return 0;
}
