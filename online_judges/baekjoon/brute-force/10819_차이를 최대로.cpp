// https://www.acmicpc.net/problem/10819

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool isUsed[8];

int calc(vector<int>& taken, vector<int>& nums) {
    int ret = 0;
    for (int i = 1; i < taken.size(); ++i) {
        int first = taken[i - 1];
        int second = taken[i];
        ret += abs(nums[first] - nums[second]);
    }
    return ret;
}

int solution(vector<int>& taken, vector<int>& nums) {
    int smallest = -1;
    for (int i = 0; i < nums.size(); ++i) {
        if (!isUsed[i]) {
            smallest = i;
            break;
        }
    }
    
    if (smallest == -1) return calc(taken, nums);
    
    int ret = 0;
    
    for (int next = smallest; next < nums.size(); ++next) {
        if (!isUsed[next]) {
            taken.push_back(next);
            isUsed[next] = true;
            ret = max(ret, solution(taken, nums));
            isUsed[next] = false;
            taken.pop_back();
        }
    }
    
    return ret;
}

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    
    vector<int> taken;
    cout << solution(taken, nums) << '\n';
    
    return 0;
}
