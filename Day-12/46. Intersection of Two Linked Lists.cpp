// Link - https://leetcode.com/explore/featured/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3660/
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		auto temp = headA;
		while (temp) {
			temp->val = temp->val * -1;
			temp = temp->next;
		}
		temp = headB;
		while (temp) {
			if (temp->val < 0) {
				goto over;
			}
			temp = temp->next;
		}
over:
		auto t = headA;
		while (t) {
			t->val = t->val * -1;
			t = t->next;
		}
		return temp;
	}
};