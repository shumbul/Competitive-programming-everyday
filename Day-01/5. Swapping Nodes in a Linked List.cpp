// Link - https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
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
	int K;
	ListNode* tmp;
	void solve(ListNode* head) {
		if (!head || !K)
			return;
		if (head->next)
			solve(head->next);
		--K;
		if (!K) {
			int t = head->val;
			head->val = tmp->val;
			tmp->val = t;
		}
	}
public:
	ListNode* swapNodes(ListNode* head, int k) {
		K = k;
		tmp = head;
		while (--K) {
			tmp = tmp->next;
		}
		K = k;
		solve(head);
		return head;
	}
};