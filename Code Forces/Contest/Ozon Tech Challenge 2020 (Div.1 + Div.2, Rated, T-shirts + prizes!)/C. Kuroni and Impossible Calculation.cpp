// https://codeforces.com/contest/1305/problem/C
#include <iostream>
#include <vector>

using namespace std;

int MOD;

long long Calculation(int start, const vector<int> &nums) {
    if (start == nums.size())
        return 1;
    
    long long ret = Calculation(start + 1, nums) % MOD;
    
    for (int next = start + 1; next < nums.size(); ++next) {
        if (ret == 0) return 0;
        
        ret = (ret * abs(nums[start] - nums[next])) % MOD ;
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N >> MOD;
    
    vector<int> nums(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    
    cout << Calculation(0, nums) << '\n';
    
    return 0;
}
