#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
int cache[2][100001];

int sticker(int row, int column, const vector<vector<int>> &nums) {
    if (column >= N)
        return 0;
    
    if (row == -1 && column == -1)
        return max(sticker(0, column + 1, nums), sticker(1, column + 1, nums));
    
    int &ret = cache[row][column];
    if (ret != -1)
        return ret;
    
    int ret0 = nums[row][column] + sticker(0, column + 2, nums);
    int ret1 = nums[row][column] + sticker(1, column + 2, nums);
    int ret2 = nums[row][column] + sticker((row + 1) % 2, column + 1, nums);
    
    return ret = max(max(ret0, ret1), ret2);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    while (T--) {
        memset(cache, -1, sizeof(cache));
        
        cin >> N;
        
        vector<vector<int>> nums(2, vector<int>(N));
        
        for (int i = 0; i < N; ++i) cin >> nums[0][i];
        for (int i = 0; i < N; ++i) cin >> nums[1][i];
        
        cout << sticker(-1, -1, nums) << '\n';
    }
    
    return 0;
}
