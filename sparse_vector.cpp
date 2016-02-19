//design a sparse vector class
//support: put, get, add, dot functions

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class SparseVector {
public:
    SparseVector (int n) : N(n) {}
    
    void put(int i, double val) {
        if (i < 0 || i >= N) return;
        if (val == 0.0) {
            dense.erase(i);
        } else {
            dense[i] = val;
        }
    }
    
    double get(int i) {
        if (i < 0 || i >= N) return 0.0;
        if (dense.count(i)) {
            return dense[i];
        } else {
            return 0.0;
        }
    }
    
    double dot(SparseVector b) {
        SparseVector a = *this;
        if (a.N != b.N) return 0.0;
        double sum = 0.0;
        if (a.dense.size() < b.dense.size()) {
            for (auto i : a.dense) {
                if (b.dense.count(i.first)) {
                    sum += a.dense[i.first] * b.dense[i.first];
                }
            }
        } else {
            for (auto i : b.dense) {
                if (a.dense.count(i.first)) {
                    sum += a.dense[i.first] * b.dense[i.first];
                }
            }
        }
        return sum;
    }
    
    SparseVector add(SparseVector b) {
        SparseVector a = *this;
        if (a.N != b.N) return 0.0;
        SparseVector c(N);
        for (auto i : a.dense) {
            c.dense[i.first] = i.second;
        }
        for (auto i : b.dense) {
            c.dense[i.first] += i.second;
        }
        return c;
    }
private:
    int N; //length
    unordered_map<int, double> dense; //dense vector represented by index - value pair
};

int main(int argc, const char * argv[]) {
    SparseVector a(3);
    a.put(0, 1);
    a.put(1, 1);
    a.put(2, 0);
    SparseVector b(3);
    b.put(0, 3);
    b.put(1, 5);
    b.put(2, 7);
    cout << a.dot(b) << endl;
    SparseVector c = a.add(b);
    cout << a.dot(c) << endl;
    cout << "vector a: " << a.get(0) << " ," << a.get(1) << " ," << a.get(2) << endl;
}
