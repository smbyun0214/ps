#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

bool footprint[8][8];
char board[8][8];

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

using namespace std;

bool inRange(int y, int x, int width) {
    return 0 <= y && y < width && 0 <= x && x < width && board[y][x] && !footprint[y][x];
}

bool hasWord(int y, int x, int width, const string& word) {
    if (word.size() == 0) return true;
    
    if (!inRange(y, x, width)) return false;
    if (board[y][x] != word[0]) return false;
    if (word.size() == 1) {
        if (board[y][x] == 'q')
            return false;
        
        return true;
    }
    
    int substrLength = 1;
    
    if (board[y][x] == 'q' && word[0] == 'q' && word[1] == 'u')
        substrLength = 2;
    
    footprint[y][x] = true;
    
    for (int direction = 0; direction < 8; ++direction) {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        
        if (hasWord(nextY, nextX, width, word.substr(substrLength)))
            return true;
    }
    
    footprint[y][x] = false;
    
    return false;
}

bool hasWordInBoard(int width, const string& word) {
    for (int y = 0; y < width; ++y) {
        for (int x = 0; x < width; ++x) {
            memset(footprint, 0, sizeof(footprint));
            
            if (hasWord(y, x, width, word))
                return true;
        }
    }
    
    return false;
}


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int W, D;
    cin >> W;
    
    vector<string> words(W);
    
    for (int i = 0; i < W; ++i)
        cin >> words[i];
    
    sort(words.begin(), words.end());
    
    while (true) {
        cin >> D;
        
        if (D == 0)
            break;
        
        memset(board, 0, sizeof(board));
        
        for (int i = 0; i < D; ++i) {
            for (int j = 0; j < D; ++j) {
                cin >> board[i][j];
            }
        }
        
        vector<string> ret;
        
        for (string word : words) {
            if (hasWordInBoard(D, word))
                ret.push_back(word);
        }
        
        for (string word : ret)
            cout << word << '\n';
        cout << '-' << '\n';
    }
    
    return 0;
}
