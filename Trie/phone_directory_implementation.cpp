#include <bits/stdc++.h>
using namespace std;







// Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. 
// The task is to implement a search query for the phone directory. 
// Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that 
// prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. 
// Please refer the explanation part for better understanding.

// Note: If there is no match between query and contacts, print "0".

// Example 1:

// Input: 
// n = 3
// contact[] = {"geeikistest", "geeksforgeeks", 
// "geeksfortest"}
// s = "geeips"
// Output:
// geeikistest geeksforgeeks geeksfortest
// geeikistest geeksforgeeks geeksfortest
// geeikistest geeksforgeeks geeksfortest
// geeikistest
// 0
// 0
// Explaination: By running the search query on 
// contact list for "g" we get: "geeikistest", 
// "geeksforgeeks" and "geeksfortest".
// By running the search query on contact list 
// for "ge" we get: "geeikistest" "geeksforgeeks"
// and "geeksfortest".
// By running the search query on contact list 
// for "gee" we get: "geeikistest" "geeksforgeeks"
// and "geeksfortest".
// By running the search query on contact list 
// for "geei" we get: "geeikistest".
// No results found for "geeip", so print "0". 
// No results found for "geeips", so print "0".
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function displayContacts() which takes n, contact[ ] and s as input parameters and returns a list of list of strings for required prefixes. If some prefix has no matching contact return "0" on that list.

// Expected Time Complexity: O(|s| * n * max|contact[i]|)
// Expected Auxiliary Space: O(n * max|contact[i]|)

// Constraints:
// 1 ≤ T ≤ 100, T = number of test cases
// 1 ≤ n ≤ 50
// 1 ≤ |contact[i]| ≤ 50
// 1 ≤ |s| ≤ 6 









class TrieNode{
    public:
    char data;
    TrieNode* children[26] = {NULL};
    bool isTerminal = false;

    TrieNode(char data){
        this -> data = data;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string s){
        if(s.size() == 0){
            root -> isTerminal = true;
        }

        //index
        int index = s[0] - 'a';
        if(root -> children[index] == NULL){
            root -> children[index] = new TrieNode(s[0]);
        }

        insertUtil(root -> children[index], s.substr(1));
    }

    void insert(string s){
        insertUtil(root, s);
    }

    void solution(vector<string> &suggestions, string prefix, TrieNode* root){
        if(root == NULL){
            return;
        }

        prefix += root -> data;
        if(root -> isTerminal) suggestions.push_back(prefix);
        for(int i = 0; i < 26; i++){
            if(root -> children[i]){
                solution(suggestions, prefix, root -> children[i]);
            }
        }
    }

    vector<vector<string>> getSuggestions(vector<string> str_list, string s){

        vector<vector<string>> ans;

        Trie* t1 = new Trie();
        //insert all the string to Trie
        for(int i = 0; i < str_list.size(); i++){
            t1 -> insert(str_list[i]);
        }

        vector<string> suggestions;
        string prefix = "";
        TrieNode* prevNode = root;

        for(int i = 0; i < s.size(); i++){
            prevNode = prevNode -> children[s[i] - 'a'];
            if(prevNode != NULL){
                solution(suggestions, prefix, prevNode);
                ans.push_back(suggestions);
            }
            else{
                for(int j = i; j < s.size(); j++){
                    ans.push_back({"0"});
                }
                break;
            }
            prefix += s[i];
            suggestions.clear();
        }
        
        return ans;
    }
};

int main() {


return 0;
}