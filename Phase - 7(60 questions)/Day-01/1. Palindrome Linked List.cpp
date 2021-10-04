// Link - https://leetcode.com/problems/palindrome-linked-list/
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
	ListNode* tmp;
	bool ans;
	bool solve(ListNode* head) {
		if (!head) {
			return 1;
		}
		if (!ans)
			return 0;
		// cout<<head->val<<tmp->val<<"\n";
		if (head->next)
			ans = ans && solve(head->next);
		ans = ans && tmp->val == head->val;
		tmp = tmp->next;
		return ans;
	}
public:
	bool isPalindrome(ListNode* head) {
		tmp = head;
		ans = 1;
		bool res = solve(head);
		return ans;
	}
};