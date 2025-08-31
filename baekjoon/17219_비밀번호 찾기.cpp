// https://www.acmicpc.net/problem/17219

#include <iostream>
#include <map>

using namespace std;

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string, string> passwords;
    string site, password;
    while (N--) {
        cin >> site >> password;
        passwords[site] = password;
    }
    
    while (M--) {
        cin >> site;
        cout << passwords[site] << '\n';
    }
    
    return 0;
}
