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
	bool res;

	void rec(ListNode* head) {
		// base case: result is already false, or head is nullptr
		if (!head || res == 0)
			return;
		// until head reaches the last node
		if (head->next && tmp != head->next)
			rec(head->next);
		if (tmp->val != head->val)
			res = 0;
		// tmp increments while head decrements recursively
		tmp = tmp->next;
	}
public:
	bool isPalindrome(ListNode* head) {
		tmp = head;
		res = 1;
		// recursive approach
		rec(head);
		return res;
	}
};

/*
Another approach is to reverse 1st half, and then use 2 pointers
SUCH THAT:
head1 points to head, head2 points to mid (careful with odd and even leangth of LL condition)

Then, traversing till head1 reaches mid of LL.
In case at any point in this traversal, head1->val!=head2->val => return false
else return true
*/