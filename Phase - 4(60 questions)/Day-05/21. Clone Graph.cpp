// Link - https://leetcode.com/problems/clone-graph/
// Author - Shumbul Arifa

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// dfs
class Solution {
	unordered_map<Node*, Node*> copy;
public:
	Node* cloneGraph(Node* node) {
		if (!node)
			return NULL;
		if (copy.find(node) == copy.end()) {
			copy[node] = new Node(node->val, {});
			for (auto n : node->neighbors) {
				copy[node]->neighbors.push_back(cloneGraph(n));
			}
		}
		return copy[node];
	}
};

// bfs
class Solution {
	unordered_map<Node*, Node*> copy;
public:
	Node* cloneGraph(Node* node) {
		if (!node)
			return NULL;
		queue<Node*> q;
		q.push(node);
		copy[node] = new Node(node->val);
		while (!q.empty()) {
			auto top = q.front();
			q.pop();
			for (auto n : top->neighbors) {
				if (copy.find(n) == copy.end()) {
					copy[n] = new Node(n->val);
					q.push(n);
				}
				copy[top]->neighbors.push_back(copy[n]);
			}
		}
		return copy[node];
	}
};