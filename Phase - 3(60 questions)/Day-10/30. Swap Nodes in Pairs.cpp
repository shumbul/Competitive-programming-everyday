// Link - https://leetcode.com/problems/swap-nodes-in-pairs/
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
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next)
			return head;
		auto tmp = head;
		int odd, even;
		while (tmp && tmp->next) {
			odd = tmp->val;
			even = tmp->next->val;
			tmp->val = even;
			tmp->next->val = odd;
			tmp = tmp->next->next;
		}
		return head;
	}
};