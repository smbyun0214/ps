#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, num;
    cin >> n;
    
    stack<int> cache;
    string ret;
    
    cache.push(0);
    int tmp = 1;
    
    for (int i = 0; i < n; ++i) {
        cin >> num;
        
        while (tmp <= n && cache.top()!= num) {
            ret += "+\n";
            cache.push(tmp);
            ++tmp;
        }
        
        if (cache.top() == num) {
            ret += "-\n";
            cache.pop();
        }
    }
    
    if (cache.size() == 1)
        cout << ret;
    else
        cout << "NO" << '\n';
    
    return 0;
}
