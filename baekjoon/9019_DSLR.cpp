// https://www.acmicpc.net/problem/9019 

#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

bool visited[10000];

int left(int i) {
    int front = (i * 10) / 10000;
    return (i * 10) % 10000 + front;
}

int right(int i) {
    int back = i % 10;
    return back * 1000 + (i / 10);
}

int double_(int i) {
    return i * 2 % 10000;
}

int substract(int i) {
    return (10000 + i - 1) % 10000;
}


int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        memset(visited, false, sizeof(visited));
        
        queue<pair<string, int> > q;
        q.push(make_pair("", A));

        while (!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();
            string cmd = p.first;
            int a = p.second;

            if (a == B) {
                cout << cmd << '\n';
                break;
            }

            int val = left(a);
            if (!visited[val]) {
                q.push(make_pair(cmd + "L", val));
                visited[val] = true;
            }
            val = right(a);
            if (!visited[val]) {
                q.push(make_pair(cmd + "R", val));
                visited[val] = true;
            } 
            val = double_(a);
            if (!visited[val]) {
                q.push(make_pair(cmd + "D", val));
                visited[val] = true;
            }
            val = substract(a);
            if (!visited[val]) {
                q.push(make_pair(cmd + "S", val));
                visited[val] = true;
            }
        }
    }

    return 0;
}
