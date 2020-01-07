#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    queue<int> cache;
    
    for (int i = 1; i <= N; ++i) {
        cache.push(i);
    }
    
    bool step = true;
    while (cache.size() != 1) {
        if (step) {
            cache.pop();
        }
        else {
            cache.push(cache.front());
            cache.pop();
        }
        step = !step;
    }
    
    cout << cache.front() << '\n';
    
    return 0;
}
