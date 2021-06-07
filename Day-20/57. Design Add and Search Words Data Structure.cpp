// Link - https://leetcode.com/problems/design-add-and-search-words-data-structure/
// Author - Shumbul Arifa

class Trie {
public:
	Trie* children[26];
	bool eow;

	Trie() {
		eow = false;
		for (int i = 0; i < 26; i++)
			children[i] = NULL;
	}
};
class WordDictionary {
	Trie* root = new Trie();
	bool search_node(string word, int pos, Trie* tmp) {
		for (int i = pos; i < word.length() && tmp; i++) {
			char c = word[i];
			if (c != '.') {
				tmp = tmp->children[c - 'a'];
			}
			else {
				for (int j = 0; j < 26; j++) {
					Trie* node = tmp->children[j];
					if (search_node(word, i + 1, node))
						return true;
				}
				return false;
			}
		}
		return tmp && tmp->eow;
	}
public:
	/** Initialize your data structure here. */
	WordDictionary() {}

	void addWord(string word) {
		Trie* tmp = root;
		for (char c : word) {
			if (tmp->children[c - 'a'] == NULL) {
				tmp->children[c - 'a'] = new Trie();
			}
			tmp = tmp -> children[c - 'a'];
		}
		tmp->eow = 1;
	}

	bool search(string word) {
		Trie* tmp = root;
		return search_node(word, 0, tmp);
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */