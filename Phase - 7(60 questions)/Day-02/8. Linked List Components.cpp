// Link - https://leetcode.com/problems/linked-list-components/
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
	set<int> st;
	void check(ListNode* head, int &c) {
		if (!head)
			return;
		if (!head->next && (st.find(head->val) != st.end() || c)) {
			ans++;
			return;
		}
		if (st.find(head->val) == st.end() && c) {
			ans++;
			c = 0;
		}
		else if (st.find(head->val) != st.end())
			c++;
		check(head->next, c);
	}
public:
	int numComponents(ListNode* head, vector<int>& nums) {
		ans = 0;
		st.clear();
		for (auto a : nums)
			st.insert(a);
		int c;
		check(head, c);
		return ans;
	}
};