// https://www.acmicpc.net/problem/12100

#include <iostream>
#include <cstring>

using namespace std;

int size;
int cache[21][21];
int board[6][21][21];

void _left2RightMove(int step) {
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < size; ++i) {
        int right = size - 1;
        for (int j = size - 1; 0 <= j; --j) {
            if (board[step][i][j] != 0) {
                cache[i][right] = board[step][i][j];
                --right;
            }
        }
        while (0 <= right)
            cache[i][right--] = 0;
    }
    memcpy(board[step], cache, sizeof(cache));
}

void _right2LeftMove(int step) {
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < size; ++i) {
        int left = 0;
        for (int j = 0; j < size; ++j) {
            if (board[step][i][j] != 0) {
                cache[i][left] = board[step][i][j];
                ++left;
            }
        }
        while (left < size)
            cache[i][left++] = 0;
    }
    memcpy(board[step], cache, sizeof(cache));
}

void _down2UpMove(int step) {
    memset(cache, -1, sizeof(cache));
    for (int j = 0; j < size; ++j) {
        int up = 0;
        for (int i = 0; i < size; ++i) {
            if (board[step][i][j] != 0) {
                cache[up][j] = board[step][i][j];
                ++up;
            }
        }
        while (up < size)
            cache[up++][j] = 0;
    }
    memcpy(board[step], cache, sizeof(cache));
}

void _up2DownMove(int step) {
    memset(cache, -1, sizeof(cache));
    for (int j = 0; j < size; ++j) {
        int down = size - 1;
        for (int i = size - 1; 0 <= i; --i) {
            if (board[step][i][j] != 0) {
                cache[down][j] = board[step][i][j];
                --down;
            }
        }
        while (0 <= down)
            cache[down--][j] = 0;
    }
    memcpy(board[step], cache, sizeof(cache));
}

void move(int step, int direction) {
    if (direction == 0)
        _down2UpMove(step);
    else if (direction == 1)
        _left2RightMove(step);
    else if (direction == 2)
        _up2DownMove(step);
    else if (direction == 3)
        _right2LeftMove(step);
    else
        throw;
}

int _left2RightAdd(int step) {
    int ret = 0;
    for (int i = 0; i < size; ++i) {
        int j = 0;
        while (j < size) {
            int& a = board[step][i][size - 1 - j];
            int& b = board[step][i][size - 1 - (j + 1)];
            
            if (a == 0 || b == 0 || a != b) {
                ret = max(ret, max(a, b));
                ++j;
            }
            else {
                a += b;
                b = 0;
                ret = max(ret, a);
                j += 2;
            }
        }
    }
    return ret;
}

int _right2LeftAdd(int step) {
    int ret = 0;
    for (int i = 0; i < size; ++i) {
        int j = 0;
        while (j < size) {
            int& a = board[step][i][j];
            int& b = board[step][i][j + 1];
            
            if (a == 0 || b == 0 || a != b) {
                ret = max(ret, max(a, b));
                ++j;
            }
            else {
                a += b;
                b = 0;
                ret = max(ret, a);
                j += 2;
            }
        }
    }
    return ret;
}

int _down2UpAdd(int step) {
    int ret = 0;
    for (int j = 0; j < size; ++j) {
        int i = 0;
        while (i < size) {
            int& a = board[step][i][j];
            int& b = board[step][i + 1][j];
            
            if (a == 0 || b == 0 || a != b) {
                ret = max(ret, max(a, b));
                ++i;
            }
            else {
                a += b;
                b = 0;
                ret = max(ret, a);
                i += 2;
            }
        }
    }
    return ret;
}

int _up2DownAdd(int step) {
    int ret = 0;
    for (int j = 0; j < size; ++j) {
        int i = 0;
        while (i < size) {
            int& a = board[step][size - 1 - i][j];
            int& b = board[step][size - 1 - (i + 1)][j];
            
            if (a == 0 || b == 0 || a != b) {
                ret = max(ret, max(a, b));
                ++i;
            }
            else {
                a += b;
                b = 0;
                ret = max(ret, a);
                i += 2;
            }
        }
    }
    return ret;
}

int add(int step, int direction) {
    if (direction == 0)
        return _down2UpAdd(step);
    else if (direction == 1)
        return _left2RightAdd(step);
    else if (direction == 2)
        return _up2DownAdd(step);
    else if (direction == 3)
        return _right2LeftAdd(step);
    else
        throw;
}

int step(int from, int to, int direction) {
    memcpy(board[to], board[from], sizeof(board[from]));
    move(to, direction);
    int ret = add(to, direction);
    move(to, direction);
    return ret;
}

int solution(int from, int toPick) {
    if (toPick == 0)
        return 0;
    
    int ret = 0;
    
    for (int direction = 0; direction < 4; ++direction) {
        ret = max(ret, step(from, from + 1, direction));
        ret = max(ret, solution(from + 1, toPick - 1));
    }
    
    return ret;
}


int main (int argc, char *argv[]) {
    memset(board, -1, sizeof(board));
    
    cin >> size;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> board[0][i][j];
        }
    }
    
    cout << solution(0, 5) << '\n';
    
    return 0;
}
