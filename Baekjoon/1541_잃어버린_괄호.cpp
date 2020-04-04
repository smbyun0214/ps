#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    vector<int> nums;
    
    int n;
    
    while (cin >> n)
        nums.push_back(n);
    
    int idxMinus = -1;
    
    for (int i = 0; i < nums.size(); ++i)
        if (nums[i] < 0) {
            idxMinus = i;
            break;
        }
    
    idxMinus = (idxMinus == -1 ? nums.size() : idxMinus);
    
    int ret = 0;
    
    for (int i = 0; i < idxMinus; ++i)
        ret += nums[i];
    for (int i = idxMinus; i < nums.size(); ++i)
        ret -= abs(nums[i]);
    
    cout << ret << '\n';
    
    return 0;
}
