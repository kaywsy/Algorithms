//given a string, find the longest substring without repeating character
//hashmap
#include <iostream>

using namespace std;

string longestSubtring(string s) {
    bool existed[256] = {false};
    int i = 0, j = 0, maxlen = 0;
    int start = 0, end = 0; //start and end point of the longest substring
    while (j < (int)s.size()) {
        if (existed[s[j]]) {
            if (j - i > maxlen) {
                start = i;
                end = j;
                maxlen = j - i;
            }
            while (s[i] != s[j]) {
                existed[s[i++]] = false;
            }
            i++;
            j++;
        } else {
            existed[s[j]] = true;
            j++;
        }
    }
    if ((int)s.size() - i > maxlen) {
        start = i;
        end = (int)s.size() - 1;
        maxlen = (int)s.size() - i;
    }
    return s.substr(start, maxlen);
}



int main(int argc, const char * argv[]) {
    string test = "bbbb";
    cout << longestSubtring(test) << endl;
}
