#include <iostream>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, idx;
    cin >> N;
    
    long long count = 0;
    map<int, long long> cache;
    
    while (N--) {
        cin >> idx;
        
        if (cache.empty())
            cache[idx] = 0;
        else {
            map<int, long long>::iterator itL = cache.lower_bound(idx);
            map<int, long long>::iterator itR = cache.lower_bound(idx);
            
            long long left = -1, right = -1;
            
            if (itL != cache.begin()) left = (--itL)->second + 1;
            if (itR != cache.end()) right = itR->second + 1;

            cache[idx] = max(left, right);
        }
        
        count += cache[idx];
        cout << count << '\n';
    }
    
    return 0;
}
