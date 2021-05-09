// Link - https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list
// Author - Shumbul Arifa

class Solution
{
public:
	//Function to remove a loop in the linked list.
	void removeLoop(Node* head)
	{
		// code here
		// just remove the loop without losing any nodes
		bool loop = 0;
		auto fast = head, slow = head;
		while (fast && slow && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				loop = 1;
				break;
			}
		}
		if (!loop)
			return;
		// otherwise, loop detected!

		auto another = head;
		while (slow != another) {
			slow = slow->next;
			another = another->next;
		}

		while (another->next != slow) {
			another = another->next;
		}
		another->next = NULL;

	}
};