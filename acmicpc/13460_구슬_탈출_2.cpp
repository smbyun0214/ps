#include <iostream>
using namespace std;

int H, W;

struct Point {
    int y;
    int x;
    
    Point() {}
    
    Point(int _y, int _x): y(_y), x(_x) {}
    
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    
    Point operator+(const Point& other) const {
        return Point(y + other.y, x + other.x);
    }
    
    void operator+=(const Point& other) {
        y += other.y;
        x += other.x;
    }
    
    Point& operator=(const Point& other) {
        y = other.y;
        x = other.x;
        
        return *this;
    }
};

char board[10][10];

Point direction[] = {Point(-1, 0), Point(0, 1), Point(1, 0), Point(0, -1)};

Point ptHoll;

bool inRange(int y, int x) {
    return 0 <= y && y < H && 0 <= x && x < W && board[y][x] == '.';
}

bool isBlueFirstThanRed(const Point& blue, const Point& red, int type) {
    Point nextRed = red + direction[type];
    
    while (inRange(nextRed.y, nextRed.x))
        nextRed += direction[type];

    return nextRed == blue;
}


int moving(Point& point, int type) {
    // -1 : 탐색 X
    // 0 : 탈출
    // 1 : 탐색 O
    
    int isMoving = -1;
    Point next = point + direction[type];
    
    while (inRange(next.y, next.x)) {
        point = next;
        next += direction[type];
        isMoving = 1;
    }
    
    if (next == ptHoll) return 0;
    
    return isMoving;
}

void print() {
    cout << "============" << '\n';
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    
}
int escape(const Point& blue, const Point& red, int usedType, int toMove) {
    if (red == ptHoll)
        return toMove;
    
    if (toMove == 0)
        return -1;
    
    int ret = -1;
    
    for (int type = 0; type < 4; ++type) {
        if (usedType != -1 && type == (usedType + 2) % 4) continue;
        
        Point hereBlue, nextBlue;
        Point hereRed, nextRed;
        
        hereBlue = nextBlue = blue;
        hereRed = nextRed = red;
        
        bool isBlueFirst = isBlueFirstThanRed(hereBlue, hereRed, type);
        
        int isMovingBlue, isMovingRed;
        
        if (isBlueFirst) {
            isMovingBlue = moving(nextBlue, type);
            
            if (isMovingBlue == 0) board[hereBlue.y][hereBlue.x] = '.';
            if (isMovingBlue == 1) swap(board[hereBlue.y][hereBlue.x], board[nextBlue.y][nextBlue.x]);
            
            isMovingRed = moving(nextRed, type);
            
            if (isMovingBlue == 1) swap(board[nextBlue.y][nextBlue.x], board[hereBlue.y][hereBlue.x]);
        }
        else {
            isMovingRed = moving(nextRed, type);
            
            if (isMovingRed == 0) board[hereRed.y][hereRed.x] = '.';
            if (isMovingRed == 1)
                swap(board[hereRed.y][hereRed.x], board[nextRed.y][nextRed.x]);
            
            isMovingBlue = moving(nextBlue, type);
            
            if (isMovingRed == 1) swap(board[nextRed.y][nextRed.x], board[hereRed.y][hereRed.x]);
        }
        
        board[hereBlue.y][hereBlue.x] = 'B';
        board[hereRed.y][hereRed.x] = 'R';
        
        if (isMovingBlue == 0) continue;
        if (isMovingRed == 0) ret = max(ret, toMove - 1);
        
        if (isMovingBlue == 1 || isMovingRed == 1) {
            if (isBlueFirst) {
                swap(board[hereBlue.y][hereBlue.x], board[nextBlue.y][nextBlue.x]);
                swap(board[hereRed.y][hereRed.x], board[nextRed.y][nextRed.x]);
            }
            else {
                swap(board[hereRed.y][hereRed.x], board[nextRed.y][nextRed.x]);
                swap(board[hereBlue.y][hereBlue.x], board[nextBlue.y][nextBlue.x]);
            }
            
            ret = max(ret, escape(nextBlue, nextRed, type, toMove - 1));
            
            if (isBlueFirst) {
                swap(board[nextRed.y][nextRed.x], board[hereRed.y][hereRed.x]);
                swap(board[nextBlue.y][nextBlue.x], board[hereBlue.y][hereBlue.x]);
            }
            else {
                swap(board[nextBlue.y][nextBlue.x], board[hereBlue.y][hereBlue.x]);
                swap(board[nextRed.y][nextRed.x], board[hereRed.y][hereRed.x]);
            }
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> H >> W;
    
    Point blue, red;
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> board[i][j];
            
            if (board[i][j] == 'B')
                blue = Point(i, j);
            else if (board[i][j] == 'R')
                red = Point(i, j);
            else if (board[i][j] == 'O')
                ptHoll = Point(i, j);
        }
    }
    
    int ret = escape(blue, red, -1, 10);
    
    cout << (ret == -1 ? -1 : 10 - ret) << '\n';
    
    return 0;
}
