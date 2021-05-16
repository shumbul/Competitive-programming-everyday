// Link - https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array
// Link - https://practice.geeksforgeeks.org/problems/maximum-xor-of-two-numbers-in-an-array/1
// Author - Shumbul Arifa

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
ll power(ll a, ll n) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a;} n >>= 1; a *= a;} return p;}
const int mod = 1e9 + 7;

class trieNode {
public:
	trieNode* left; // (0)
	trieNode* right; // (1)
};

void insert(int val, trieNode* root) {
	trieNode* curr = root;
	for (int i = 31; i >= 0; i--) {
		int b = (val >> i) & 1;
		if (b == 0) {
			if (!curr->left) {
				curr->left = new trieNode();
			}
			curr = curr->left;
		}
		else {
			if (!curr->right) {
				curr->right = new trieNode();
			}
			curr = curr->right;
		}
	}
}

int findMaxXorPair(trieNode* root, int *arr, int n) {
	if (n < 2)
		return 0;
	int max_xor = INT_MIN;
	for (int i = 0; i < n; i++) {
		trieNode* curr = root;
		int val = arr[i];
		int curr_xor = 0;
		for (int j = 31; j >= 0; j--) {
			int b = (val >> j) & 1;
			if (b == 0) {
				if (curr->right) {
					curr_xor += power(2, j);
					curr = curr->right;
				}
				else
					curr = curr->left;
			}
			else {
				if (curr->left) {
					curr_xor += power(2, j);
					curr = curr->left;
				}
				else
					curr = curr->right;
			}
		}
		if (curr_xor > max_xor)
			max_xor = curr_xor;
	}
	return max_xor;
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[6] = {8, 1, 2, 15, 10, 5};
	trieNode* root = new trieNode();
	for0(i, 6) {
		insert(arr[i], root);
	}
	cout << findMaxXorPair(root, arr, 6);

	return 0;
}