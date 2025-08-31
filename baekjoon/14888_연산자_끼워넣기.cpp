#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int INF = 987654321;

int used[4];

int usedOperator(int type, int i, int j) {
    if (type == 0)
        return i + j;
    else if (type == 1)
        return i - j;
    else if (type == 2)
        return i * j;
    else
        return i / j;
}

pair<int, int> dfs(int start, int value, const vector<int> &nums) {
    if (start == nums.size() - 1)
        return make_pair(value, value);
    
    int minValue = INF, maxValue = -INF;
    
    for (int type = 0; type < 4; ++type) {
        if (used[type] > 0) {
            --used[type];
            
            pair<int, int> minMax = dfs(start + 1, usedOperator(type, value, nums[start + 1]), nums);
            
            minValue = min(minValue, minMax.first);
            maxValue = max(maxValue, minMax.second);
            
            ++used[type];
        }
    }
    
    return make_pair(minValue, maxValue);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    memset(used, 0, sizeof(used));
    
    int N; cin >> N;
    
    vector<int> nums(N);
    
    for (int i = 0; i < N; ++i)
        cin >> nums[i];
    
    cin >> used[0] >> used[1] >> used[2] >> used[3];
    
    pair<int, int> ret = dfs(0, nums[0], nums);
    
    cout << ret.second << '\n' << ret.first << '\n';
    
    return 0;
}
