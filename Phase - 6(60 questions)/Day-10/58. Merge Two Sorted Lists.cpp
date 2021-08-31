// Link - https://leetcode.com/problems/merge-two-sorted-lists/
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		// iteratively
		ListNode* nn = new ListNode();
		ListNode* tmp = nn;
		while (l1 && l2) {
			if (l1->val <= l2->val) {
				tmp->next = l1;
				tmp = tmp->next;
				l1 = l1->next;
			}
			else {
				tmp->next = l2;
				tmp = tmp->next;
				l2 = l2->next;
			}
		}
		if (l1)
			tmp->next = l1;
		else if (l2)
			tmp->next = l2;
		return nn->next;
	}
};