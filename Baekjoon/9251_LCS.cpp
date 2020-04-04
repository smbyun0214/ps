#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int cache[2][1001];

string A, B;

void lcs() {
    for (int row = 1; row <= A.size(); ++row) {
        for (int col = 1; col <= B.size(); ++col) {
            cache[row % 2][col] = max(cache[(row - 1) % 2][col], cache[(row) % 2][col - 1]);
            
            if (A[row - 1] == B[col - 1])
                cache[row % 2][col] = cache[(row - 1) % 2][col - 1] + 1;
        }
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    memset(cache, 0, sizeof(cache));
    
    cin >> A >> B;
    
    lcs();
    
    cout << cache[A.size() % 2][B.size()] << '\n';
    
    return 0;
}
