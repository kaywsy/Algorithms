//given a product class
//a method called getcost
//int getcost(int quantity)
//given an amount of money, return how many product can buy

#include <iostream>
#include <vector>

using namespace std;

class Product {
public:
    Product(int p) : price(p) {}
    
    int get_cost(int quantity) {
        return price * quantity;
    }
private:
    int price;
};


int main() {
    int money;
    cin >> money;
    Product p(4);
    int l = 1, r = 1;
    while (p.get_cost(r) < money) {
        r *= 2;
    }
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (p.get_cost(m) == money) {
            cout << m << endl;
            return -1;
        }
        else if (p.get_cost(m) < money) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << l-1 << endl;
}
