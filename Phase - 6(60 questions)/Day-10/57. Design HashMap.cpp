// Link - https://leetcode.com/problems/design-hashmap/
// Author - Shumbul Arifa

struct Node {
	int key;
	int val;
	Node *next;
	Node() : key(-1), val(-1), next(nullptr) {}
	Node(int x, int y) : key(x), val(y), next(nullptr) {}
};

class MyHashMap {
public:
	/** Initialize your data structure here. */
	Node* head = new Node();
	Node* tmp = head;
	MyHashMap() {
		head = new Node();
		tmp = head;
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
		if (get(key) == -1) {
			tmp->next = new Node(key, value);
			tmp = tmp->next;
		}
		else {
			// change
			Node* t = head;
			while (t) {
				if (t->key == key) {
					t->val = value;
					return;
				}
				t = t->next;
			}
		}
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		Node* t = head;
		while (t) {
			if (t->key == key) {
				return t->val;
			}
			t = t->next;
		}
		return -1;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		Node* t = head, *prev = nullptr;
		if (!t)
			return;
		if (t->key == key) {
			if (tmp == head)
				tmp = tmp->next;
			head = head->next;
		}
		while (t) {
			if (t->key == key) {
				if (tmp == t)
					tmp = prev;
				if (prev)
					prev->next = t->next;
			}
			prev = t;
			t = t->next;
		}
	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */