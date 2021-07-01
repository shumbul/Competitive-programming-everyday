// Link - https://leetcode.com/problems/rotate-list/submissions/
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
	ListNode* root;
	void solve(ListNode* head, int k) {
		auto tmp = head;
		for (int i = 1; i < k; i++) {
			tmp = tmp->next;
		}
		if (tmp->next == NULL)
			return;
		root = tmp->next;
		tmp->next = NULL;
		tmp = root;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = head;
	}
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == NULL)
			return head;
		int len = 0;
		auto tmp = head;
		while (tmp != NULL) {
			len++;
			tmp = tmp->next;
		}
		k = k % len;
		root = head;
		solve(head, len - k);
		return root;
	}
};