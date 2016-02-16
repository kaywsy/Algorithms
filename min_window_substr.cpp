string minWindow(string &source, string &target) {
        int shash[256] = {0};
        int thash[256] = {0};
        int size = INT_MAX;
        string result;
        int i = 0, j = 0;
        for (int k = 0; k < target.size(); ++k) {
            thash[target[k]]++;
        }
        for ( ; i < source.size(); ++i) {
            while (j < source.size() && !valid(shash, thash)) {
                shash[source[j]]++;
                j++;
            }
            if (valid(shash, thash)) {
                if (size > j - i) {
                    size = j - i;
                    result = source.substr(i, j-i);
                }
            }
            shash[source[i]]--;
            
        }
        return result;
    }
    
    bool valid(int* shash, int* thash) {
        for (int i = 0; i < 256; ++i) {
            if (thash[i] > shash[i]) return false;
        }
        return true;
    }
