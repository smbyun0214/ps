#include <iostream>
#include <cstring>

using namespace std;

int H, W;

// [회전유형][칸수][xy]
const int blocks[19][4][2] = {
//    block1
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
//    block2
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
//    block3
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {1, 0}, {1, -1}, {1, -2}},
//    block3 flip
    {{0, 0}, {1, 0}, {2, 0}, {2, -1}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
//    block4
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {1, -1}, {1, 0}},
//    block4
    {{0, 0}, {1, -1}, {1, 0}, {2, -1}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
//    block5
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 0}, {1, -1}, {1, 0}, {2, 0}},
    {{0, 0}, {1, -1}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 0}}
};

int board[500][500];
int footprint[500][500];

bool inRange(int y, int x) {
    return 0 <= y && y < H && 0 <= x && x < W;
}

int score(int y, int x) {
    int ret = 0;
    
    for (int type = 0; type < 19; ++type) {
        int score = 0;
        
        for (int size = 0; size < 4; ++size) {
            int coordY = y + blocks[type][size][0], coordX = x + blocks[type][size][1];
            
            if (!inRange(coordY, coordX)) {
                score = 0;
                break;
            }
                
            score += board[coordY][coordX];
        }
            
        ret = max(ret, score);
    }
    
    return ret;
}

int maxScore() {
    int ret = 0;
    
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            ret = max(ret, score(y, x));
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(board, 0, sizeof(board));
    memset(footprint, 0, sizeof(footprint));
    
    cin >> H >> W;
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> board[i][j];
        }
    }
    
    cout << maxScore() << '\n';
    
    return 0;
}
