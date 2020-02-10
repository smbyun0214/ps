#include <iostream>

using namespace std;

int cache[50];

void initialize() {
    for (int i = 0; i < 50; ++i) {
        cache[i] = (i * (i + 1)) / 2;
    }
}

bool eureka(int toPick, int num) {
    if (toPick == 0) {
        if (num == 0)
            return true;
        
        return false;
    }
    
    for (int i = 1; i < 50; ++i) {
        if (eureka(toPick - 1, num - cache[i]))
            return true;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    initialize();
    
    int T, K;
    
    cin >> T;
    
    while (T--) {
        cin >> K;
        cout << eureka(3, K) << '\n';
    }
    
    return 0;
}

