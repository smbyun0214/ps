#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[2001][2001];

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, 0, sizeof(cache));
    
    int N; cin >> N;
    
    vector<int> nums(N);
    
    for (int i = 0; i < N; ++i)
        cin >> nums[i];
    
    for (int i = 0; i < N; ++i) {
        int delta = 0;
        while (0 <= i - delta && (i + delta) < N && nums[i - delta] == nums[i + delta]) {
            cache[i - delta][i + delta] = 1;
            ++delta;
        }
        
        delta = 0;
        while (0 <= i - delta && (i + 1 + delta) < N && nums[i - delta] == nums[i + 1 + delta]) {
            cache[i - delta][i + 1 + delta] = 1;
            ++delta;
        }
    }
    
    int T; cin >> T;
    int start, end;
    
    while (T--) {
        cin >> start >> end;
        cout << cache[start - 1][end - 1] << '\n';
    }
    
    return 0;
}
