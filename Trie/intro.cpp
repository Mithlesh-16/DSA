#include <iostream>
using namespace std;

class TrieNode{

    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char data){
        this -> data = data;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        this -> root = new TrieNode('\0');
    }

    void insertWord(TrieNode* root, string word){
        if(word.size() == 0){
            root -> isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        if(root -> children[index] == NULL){
            root -> children[index] = new TrieNode(word[0]);
        }

        //recursion
        insertWord(root -> children[index], word.substr(1));

    }

    bool searchWord(TrieNode* root, string word){
        if(word.size() == 0){
            return root -> isTerminal;
        }

        int index = word[0] - 'a';
        if(root -> children[index]){
          return searchWord(root -> children[index], word.substr(1));
        }
        return false;
    }

    void removeWord(TrieNode* root, string word){
        if(word.size() == 0){
            root -> isTerminal = false;
            return;
        }

        int index = word[0] - 'a';
        if(root -> children[index]){
            removeWord(root -> children[index], word.substr(1));
            return ;
        }else return ;

    }

};

int main(){
    Trie* t1 = new Trie();
    t1 -> insertWord(t1 -> root, "abcd");
    t1 -> insertWord(t1 ->  root, "mithlesh");
    t1 -> insertWord(t1 ->  root, "ramesh");
    t1 -> insertWord(t1 ->  root, "rameshwaram");
    t1 -> insertWord(t1 ->  root, "time");
    t1 -> insertWord(t1 ->  root, "tim");

    cout<<t1 -> searchWord(t1 -> root, "abcd");
    cout<<endl;
    cout<<t1 -> searchWord(t1 -> root, "abcde");
    cout<<endl;
    cout<<t1 -> searchWord(t1 -> root, "mithilesh");
    cout<<endl;
    cout<<t1 -> searchWord(t1 -> root, "mithlesh");
    cout<<endl;
    cout<<t1 -> searchWord(t1 -> root, "ramesh");
    cout<<endl;
    cout<<t1 -> searchWord(t1 -> root, "raushan");
    cout<<endl;
    cout<<t1 -> searchWord(t1 -> root, "rameshwaram");
    cout<<endl;
    cout<<t1 -> searchWord(t1 -> root, "time");
    cout<<endl;
    cout<<t1 -> searchWord(t1 -> root, "tim");
    cout<<endl;
    cout<<t1 -> searchWord(t1 -> root, "ti");

    t1 -> removeWord(t1 -> root, "abcd");
    t1 -> removeWord(t1 -> root, "abcde");
    t1 -> removeWord(t1 -> root, "mithlesh");

    cout<<t1 -> searchWord(t1 -> root, "mithlesh");
    cout<<endl;
    cout<<t1 -> searchWord(t1 -> root, "abcd");
    cout<<endl;


}