//https://mini-ko.tistory.com/11

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int INF = 987654321;

int N, M, H;

bool board[31][11];

bool goDown() {
    for (int i = 1; i <= N; ++i) {
        int pos = i;
        
        for (int j = 1; j <= H; ++j) {
            if (board[j][pos])
                ++pos;
            else if (board[j][pos - 1])
                --pos;
        }
        
        if (pos != i)
            return false;
    }
    
    return true;
}

//bool isUsed(const pair<int, int> &p) {
//    return !board[p.first][p.second - 1] && !board[p.first][p.second] && !board[p.first][p.second + 1];
//}

//int isLadder(int start, int step, const vector<pair<int, int> > &candi) {
//    if (goDown())
//        return 0;
//
//    if (step == 0) return INF;
//
//    int ret = INF;
//    int size = candi.size();
//
//    for (int i = start; i < size; ++i) {
//        if (start == -1) {
//            ret = min(ret, isLadder(i + 1, step, candi));
//            continue;
//        }
//
//        const pair<int, int> &p = candi[i];
//
//        if (isUsed(p)) {
//            board[p.first][p.second] = true;
//            ret = min(ret, 1 + isLadder(i + 1, step - 1, candi));
//            board[p.first][p.second] = false;
//        }
//    }
//
//    return ret;
//}

int isLadder(const vector<pair<int, int> > &candi) {
    if (goDown()) return 0;

    int ret = INF;
    
    for (int i = 0; i < candi.size(); ++i) {
        board[candi[i].first][candi[i].second] = true;
        
        if (goDown()) return 1;
        
        for (int j = i + 1; j < candi.size() && 2 < ret; ++j) {
            board[candi[j].first][candi[j].second] = true;
            
            if (goDown()) ret = min(ret, 2);
            
            for (int k = j + 1; k < candi.size() && 3 < ret; ++k) {
                board[candi[k].first][candi[k].second] = true;
                
                if (goDown()) ret = min(ret, 3);
                
                board[candi[k].first][candi[k].second] = false;
            }
            board[candi[j].first][candi[j].second] = false;
        }
        board[candi[i].first][candi[i].second] = false;
    }

    if (ret == INF)
        return -1;
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(board, false, sizeof(board));
    
    cin >> N >> M >> H;
    
    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        board[a][b] = true;
    }
    
    vector<pair<int, int>> candi;
    
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j < N; ++j) {
            if (!board[i][j - 1] && !board[i][j] && !board[i][j + 1])
                candi.push_back(make_pair(i, j));
        }
    }
    
//    int ret = isLadder(-1, 3, candi);
//    cout << (ret == INF ? -1 : ret) << '\n';
    
    cout << isLadder(candi) << '\n';
    
    return 0;
}
