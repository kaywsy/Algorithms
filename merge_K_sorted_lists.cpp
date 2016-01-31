//merge k sorted lists
//merge k sorted linked lists and return it as one sorted lists

//method1: priority queue(heap)
//use a min heap, pust the smallest node of each list into the heap
//once pop this node, push the next node of the same list into the queue
//size of heap: k
//each push: logk
//nk node in total, time: O(nklogk), space: O(k)

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this -> val = val;
		this -> next = NULL;
	}
};

struct myCompare {
	bool operator() (ListNode* a, ListNode* b) const{
		return a -> val > b -> val;
	}
};

ListNode* mergeKLists1(vector<ListNode*> &lists) {
	priority_queue<ListNode*, vector<ListNode*>, myCompare> heap;
	ListNode* dummy = new ListNode(0), *tail = dummy;
	for (int i = 0; i < lists.size(); ++i) {
		if (lists[i]) heap.push(lists[i]);
	}
	while (!heap.empty()) {
		tail -> next = heap.top();
		heap.pop();
		tail = tail -> next;
		if (tail -> next) heap.push(tail -> next);
	}
	return dummy -> next;
}

//method2: devide & conquer
//recursion or iteration
//time: O(nklogk), space: iterative O(1)
ListNode* mergeKLists2(vector<ListNode*> &lists) {
	if (lists.size() == 0) return NULL;
	    int r = lists.size() - 1;
	    while (r > 0) {
	        int l = 0;
	        while (l < r) {
    		    lists[l] = merge2Lists(lists[l], lists[r]);
    		    l++;
    		    r--;
	        }
	    }
	    return lists[0];
}

ListNode* merge2Lists(ListNode* a, ListNode* b) {
	ListNode* dummy = new ListNode(0), *tail = dummy;
	while (a && b) {
		if (a -> val < b -> val) {
			tail -> next = a;
			a = a -> next;
		} else {
			tail -> next = b;
			b = b -> next;
		}
		tail = tail -> next;
	}
	tail -> next = a ? a : b;
	return dummy -> next;
}
