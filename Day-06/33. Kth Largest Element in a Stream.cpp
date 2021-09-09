// Link - https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Author - Shumbul Arifa

class KthLargest {
	priority_queue<int, vector<int>, greater<int>> pq;
	int K;
public:
	KthLargest(int k, vector<int>& nums) {
		K = k;
		for (int i : nums) {
			pq.push(i);
		}
		while (pq.size() > k)
			pq.pop();
	}

	int add(int val) {
		pq.push(val);
		if (pq.size() > K)
			pq.pop();
		return pq.top();
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */