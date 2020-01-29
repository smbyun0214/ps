#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool compareSecond(const pair<int, int> &point1, const pair<int, int> &point2) {
    if (point1.second == point2.second)
        return point1.first > point2.first;
    
    return point1.second > point2.second;
}

int distance(const pair<int, int> &point1, const pair<int, int> &point2) {
    int first = point1.first - point2.first;
    int second = point1.second - point2.second;
    
    return first * first + second * second;
}

int minDistance(int left, int right, const vector<pair<int, int>> &points) {
    if (left + 1 == right)
        return distance(points[left], points[right]);
    
    int mid = (left + right) / 2;
    
    int leftDistance = minDistance(left, mid, points);
    int rightDistance = minDistance(mid, right, points);
    
    int ret = min(leftDistance, rightDistance);
    
    vector<pair<int, int>> candidate;
    
    for (int lo = mid - 1; left <= lo; --lo) {
        int first = points[mid].first - points[lo].first;
        if ((first * first) > ret)
            break;
        
        candidate.push_back(points[lo]);
    }
    
    for (int hi = mid + 1; hi <= right; ++hi) {
        int first = points[hi].first - points[mid].first;
        if ((first * first) > ret)
            break;
        
        candidate.push_back(points[hi]);
    }
    
    sort(candidate.begin(), candidate.end(), compareSecond);
    
    for (int i = 0; i < candidate.size(); ++i) {
        for (int j = i + 1; j < candidate.size(); ++j) {
            ret = min(ret, distance(candidate[i], candidate[j]));
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N;
    
    vector<pair<int, int>> points(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    sort(points.begin(), points.end());
    
    cout << minDistance(0, N - 1, points) << '\n';
    
    return 0;
}
