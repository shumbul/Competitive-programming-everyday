// Link - https://practice.geeksforgeeks.org/problems/trie-insert-and-search0651/1#
// Author - Shumbul Arifa

// trie node
struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];

	// isEndOfWord is true if the node represents
	// end of a word
	bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
	struct TrieNode *pNode =  new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
	// code here
	struct TrieNode *node = root;
	for (int i = 0; i < key.length(); i++) {
		int ele = key[i] - 'a';
		if (!node->children[ele])
			node->children[ele] = getNode();
		node = node -> children[ele];
	}
	node->isLeaf = 1;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key)
{
	// code here
	struct TrieNode *node = root;
	for (int i = 0; i < key.length(); i++) {
		int ele = key[i] - 'a';
		if (!node->children[ele])
			return false;
		node = node -> children[ele];
	}
	return node != NULL && node->isLeaf;
}