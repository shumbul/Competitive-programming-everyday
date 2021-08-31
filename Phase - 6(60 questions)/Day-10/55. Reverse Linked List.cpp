// Link - https://leetcode.com/problems/reverse-linked-list/
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
	ListNode* newhead;
	void solve(ListNode* head, ListNode* prev = nullptr) {
		if (!head)
			return;
		if (!head->next)
			newhead = head;
		solve(head->next, head);
		head->next = prev;
	}
public:
	ListNode* reverseList(ListNode* head) {
		solve(head);
		return newhead;
	}
};