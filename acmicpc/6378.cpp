#include <iostream>
#include <cstring>

using namespace std;

int cache[1000];

int digitalRoot(int size) {
    int n = 0, ret = 0, T = 3;
    
    for (int i = 0; i < size; ++i)
        n += cache[i];
    
    while (T--) {
        ret = 0;
        
        while (n) {
            ret += (n % 10);
            n /= 10;
        }
        
        n = ret;
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    string str;
    
    while (true) {
        cin >> str;
        
        if (str == "0")
            break;
        
        memset(cache, 0, sizeof(cache));
        
        for (int i = 0; i < str.size(); ++i)
            cache[i] = str[i] - '0';
        
        cout << digitalRoot(str.size()) << '\n';
    }
    
    return 0;
}
