//https://codeforces.com/gym/102556/problem/G
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int W, L, X, Y;
    
    cin >> W >> L >> X >> Y;
    
    int minWidth = min(X, W - X + 1);
    int minLength = min(Y, L - Y + 1);
    
    int ret = minWidth * minLength;
    
    if (W * L > 2 * ret)
        cout << ret << '\n';
    else
        cout << "I don't wanna do this anymore!" << '\n';
    
    return 0;
}
