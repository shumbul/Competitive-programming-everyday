// Link - https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Author - Shumbul Arifa

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
	Node* solve(Node* head) {
		auto res = head;
		while (head) {
			if (head->child) {
				auto t = solve(head->child);
				auto nxt = head->next;
				head->next = head->child;
				head->child->prev = head;
				head->child = nullptr;
				t->next = nxt;
				if (nxt)
					nxt->prev = t;
				head = nxt;
				res = t;
			}
			else {
				res = head;
				head = head->next;
			}
		}
		return res;
	}
public:
	Node* flatten(Node* head) {
		if (!head)
			return head;
		solve(head);
		return head;
	}
};