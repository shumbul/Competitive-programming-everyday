// Link -https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3693/
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
	ListNode* tmp;
	bool res;

	void rec(ListNode* head) {
		if (!head || res == 0)
			return;
		if (head->next && tmp != head->next)
			rec(head->next);
		if (tmp->val != head->val)
			res = 0;
		tmp = tmp->next;
	}
public:
	bool isPalindrome(ListNode* head) {
		tmp = head;
		res = 1;
		rec(head);
		return res;
	}
};