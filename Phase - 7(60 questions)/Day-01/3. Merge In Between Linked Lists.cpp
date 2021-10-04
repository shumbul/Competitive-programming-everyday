// Link - https://leetcode.com/problems/merge-in-between-linked-lists/
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
	ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
		auto tmp = list1;
		ListNode *c, *d;
		b -= a;
		while (--a) {
			tmp = tmp->next;
		}
		c = tmp->next;
		tmp->next = list2;
		tmp = tmp->next;
		while (b--) {
			c = c->next;
		}
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = c->next;
		c->next = NULL;
		return list1;
	}
};