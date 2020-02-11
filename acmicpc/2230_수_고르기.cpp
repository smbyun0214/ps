#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> nums(N);
    
    for (int i = 0; i < N; ++i)
        cin >> nums[i];
    
    sort(nums.begin(), nums.end());
    
    int ret = 2000000000;
    
    int l = 0, r = 1;
    
    while (l < N && r < N) {
        int diff = nums[r] - nums[l];
        
        if (diff >= M) {
            ret = min(ret, diff);
            
            if (ret == M) break;
            
            ++l;
        }
        else {
            ++r;
        }
    }
    
    cout << ret << '\n';
    
    return 0;
}
