#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {

public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
    void insertUtil(TrieNode *root, string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }
    void insert(string word)
    { insertUtil(root, word); }


    void lcp(string str, string &ans){
        for(int i= 0; i < str.length(); i++){
            char ch = str[i];
            if(root->childCount == 1){
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }else{
                break;
            }
            if(root->isTerminal){
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n) {
    Trie* obj = new Trie();
    for(int i = 0; i < n; i++){
        obj->insert(arr[i]);
    }
    string first = arr[0], ans;
    obj->lcp(first, ans);
    return ans;
}




// string longestCommonPrefix(vector<string> &arr, int n)
// {
//     string ans;
//     bool match = true;
//     for(int i =0 ; i < arr[0].length(); i++){
//         char ch = arr[0][i];
//         for(int j = 1; j < n; j++){
//             if(ch != arr[j][i]){
//                 match = false;
//                 break;
//             }
//         }
//         if(match){
//             ans.push_back(ch);
//         }else{
//             break;
//         }
//     }
//     return ans;
// }


