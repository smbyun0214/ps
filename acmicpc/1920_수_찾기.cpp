#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(const vector<int>& nums, int left, int right, int i) {
    int mid = (left + right) / 2;
    
    if (i == nums[mid])
        return true;
    else if (right < left)
        return false;
    
    if (i < nums[mid])
        return binarySearch(nums, left, mid - 1, i);
    else
        return binarySearch(nums, mid + 1, right, i);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, M, m;
    cin >> N;
    
    vector<int> nums(N);
    
    for (int i = 0; i < N; ++i)
        cin >> nums[i];
    
    sort(nums.begin(), nums.end());
    
    cin >> M;
    
    while (M--) {
        cin >> m;
        cout << (binarySearch(nums, 0, nums.size() - 1, m) ? 1 : 0) << '\n';
    }
    
    return 0;
}
