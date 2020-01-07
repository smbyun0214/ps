#include <iostream>
#include <deque>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int size, pick, num;
    cin >> size >> pick;
    
    deque<int> cache;
    
    for (int i = 1; i <= size; ++i) cache.push_back(i);
    
    int ret = 0;
    
    for (int i = 0, step; i < pick; ++i) {
        cin >> num;
        
        for (step = 0; step < cache.size(); ++step) {
            if (cache[step] == num)
                break;
        }
        
        if (step < cache.size() - step) {
            while (cache.front() != num) {
                cache.push_back(cache.front());
                cache.pop_front();
                
                ++ret;
            }
        }
        else {
            while (cache.front() != num) {
                cache.push_front(cache.back());
                cache.pop_back();
                
                ++ret;
            }
        }
        
        cache.pop_front();
    }
    
    cout << ret << '\n';
    
    return 0;
}
