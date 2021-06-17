// Link - https://leetcode.com/problems/odd-even-linked-list/submissions/
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
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr) return head;
		ListNode* oddHead = head;
		ListNode* evenHead = head->next, *even = evenHead;
		while (evenHead != NULL && evenHead->next != NULL) {
			oddHead->next = evenHead->next;
			oddHead = oddHead->next;
			evenHead->next = oddHead->next;
			evenHead = evenHead->next;
		}
		oddHead->next = even;
		return head;
	}
};