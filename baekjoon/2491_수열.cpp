// https://www.acmicpc.net/problem/2491

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int nums[100001];

int cache[100001];

int solve (int start) {
    int &ret = cache[start];
    if (ret != -1) return ret;
    
    ret = 1;
    
    if (start + 1 < n && nums[start] <= nums[start + 1])
        ret = max(ret, 1 + solve(start + 1));
        
    return ret;
}

int main (int argc, char *argv[]) {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int ret = 0;
    
    memset(cache, -1, sizeof(cache));
    for (int i = n - 1; 0 <= i; --i) {
        ret = max(ret, solve(i));
    }
    
    reverse(nums + 0, nums + n);
    memset(cache, -1, sizeof(cache));
    for (int i = n - 1; 0 <= i; --i) {
        ret = max(ret, solve(i));
    }
    
    cout << ret;
    
    return 0;
}
