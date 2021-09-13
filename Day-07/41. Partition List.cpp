// Link - https://leetcode.com/problems/partition-list/
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
	ListNode* partition(ListNode* head, int x) {
		if (!head)
			return head;
		ListNode* l1 = new ListNode(0), *l2 = new ListNode(0);
		auto t1 = l1;
		auto t2 = l2;
		if (!l1 || !l2)
			return head;
		while (head) {
			// cout<<head->val<<"\n";
			if (head->val < x) {
				t1->next = head;
				t1 = t1->next;
			}
			else {
				t2->next = head;
				t2 = t2->next;
			}
			head = head->next;
		}
		t1->next = NULL;
		t2->next = NULL;
		t1->next = l2->next;
		return l1->next;
	}
};