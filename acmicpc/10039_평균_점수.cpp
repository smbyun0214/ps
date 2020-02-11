#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N = 5, n;
    
    int ret = 0;
    
    while (N--) {
        cin >> n;
        ret += max(n, 40);
    }
    
    cout << ret / 5 << '\n';
    
    return 0;
}
