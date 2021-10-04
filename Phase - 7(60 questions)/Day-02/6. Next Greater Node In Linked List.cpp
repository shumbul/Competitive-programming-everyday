// Link - https://leetcode.com/problems/next-greater-node-in-linked-list/
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
	vector<int> ans;
	void solve(ListNode* head, stack<int>& st) {
		if (!head)
			return;
		if (head->next) {
			solve(head->next, st);
		}
		while (!st.empty() && st.top() <= head->val)
			st.pop();
		if (!st.empty()) {
			ans.push_back(st.top());
		}
		else
			ans.push_back(0);
		st.push(head->val);
	}
public:
	vector<int> nextLargerNodes(ListNode* head) {
		stack<int> st;
		ans.clear();
		solve(head, st);
		reverse(ans.begin(), ans.end());
		return ans;
	}
};