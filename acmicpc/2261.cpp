#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MAX = 987654321;

bool compareSecond(const pair<int, int> &pair1, const pair<int, int> &pair2) {
    if (pair1.second == pair2.second)
        return pair1.first > pair2.first;
    
    return pair1.second > pair2.second;
}

int squareDistance(const pair<int, int> &point1, const pair<int, int> &point2) {
    return (point1.first - point2.first) * (point1.first - point2.first) + (point1.second - point2.second) * (point1.second - point2.second);
}

int minSquareDistance(const vector<pair<int, int>> &points, int left, int right) {
    if (left == right)
        return MAX;
    
    if (left + 1 == right)
        return squareDistance(points[left], points[right]);
    
    int mid = (left + right) / 2;
    
    int leftMin = minSquareDistance(points, left, mid);
    int rightMin = minSquareDistance(points, mid, right);
    
    int ret = min(leftMin, rightMin);
    
    vector<pair<int, int>> candidate;
    candidate.push_back(points[mid]);
    
    for (int i = mid - 1; left <= i; --i) {
        int squareWidth = (points[i].first - points[mid].first) * (points[i].first - points[mid].first);
        
        if (squareWidth >= ret)
            break;
        
        candidate.push_back(points[i]);
    }
    
    for (int i = mid + 1; i < right; ++i) {
        int squareWidth = (points[i].first - points[mid].first) * (points[i].first - points[mid].first);
        
        if (squareWidth >= ret)
            break;
        
        candidate.push_back(points[i]);
    }
    
    int size = candidate.size();
    if (size > 1) {
        sort(candidate.begin(), candidate.end(), compareSecond);
        
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                int squareHeight = (candidate[i].second - candidate[j].second) * (candidate[i].second - candidate[j].second);
                
                if (squareHeight >= ret)
                    break;
                
                ret = min(ret, squareDistance(candidate[i], candidate[j]));
            }
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    
    cin >> N;
    
    vector<pair<int, int>> points(N);
    
    for (int i = 0; i < N; ++i)
        cin >> points[i].first >> points[i].second;
    
    sort(points.begin(), points.end());

    vector<pair<int, int>>::iterator it = unique(points.begin(), points.end());
    if (it != points.end()) {
        cout << 0 << '\n';
        return 0;
    }

    points.erase(it, points.end());

    cout << minSquareDistance(points, 0, points.size() - 1) << '\n';
    
    return 0;
}

