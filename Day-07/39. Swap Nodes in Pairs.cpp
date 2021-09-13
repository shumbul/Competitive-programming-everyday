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
		auto tmp = head;
		while (tmp && tmp->next) {
			int t = tmp->val;
			tmp->val = tmp->next->val;
			tmp->next->val = t;
			tmp = tmp->next->next;
		}
		return head;
	}
};