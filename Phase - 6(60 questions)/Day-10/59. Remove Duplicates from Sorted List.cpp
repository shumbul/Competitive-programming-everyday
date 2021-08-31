// Link - https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head)
			return head;
		auto curr = head;
		while (curr && curr->next) {
			auto b = curr->next;
			while (b && curr->val == b->val) {
				b = b->next;
			}
			curr->next = b;
			curr = curr->next;
		}
		return head;
	}
};