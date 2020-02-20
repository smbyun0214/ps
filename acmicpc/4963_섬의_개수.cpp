#include <iostream>
#include <vector>

using namespace std;

bool inRange(int y, int x, const int &height, const int &width) {
    return 0 <= y && y < height && 0 <= x && x < width;
}

void flooding(int y, int x, vector<vector<int> > &board) {
    int height = board.size(), width = board[0].size();
    
    if (inRange(y, x, height, width) && board[y][x]) {
        board[y][x] = 0;
        flooding(y + 1, x, board);
        flooding(y - 1, x, board);
        flooding(y, x + 1, board);
        flooding(y, x - 1, board);
        flooding(y + 1, x - 1, board);
        flooding(y + 1, x + 1, board);
        flooding(y - 1, x - 1, board);
        flooding(y - 1, x + 1, board);
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    while (true) {
        int width, height;
        cin >> width >> height;
        
        if (width == 0 && height == 0)
            break;
        
        vector<vector<int> > board(height, vector<int>(width, 0));
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cin >> board[i][j];
            }
        }
        
        int ret = 0;
        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (board[i][j]) {
                    flooding(i, j, board);
                    ++ret;
                }
            }
        }
        
        cout << ret << '\n';
    }
    
    return 0;
}
