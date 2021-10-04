// Link - https://leetcode.com/problems/design-browser-history/
// Author - Shumbul Arifa

class Node {
public:
	string val;
	Node* prev;
	Node* next;
	Node(): val("-1"), next(nullptr), prev(nullptr) {}
	Node(string s): val(s), next(nullptr), prev(nullptr) {}
};

class BrowserHistory {
	// we will try with doubly LL
	Node* head;
	Node* tmp;
public:
	BrowserHistory(string homepage) {
		head = new Node(homepage);
		tmp = head;
	}

	void visit(string url) {
		tmp->next = new Node(url);
		auto t = tmp;
		tmp = tmp->next;
		tmp->prev = t;
	}

	string back(int steps) {
		while (steps-- && tmp->prev) {
			tmp = tmp->prev;
		}
		return tmp->val;
	}

	string forward(int steps) {
		while (steps-- && tmp->next) {
			tmp = tmp->next;
		}
		return tmp->val;
	}
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */