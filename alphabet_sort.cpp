//given a list of string and a string alphabet
//sort the list as the alphabet order

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Alphabet {
public:
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;
        char val;
        TrieNode() {
            for (int i = 0; i < 26; ++i) {
                child[i] = NULL;
            }
            isEnd = false;
        }
        TrieNode(char c) {
            for (int i = 0; i < 26; ++i) {
                child[i] = NULL;
            }
            isEnd = false;
            val = c;
        }
    };
    
    Alphabet(string s) {
        root = new TrieNode();
        for (int i = 0; i < s.size(); ++i) {
            hashMap.insert(make_pair(s[i], i));
        }
    }
    
    
    void dfs(vector<string>& result, string temp, TrieNode* root) {
        if (root == NULL) return;
        if (root -> isEnd) {
            result.push_back(temp);
        }
        for (int i = 0; i < 26; ++i) {
            if (root -> child[i] != NULL) {
                temp += root -> child[i] -> val;
                dfs(result, temp, root -> child[i]);
                temp.pop_back();
            }
        }
        
    }
    
    vector<string> alphabetSort(vector<string>& list) {
        vector<string> result;
        if (list.size() == 0) return result;
        for (int i = 0; i < list.size(); ++i) {
            insert(list[i]);
        }
        string temp;
        dfs(result, temp, root);
        return result;
    }
    
    
    
    
    
private:
    unordered_map<char, int> hashMap;
    TrieNode* root;
    
    void insert(string word) {
        TrieNode* p = root;
        int len = (int)word.size();
        for (int i = 0; i < len; ++i) {
            int index = hashMap[word[i]];
            if (p -> child[index] == NULL) {
                p -> child[index] = new TrieNode(word[i]);
            }
            p = p -> child[index];
        }
        p -> isEnd = true;
    }
};




int main() {
    Alphabet test("cbade");
    vector<string> list = {"abc", "bcd", "cdea", "dbc", "bae"};
    vector<string> result = test.alphabetSort(list);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}
