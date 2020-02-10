#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, M, n, m;
    cin >> N;
    
    map<int, int> nums;
    
    for (int i = 0; i < N; ++i) {
        cin >> n;
        
        if (nums.find(n) != nums.end())
            ++nums[n];
        else
            nums[n] = 1;
    }
    
    cin >> M;
    
    while (M--) {
        cin >> m;
        
        if (nums.find(m) != nums.end())
            cout << nums[m];
        else
            cout << 0;
        cout << ' ';
    }
    
    return 0;
}
