#ifndef TRIE
#define TRIE
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
 
using namespace std;

struct node
{
    bool is_end;
    int suffix_count;
    struct node* child[26];
};


class trie{
  public:
    trie(){
      head = new node();
      head->suffix_count = 0;
      head->is_end = false;
    }
    ~trie();
    void insert(string word){
      node * current = head;
      current->suffix_count++;
      for(unsigned int i=0; i<word.length(); ++i){
        int letter = (int)word[i] - (int)'a';
        if(current->child[letter] == NULL)
          current->child[letter] = new node();
        current->child[letter]->suffix_count++;
        current = current->child[letter];
      }
      current->is_end = true;
    }

    bool search(string word){
      node * current = head;
      for(unsigned int i=0; i<word.length(); ++i){
        if(current->child[((int)word[i]-(int)'a')] == NULL)
          return false;
        current = current->child[((int)word[i]-(int)'a')];
      }
      return current->is_end;
    }

    int words_with_suffix(string suffix){
      node * current = head;
      for(unsigned int i=0; i<suffix.length(); ++i){
        if(current->child[((int)suffix[i]-(int)'a')] == NULL)
          return 0;
        else
          current = current->child[((int)suffix[i]-(int)'a')];
      }
      return current->suffix_count;
    }


  private:
    node * head; 
};

#endif