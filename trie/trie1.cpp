//striever video
#include<iostream>
using namespace std;
struct Node{
    Node*  links[26];
    bool flag = false;
    bool containsKey(char c){
        return links[c-'a']==NULL;
    }
    void put(char c,Node* node){
       links[c-'a']=node;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
         //O(length of word)
        void insertWord(string word){
            int n = word.length();
            Node* node = root;
            for(int i=0;i<n;++i){
                if(!node->containsKey(word[i])){
                    Node* newNode = new Node();
                    node->put(word[i],newNode);
                }
                node = node->get(word[i]);
            }
            node->setEnd();
        }
        //O(length of word)
        bool searchWord(string word){
            Node* node = root;
            int n=word.length();
            for(int i=0;i<n;++i){
                if(!node->containsKey(word[i]))return false;
                node=node->get(word[i]);
            }
            return node->isEnd();
        }
         //O(length of word)
        bool startsWith(string word){
            Node* node = root;
            int n = word.length();
            for(int i=0;i<n;++i){
                if(!node->containsKey(word[i]))return false;
                node = node->get(word[i]);
            }
            return true;
        }

};
int main(){
    Trie t1;
}