// Link - https://leetcode.com/problems/middle-of-the-linked-list/
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
	ListNode* middleNode(ListNode* head) {
		auto fast = head;
		auto slow = head;
		while (fast && fast->next && slow) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
};