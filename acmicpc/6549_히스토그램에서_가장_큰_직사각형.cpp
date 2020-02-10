#include <iostream>
#include <vector>

using namespace std;

long long maxArea(const vector<int>& tiles, int left, int right) {
    if (left == right)
        return tiles[left];
    
    int mid = (left + right) / 2;
    
    long long ret = max(maxArea(tiles, left, mid), maxArea(tiles, mid + 1, right));
    
    int lo = mid, hi = mid + 1;
    int height = min(tiles[lo], tiles[hi]);
    
    ret = max(ret, (long long)height * 2);
    
    while (left < lo || hi < right) {
        if (hi < right && (left == lo || tiles[lo - 1] < tiles[hi + 1])) {
            ++hi;
            height = min(height, tiles[hi]);
        }
        else {
            --lo;
            height = min(height, tiles[lo]);
        }
        
        ret = max(ret, (long long)height * (hi - lo + 1));
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    
    while (true) {
        cin >> n;
        
        if (n == 0)
            break;
        
        vector<int> tiles(n);
        for (int i = 0; i < n; ++i)
            cin >> tiles[i];
        
        cout << maxArea(tiles, 0, n - 1) << '\n';
    }
    
    return 0;
}
