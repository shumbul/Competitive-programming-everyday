// Link - https://leetcode.com/problems/delete-node-in-a-linked-list/
// Author - Shumbul Arifa

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	void deleteNode(ListNode* node) {
		// change val instead
		auto prev = node;
		while (node->next) {
			prev = node;
			node->val = node->next->val;
			node = node->next;
		}
		prev->next = nullptr;
	}
};