// Link - https://leetcode.com/problems/remove-linked-list-elements/
// Author - Shumbul Arifa

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
	ListNode * newhead = new ListNode();
	void solve(ListNode* head, ListNode* prev, int val) {
		if (!head)
			return;
		if (head->val == val) {
			prev->next = head->next;
			solve(head->next, prev, val);
		}
		else
			solve(head->next, head, val);
	}
public:
	ListNode* removeElements(ListNode* head, int val) {
		newhead->next = head;
		solve(head, newhead, val);
		return newhead->next;
	}
};