#include <iostream>
#include <cstring>

using namespace std;

int height, width;
int board[301][301];
int cache[301][301];

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, 0, sizeof(cache));
    
    cin >> height >> width;
    
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= width; ++j) {
            cin >> board[i][j];
            cache[i][j] = cache[i - 1][j] + cache[i][j - 1] - cache[i - 1][j - 1] + board[i][j];
        }
    }
    
    int K;
    int startY, startX, endY, endX;
    
    cin >> K;
    
    while (K--) {
        cin >> startY >> startX >> endY >> endX;
        cout << cache[endY][endX] - cache[startY - 1][endX] - cache[endY][startX - 1] + cache[startY - 1][startX - 1] << '\n';
    }
    
    
    return 0;
}
