// Link - https://leetcode.com/problems/add-two-numbers/
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		auto a1 = l1, a2 = l2;
		ListNode* head = new ListNode(0);
		auto tmp = head;
		int sum = 0;
		while (a1 != NULL || a2 != NULL) {
			sum /= 10;
			if (a1) {
				sum += a1->val;
				a1 = a1->next;
			}
			if (a2) {
				sum += a2->val;
				a2 = a2->next;
			}
			tmp->next = new ListNode(sum % 10);
			tmp = tmp->next;
		}
		if (sum / 10) {
			tmp->next = new ListNode(sum / 10);
		}
		return head->next;
	}
};