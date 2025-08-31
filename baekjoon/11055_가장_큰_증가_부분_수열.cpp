#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[1001];

int increase(int start, const vector<int> &nums) {
    int &ret = cache[start];

    if (ret != -1) return ret;
    
    ret = nums[start];
    
    for (int next = start + 1; next < nums.size(); ++next) {
        if (nums[start] < nums[next])
            ret = max(ret, nums[start] + increase(next, nums));
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    int N; cin >> N;
    
    vector<int> nums(N + 1, 0);
    
    for (int i = 1; i <= N; ++i) {
        cin >> nums[i];
    }
    
    cout << increase(0, nums) << '\n';
    
    return 0;
}
