#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;


bool used[100000];
int cache[100000];


int maxSubsequence(int idx, const vector<int> &nums) {
    if (idx >= N)
        return 0;
    
    int &ret = cache[idx];
    if (used[idx] != false)
        return ret;
    
    used[idx] = true;
    return ret = max(nums[idx], nums[idx] + maxSubsequence(idx + 1, nums));
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    memset(used, false, sizeof(used));
    
    cin >> N;
    
    vector<int> nums(N);
    
    for (int i = 0; i < N; ++i)
        cin >> nums[i];
    
    int ret = nums[0];
    for (int i = 0; i < N; ++i)
        ret = max(ret, maxSubsequence(i, nums));
    
    cout << ret << '\n';
    
    return 0;
}
