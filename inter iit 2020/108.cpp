//SEARCH and INSERT in TRIES
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    bool isEnd;
    TrieNode *children[26];
    TrieNode(){
        isEnd = false;
        for(int i = 0; i < 26; ++i)
            children[i] = NULL;
    }
};

void insert(TrieNode *root, string key){
    int len = key.size();
    TrieNode *temp = root;

    for(int i = 0; i < len; ++i){
        int idx = key[i] - 'a';
        if(temp->children[idx] == NULL){
            TrieNode *newNode = new TrieNode();
            temp->children[idx] = newNode;
            temp = newNode;
        }
        else
            temp = temp->children[idx];

        if(i == len - 1)
            temp->isEnd = true;
    }
}

bool search(TrieNode *root, string key){
    int len = key.size();
    TrieNode *temp = root;

    for(int i = 0; i < len; i++){
         int idx = key[i] - 'a';
        if(!temp->children[idx])
            return false;
        temp = temp->children[idx];
    }
    return temp->isEnd;
}

bool isEmpty(TrieNode *root){
    for(int i = 0; i < 26; ++i)
        if(root->children[i])
            return false;
    return true;
}

TrieNode* remove(TrieNode *root, string key, int depth = 0){
    if(!root)
        return NULL;
    
    if(depth == key.size()){
        if(root->isEnd)
            root->isEnd = false;
        
        if(isEmpty(root)){
            delete(root);
            root = NULL;
        }
        return root;
    }

    int idx = key[depth] - 'a';
    root->children[idx] = remove(root->children[idx],key,1+depth);
    if(isEmpty(root) && !root->isEnd){
        delete(root);
        root == NULL;
    }
    return root; 
}

int main(){
    string keys[] = {"their", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "the" };
    int n = 8;

    TrieNode *root = new TrieNode();
    for(int i = 0; i < n; i++)
        insert(root,keys[i]);

    search(root, "their")? cout << "Yes\n" : cout << "No\n"; 
    search(root, "these")? cout << "Yes\n" : cout << "No\n"; 
    remove(root, "their"); 
    search(root, "their") ? cout << "Yes\n" : cout << "No\n"; 
    return 0;
}