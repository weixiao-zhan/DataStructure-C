#include<iostream>
#include<string>
using namespace std; 
const int ALPHABET_SIZE = 26; 

// trie node
typedef struct trienode{
    string key;
    int children_num;
    struct trienode* children[ALPHABET_SIZE]; 
    bool isEndOfWord; // isEndOfWord is true if the node represents end of a word 
}TrieNode; 

class Trie{
private:
    TrieNode* root;
    TrieNode* initNode(); 
public:
    Trie();
    bool isCompressed;
    void insert(string str); // Returns new trie node (initialized to NULLs) 
    bool search(string str);
    void compress();
};

Trie::Trie(){
    root = new TrieNode;
    root->isEndOfWord = false;
    root->key = "";
}

TrieNode* Trie::initNode() {
TrieNode* pNode =  new TrieNode; 
    pNode->isEndOfWord = false; 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL;
    pNode->children_num = 0;
    return pNode; 
} 

// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void Trie::insert(string str){
    if(isCompressed){
        perror("Insert to compressed trie");
        return;
    }
    TrieNode* temp = Trie::root;
    for (int i = 0; i < str.length(); i++) 
    {
        int index = str[i] - 'a'; 
        if (!temp->children[index])
            temp->key = str[i];
            temp->children[index] = initNode();
        temp = temp->children[index]; 
    }
    // mark last node as leaf 
    temp->isEndOfWord = true; 
}
  
// Returns true if key presents in trie, else 
// false 
bool Trie::search(string key){ 
    TrieNode* temp = Trie::root; 
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!temp->children[index]) 
            return false; 
  
        temp = temp->children[index]; 
    } 
  
    return (temp != NULL && temp->isEndOfWord); 
} 
  
// Driver 
int main() 
{ 
    // Input keys (use only 'a' through 'z' 
    // and lower case) 
    string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
  
    Trie trie; 
  
    // Construct trie
    for (int i = 0; i < n; i++){
        trie.insert(keys[i]); 
    }
    // Search for different keys 
    trie.search("the")?   cout << "Yes\n" : cout << "No\n"; 
    trie.search("these")? cout << "Yes\n" : cout << "No\n"; 
    return 0; 
} 