#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>

#define MAX     100

using namespace std;

int MAX_COUNT = 26;

class TrieNode{
    private:
        TrieNode *elements[MAX_COUNT];
        bool is_end;

    public:
        TrieNode(){
            this->is_end = false;
            for(int i = 0; i < MAX_COUNT; i++)
                this->elements[i] = NULL;
        }

        Trienode *get_value(char ch)
        {
            return elements[ch - 'a'];
        }

        void set_value(char ch)
        {
            TrieNode newnode = new TrieNode();
            newnode.is_end = false;
            elements[ch -'a'] = newnode;
        }
        
        TrieNode *move_local(char ch)
        {
            return elements[ch - 'a'];
        }


};

class Trie{
    TrieNode *root;

    Trie(){
        root = new TrieNode();
        root->is_end = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *local = root;
        int i = 0;

        for(i = 0; i < word.length(); i++)
        {
            if(local->get_value(word[i]) == NULL)
                local->set_value(word[i]);
            
            local = local->move_local(word[i]);
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *local = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(local->get_value(word[i]) != NULL)
            {
                local = local->move_local(word[i]);
            }
            else
                return false;
        }
        if(local->is_end == true)
            return true;
        else
            return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *local = root;

        for(int i = 0; i < word.length(); i++)
        {
            if(local->get_value(word[i]) != NULL)
            {
                local = local->move_local(word[i]);
            }
            else
                return false;
        }
        return true;
    }
};
