//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//const int MAX = 500;
//
//const int dy[] = {-1, -1, 0, 1, 1, 0};
//const int dx[] = {-1, 0, 1, 1, 0, -1};
//
//long long pascal[MAX][MAX];
//
//bool inRange(int y, int x) {
//    return 0 <= y && y < MAX && 0 <= x && x <= y && pascal[y][x] != 0;
//}
//
//bool pascalWalk(int y, int x, long long remainder, vector<pair<int, int> > &path) {
//    if (path.size() > 500 || remainder < 0) return false;
//    if (remainder == 0) return true;
//
//    long long cost = pascal[y][x];
//    pascal[y][x] = 0;
//
//    for (int direction = 0; direction < 6; ++direction) {
//        int nextY = y + dy[direction], nextX = x + dx[direction];
//
//        if (inRange(nextY, nextX)) {
//            path.push_back(make_pair(nextY, nextX));
//
//            if (pascalWalk(nextY, nextX, remainder - pascal[nextY][nextX], path))
//                return true;
//
//            path.pop_back();
//        }
//    }
//
//    pascal[y][x] = cost;
//
//    return false;
//}
//
//void initialize() {
//    for (int i = 0; i < MAX; ++i) pascal[i][0] = pascal[i][i] = 1;
//    for (int i = 2; i < MAX; ++i) {
//        for (int j = 1; j < i; ++j) {
//            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
//        }
//    }
//}
//
//int main(int argc, const char * argv[]) {
//    cin.tie(NULL);
//    ios::sync_with_stdio(false);
//
//    for (int i = 0; i < MAX; ++i) pascal[i][0] = pascal[i][i] = 1;
//    for (int i = 2; i < MAX; ++i) {
//        for (int j = 1; j < i; ++j) {
//            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
//        }
//    }
//
//    int T, N;
//
//    cin >> T;
//
//    for (int t = 1; t <= T; ++t) {
//        cin >> N;
//
//        initialize();
//
//        vector<pair<int, int> > path(1, make_pair(0, 0));
//
//        pascalWalk(0, 0, N - pascal[0][0], path);
//
//        cout << "Case #" << t << ':' << '\n';
//
//        for (pair<int, int> &p : path)
//            cout << p.first + 1 << ' ' << p.second + 1 << '\n';
//    }
//
//    return 0;
//}


/**
 *    author:  tourist
 *    created: 11.04.2020 04:17:10
**/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ":\n";
    int n;
    cin >> n;
    int rows = min(30, n);
    n -= rows;
    vector<int> a(rows);
    for (int row = rows - 1; row >= 0; row--) {
      if (n >= (1 << row) - 1) {
        a[row] = 1;
        n -= (1 << row) - 1;
      }
    }
    rows += n;
    a.resize(rows);
    int side = 0;
    for (int row = 0; row < rows; row++) {
      if (a[row] == 1) {
        if (side == 0) {
          for (int j = 0; j <= row; j++) {
            cout << row + 1 << " " << j + 1 << '\n';
          }
        } else {
          for (int j = row; j >= 0; j--) {
            cout << row + 1 << " " << j + 1 << '\n';
          }
        }
        side ^= 1;
      } else {
        if (side == 0) {
          cout << row + 1 << " " << 1 << '\n';
        } else {
          cout << row + 1 << " " << row + 1 << '\n';
        }
      }
    }
  }
  return 0;
}
