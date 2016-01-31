#include <iostream>
#include <vector>

using namespace std;

bool canWinHelper(string s);

vector<string> possibleMoves(string s) {
    vector<string> result;
    for (int i = 0; i < (int)s.size()-1; ++i) {
        if (s[i] == '+' && s[i+1] == '+') {
            s[i] = '-';
            s[i+1] = '-';
            result.push_back(s);
            s[i] = '+';
            s[i+1] = '+';
        }
    }
    return result;
}

//idea: backtracking
bool canWin(string s) {
    if (s.size() == 0) return false;
    return canWinHelper(s);
}

bool canWinHelper(string s) {
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == '+' && s[i+1] == '+') {
            s[i] = s[i+1] = '-';
            bool win = !canWinHelper(s);
            s[i] = s[i+1] = '+';
            if (win) return true;
        }
    }
    return false;
}

int main() {
    string test = "++++";
    vector<string> result = possibleMoves(test);
    bool win = canWin(test);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    cout << "Can Win?" << " " << win << endl;
}
