#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[1001];

int LIS(int start, const vector<int> &nums) {
    if (start == nums.size())
        return 1;
    
    int &ret = cache[start + 1];
    if (ret != -1)
        return ret;
    
    ret = 0;
    
    for (int next = start + 1; next < nums.size(); ++next) {
        if (start == -1 || nums[start] < nums[next])
            ret = max(ret, 1 + LIS(next, nums));
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    int N; cin >> N;
    
    vector<int> nums(N);
    
    for (int i = 0; i < N; ++i)
        cin >> nums[i];
    
    cout << LIS(-1, nums) << '\n';
    
    return 0;
}
