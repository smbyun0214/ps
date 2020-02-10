#include <iostream>
#include <vector>

using namespace std;

int N, S;

int countSubsequences(int idx, int sum, const vector<int>& nums) {
    int ret = 0;
    
    for (int i = idx; i < N; ++i) {
        sum += nums[i];
        
        if (sum == S) ++ret;
        
        ret += countSubsequences(i + 1, sum, nums);
        
        sum -= nums[i];
    }
    
    return ret;
}


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N >> S;
    
    vector<int> nums(N);
    
    for (int i = 0; i < N; ++i)
        cin >> nums[i];
    
    cout << countSubsequences(0, 0, nums) << '\n';

    return 0;
}
