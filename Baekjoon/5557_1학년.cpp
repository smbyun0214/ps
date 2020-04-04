#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long cache[101][901];

long long countCalc(int start, int calc, const vector<int> &nums, const int &result) {
    if (calc < 0 || 20 < calc)
        return 0;
    
    if (start == nums.size()) {
        if (calc == result)
            return 1;
        return 0;
    }
    
    long long &ret = cache[start][calc];
    if (ret != -1)
        return ret;
    
    ret = countCalc(start + 1, calc + nums[start], nums, result) + countCalc(start + 1, calc - nums[start], nums, result);
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    int N, result;
    
    cin >> N;
    
    vector<int> nums(N - 1);
    
    for (int i = 0; i < N - 1; ++i)
        cin >> nums[i];
    
    cin >> result;
    
    cout << countCalc(1, nums[0], nums, result) << '\n';
    
    return 0;
}
