// Link - https://leetcode.com/problems/intersection-of-two-linked-lists/
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
		set<ListNode*> st;
		auto t = headA;
		while (t) {
			st.insert(t);
			t = t->next;
		}
		t = headB;
		while (t) {
			if (st.find(t) != st.end())
				return t;
			t = t->next;
		}
		return nullptr;
	}
};