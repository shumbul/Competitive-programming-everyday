// Link - https://leetcode.com/problems/linked-list-cycle/
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
	bool hasCycle(ListNode *head) {
		if (head == NULL)   return 0;
		ListNode* fptr, * sptr;
		fptr = sptr = head;
		while (fptr && (sptr && fptr->next)) {
			sptr = sptr->next;
			fptr = fptr->next->next;
			if (fptr == sptr) {
				return 1;
			}
		}
		return 0;
	}
};