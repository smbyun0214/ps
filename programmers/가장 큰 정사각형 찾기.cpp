// 참고: https://soobarkbar.tistory.com/m/164

#include <cstring>
#include <vector>

using namespace std;

int cache[1000][1000];

int solution(vector<vector<int>> board) {
    memset(cache, 0, sizeof(cache));
    int ret = 0;

    for (int i = 0; i < board.size(); ++i) {
        if (board[i][0]) {
            cache[i][0] = 1;
            ret = max(ret, cache[i][0]);
        }
    }
    for (int j = 0; j < board[0].size(); ++j) {
        if (board[0][j]) {
            cache[0][j] = 1;
            ret = max(ret, cache[0][j]);
        }
    }
    
    for (int i = 1; i < board.size(); ++i) {
        for (int j = 1; j < board[0].size(); ++j) {
            if (board[i][j] == 1) {
                cache[i][j] = 1 + min(cache[i - 1][j],
                                  min(cache[i][j - 1],
                                      cache[i - 1][j - 1]));
                ret = max(ret, cache[i][j]);
            }
        }
    }
    
    return ret * ret;
}
