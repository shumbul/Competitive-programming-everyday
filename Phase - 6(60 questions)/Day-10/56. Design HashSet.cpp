// Link - https://leetcode.com/problems/design-hashset/
// Author - Shumbul Arifa



class MyHashSet {
public:
	/** Initialize your data structure here. */
	ListNode* head = new ListNode(-1);
	ListNode* tmp = head;
	MyHashSet() {
		head = new ListNode(-1);
		tmp = head;
	}

	void add(int key) {
		if (!contains(key)) {
			tmp->next = new ListNode(key);
			tmp = tmp->next;
		}
	}

	void remove(int key) {
		ListNode* t = head, *prev = nullptr;
		if (!t)
			return;
		if (t->val == key) {
			if (tmp == head)
				tmp = tmp->next;
			head = head->next;
		}
		while (t) {
			if (t->val == key) {
				if (tmp == t)
					tmp = prev;
				if (prev)
					prev->next = t->next;
			}
			prev = t;
			t = t->next;
		}
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		ListNode* t = head;
		while (t) {
			if (t->val == key) {
				return 1;
			}
			t = t->next;
		}
		return 0;
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */