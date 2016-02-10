//given a string s, find the length of the longest substring that contains at most k distinct characters
//e.g. given s = "eceba", k = 3
//return "eceb" which its length is 4

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestSubstringKDistinct(string s, int k) {
    int n = (int)s.size();
    unordered_map<char, int> hashMap;
    int l = 0, r = 0, size = 0;
    while (l < n) {
        while (r < n) {
            if (!hashMap.count(s[r])) {
                if (hashMap.size() >= k) {
                    break;
                }
            }
            hashMap[s[r]]++;
            r++;
        }
        size = max(size, r - l);
        hashMap[s[l]]--;
        if (hashMap[s[l]] == 0) {
            hashMap.erase(s[l]);
        }
        l++;
    }
    return size;
}

int main(int argc, const char * argv[]) {
    string s = "eceba";
    cout << longestSubstringKDistinct(s, 3) << endl;
}
