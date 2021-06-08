// Link - https://leetcode.com/problems/implement-trie-prefix-tree/
// Author - Shumbul Arifa

/* METHOD -1: using array */
class TrieNode {
public:
	// Initialize your data structure here.
	bool eow;
	TrieNode *children[26];

	TrieNode() {
		eow = false;

		for (int i = 0; i < 26; i++)
			children[i] = NULL;
	}
};
class Trie {
	TrieNode* root;
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* tmp = root;
		int n = word.length();
		for (int i = 0; i < n; i++) {
			if (tmp->children[word[i] - 'a'] == NULL) {
				tmp->children[word[i] - 'a'] = new TrieNode();
			}
			tmp = tmp -> children[word[i] - 'a'];
		}
		tmp->eow = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* tmp = root;
		int n = word.length();
		for (int i = 0; i < n; i++) {
			if (tmp->children[word[i] - 'a'] == NULL) {
				return false;
			}
			tmp = tmp -> children[word[i] - 'a'];
		}
		return tmp->eow;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string word) {
		TrieNode* tmp = root;
		int n = word.length();
		for (int i = 0; i < n; i++) {
			if (tmp->children[word[i] - 'a'] == NULL) {
				return false;
			}
			tmp = tmp -> children[word[i] - 'a'];
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */



/* Method -2: using map */
class Trie {
	map<char, Trie*> children = {};
	bool eow = false;
public:
	/** Initialize your data structure here. */
	Trie() {}

	/** Inserts a word into the trie. */
	void insert(string word) {
		if (word == "")
			return;
		Trie *tmp = this;
		for (char c : word) {
			if (tmp->children.find(c) == tmp->children.end())
				(tmp->children)[c] = new Trie();
			tmp = (tmp->children)[c];
		}
		tmp->eow = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		if (word == "")
			return 1;
		Trie *tmp = this;
		for (char c : word) {
			if ((tmp->children).find(c) == (tmp->children).end())
				return false;
			tmp = (tmp->children)[c];
		}
		return tmp->eow;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string word) {
		if (word == "")
			return 1;
		Trie *tmp = this;
		for (char c : word) {
			if ((tmp->children).find(c) == (tmp->children).end())
				return false;
			tmp = (tmp->children)[c];
		}
		return 1;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/* Method -3: using map, but different class */
class TrieNode {
public:
	map<char, TrieNode*> children = {};
	bool eow = false;
};

class Trie {
	TrieNode* root = new TrieNode;
public:
	/** Initialize your data structure here. */
	Trie() {}

	/** Inserts a word into the trie. */
	void insert(string word) {
		if (word == "")
			return;
		TrieNode *tmp = root;
		for (char c : word) {
			if (tmp->children.find(c) == tmp->children.end())
				(tmp->children)[c] = new TrieNode();
			tmp = (tmp->children)[c];
		}
		tmp->eow = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		if (word == "")
			return 1;
		TrieNode *tmp = root;
		for (char c : word) {
			if ((tmp->children).find(c) == (tmp->children).end())
				return false;
			tmp = (tmp->children)[c];
		}
		return tmp->eow;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string word) {
		if (word == "")
			return 1;
		TrieNode *tmp = root;
		for (char c : word) {
			if ((tmp->children).find(c) == (tmp->children).end())
				return false;
			tmp = (tmp->children)[c];
		}
		return 1;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */