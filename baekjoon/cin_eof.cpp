//
//  cin_eof.cpp
//  ProblemSolving
//
//  Created by 변성목 on 2020/10/25.
//  Copyright © 2020 변성목. All rights reserved.
//

#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    string row;
    while (!cin.eof()) {
        getline(cin, row);
        cout << row << '\n';
    }
    return 0;
}
