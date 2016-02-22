//given a doubly linked list and an array of list nodes
//return the number of components in the array

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* pre;
    ListNode* next;
    ListNode(int i) : val(i) {
        pre = NULL;
        next = NULL;
    }
};

int findComponent(vector<ListNode*>& list) {
    unordered_set<ListNode*> s(list.begin(), list.end());
    int count = (int)list.size();
    for (ListNode* l : list) {
        s.erase(l);
        ListNode* pre = l -> pre;
        ListNode* next = l -> next;
        while (s.find(pre) != s.end()) {
            s.erase(pre);
            pre = pre -> pre;
            count--;
        }
        while (s.find(next) != s.end()) {
            s.erase(next);
            next = next -> next;
            count--;
        }
    }
    return count;
}

int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    ListNode* l6 = new ListNode(6);
    l1 -> next = l2;
    l2 -> pre = l1;
    l2 -> next = l3;
    l3 -> pre = l2;
    l3 -> next = l4;
    l4 -> pre = l3;
    l4 -> next = l5;
    l5 -> pre = l4;
    l5 -> next = l6;
    l6 -> pre = l5;
    vector<ListNode*> test1 = {l1, l3, l5, l6};
    vector<ListNode*> test2 = {l2, l3, l5};
    vector<ListNode*> test3 = {l1, l3, l5};
    cout << findComponent(test1) << " " << findComponent(test2) << " " << findComponent(test3) << endl;
    
}
