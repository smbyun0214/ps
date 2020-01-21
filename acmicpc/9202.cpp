#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

bool footprint[4][4];
char board[4][4];

int dy[] = {-1, -1, 0, 1, 1,  1,  0, -1};
int dx[] = { 0,  1, 1, 1, 0, -1, -1, -1};

int score[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

bool inRange(int y, int x) {
    return 0 <= y && y < 4 && 0 <= x && x < 4 && !footprint[y][x];
}

bool hasWord(int y, int x, const string& word) {
    if (!inRange(y, x)) return false;
    if (board[y][x] != word[0]) return false;
    if (word.size() == 1) return true;
    
    footprint[y][x] = true;
    
    for (int direction = 0; direction < 8; ++direction) {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        
        if (hasWord(nextY, nextX, word.substr(1)))
            return true;
    }
    
    footprint[y][x] = false;
    
    return false;
}

bool hasWordInBoard(const string& word) {
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            memset(footprint, 0, sizeof(footprint));
            
            if (hasWord(y, x, word))
                return true;
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int W, B;
    cin >> W;
    
    vector<string> words(W);
    
    for (int i = 0; i < W; ++i)
        cin >> words[i];
    
    sort(words.begin(), words.end());
    
    cin >> B;
    
    while (B--) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j)
                cin >> board[i][j];
        }
        
        int maxScore = 0;
        int foundWords = 0;
        string longestWord = "";
        
        for (int i = 0; i < W; ++i) {
            string word = words[i];
            
            if (hasWordInBoard(word)) {
                maxScore += score[word.size()];
                ++foundWords;
                longestWord = longestWord.size() < word.size() ? word : longestWord;
            }
        }
        
        cout << maxScore << ' ' << longestWord << ' ' << foundWords << '\n';
    }
    
    return 0;
}
