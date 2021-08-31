// Link - https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
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
	int ans;
	void solve(ListNode* head, int &pos) {
		if (!head)
			return;
		solve(head->next, pos);
		// cout<<pos<<" ";
		ans = ans + (pow(2, pos)) * (head->val);
		// cout<<ans<<"\n";
		pos++;
	}
public:
	int getDecimalValue(ListNode* head) {
		ans = 0;
		int pos = 0;
		solve(head, pos);
		return ans;
	}
};