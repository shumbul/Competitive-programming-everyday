// Link - https://leetcode.com/problems/add-two-numbers-ii/
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> s1, s2;
		ListNode* tmp = l1, *head = NULL;
		while (tmp) {
			s1.push(tmp->val);
			tmp = tmp->next;
		}
		tmp = l2;
		while (tmp) {
			s2.push(tmp->val);
			tmp = tmp->next;
		}
		int carry = 0, v1, v2;
		while (!s1.empty() || !s2.empty() || carry) {
			if (s1.empty())
				v1 = 0;
			else {
				v1 = s1.top();
				s1.pop();
			}
			if (s2.empty())
				v2 = 0;
			else {
				v2 = s2.top();
				s2.pop();
			}
			// cout<<v1<<" "<<v2<<" "<<carry<<"\n";
			int val = v1 + v2 + carry;
			tmp = new ListNode((val) % 10);
			if (val > 9)
				carry = 1;
			else carry = 0;

			tmp->next = head;
			head = tmp;
		}
		return head;
	}
};