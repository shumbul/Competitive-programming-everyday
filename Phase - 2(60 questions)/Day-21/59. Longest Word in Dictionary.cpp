// Link - https://leetcode.com/problems/longest-word-in-dictionary/
// Author - Shumbul Arifa

class Trie {
public:
	Trie* children[26];
	bool eow;

	// constructer
	Trie() {
		eow = false;
		for (int i = 0; i < 26; i++)
			children[i] = NULL;
	}
	// destructer
	~Trie() {
		Trie* root = new Trie();
		delTree(root);
	}
	void delTree( Trie *root )
	{
		for ( int i = 0; i < 26; ++i ) {
			if ( root->children[i] ) {
				delTree( root->children[i] );
			}
		}
		free( root );
	}
};

class Solution {
	Trie* root = new Trie();
	string anss;
public:
	void insert(string word) {
		Trie* tmp = root;
		bool out = false;
		for (int i = 0; i < word.length(); i++) {
			if ((tmp->children)[word[i] - 'a'] == NULL) {
				(tmp->children)[word[i] - 'a'] = new Trie();
			}
			tmp = (tmp->children)[word[i] - 'a'];
			if (tmp->eow == false)
				out = true;
			if (i == word.length() - 2 && anss.length() < word.length() && !out) {
				anss = word;
			}
		}
		tmp->eow = 1;
	}
	string longestWord(vector<string>& Words) {
		auto words = Words;
		if (words.size() < 1)
			return "";
		sort(words.begin(), words.end(), [](const auto & s1, const auto & s2) {
			if (s1.length() != s2.length())
				return s1.length() < s2.length();
			return s1 < s2;
		});
		if (words[0].length() > 1)
			return "";
		for (string s : words)
			insert(s);
		if (anss.length() == 0 && words[0].length() == 1)
			return words[0];
		return anss;
	}
};

// JAVA Editorial Solution
// trie with dfs
class Solution {
	public String longestWord(String[] words) {
		Trie trie = new Trie();
		int index = 0;
		for (String word : words) {
			trie.insert(word, ++index); //indexed by 1
		}
		trie.words = words;
		return trie.dfs();
	}
}
class Node {
	char c;
	HashMap<Character, Node> children = new HashMap();
	int end;
	public Node(char c) {
		this.c = c;
	}
}

class Trie {
	Node root;
	String[] words;
	public Trie() {
		root = new Node('0');
	}

	public void insert(String word, int index) {
		Node cur = root;
		for (char c : word.toCharArray()) {
			cur.children.putIfAbsent(c, new Node(c));
			cur = cur.children.get(c);
		}
		cur.end = index;
	}

	public String dfs() {
		String ans = "";
		Stack<Node> stack = new Stack();
		stack.push(root);
		while (!stack.empty()) {
			Node node = stack.pop();
			if (node.end > 0 || node == root) {
				if (node != root) {
					String word = words[node.end - 1];
					if (word.length() > ans.length() ||
					        word.length() == ans.length() && word.compareTo(ans) < 0) {
						ans = word;
					}
				}
				for (Node nei : node.children.values()) {
					stack.push(nei);
				}
			}
		}
		return ans;
	}
}