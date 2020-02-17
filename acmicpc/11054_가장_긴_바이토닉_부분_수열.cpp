#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int cache0[1001], cache1[1001];

int decrease(int start, int cache[], const vector<int> &nums) {
    int &ret = cache[start + 1];

    if (ret != -1) return ret;
    
    ret = 1;
    
    for (int next = start + 1; next < nums.size(); ++next) {
        if (start == -1 || nums[start] > nums[next])
            ret = max(ret, 1 + decrease(next, cache, nums));
    }
    
    return ret;
}

int bitonic(vector<int> &nums) {
    decrease(-1, cache0, nums);
    
    reverse(nums.begin(), nums.end());
    decrease(-1, cache1, nums);
    
    int ret = 0;
    for (int i = 1; i <= N; ++i)
        ret = max(ret, cache0[i] + cache1[N + 1 - i]);
    
    return ret - 1;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache0, -1, sizeof(cache0));
    memset(cache1, -1, sizeof(cache1));
    
    cin >> N;
    
    vector<int> nums(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    
    cout << bitonic(nums) << '\n';
    
    return 0;
}
