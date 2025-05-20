//striever video
#include<iostream>
using namespace std;
struct Node{
    Node* links[26];
    int countWithEnds = 0;
    int countPrefix = 0;
    bool containsKey (char c){
        return links[c-'a']!=NULL;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void put(char c,Node* node){
        links[c-'a']=node;
    }
    void increaseEnd(){
        countWithEnds++;
    }
    void increasePrefix(){
        countPrefix++;
    }
    void reduceEnd(){
        countWithEnds--;
    }
    void reducePrefix(){
        countPrefix--;
    }
    int getWordCount(){
        return countWithEnds;
    }
    int getPrefixCount(){
        return countPrefix;
    }
};
class Trie {
    private:
        Node* root;
	public:
	    Trie() {    
	        root = new Node();
	    }

	    void insert(string word) {
	        int n= word.length();
            Node* node = root;
            for(int i=0;i<n;++i){
                if(node->containsKey(word[i])){
                    node=node->get(word[i]);
                    node->increasePrefix();
                }
                else{
                    Node * newNode = new Node();
                    node->put(word[i],newNode);
                    // newNode->increasePrefix();
                    node = node->get(word[i]);
                    node->increasePrefix();
                }
            }
            node->increaseEnd();
    	}

	    int countWordsEqualTo(string word) {
	        int n= word.length();
            Node* node = root;
            for(int i=0;i<n;++i){
                if(!node->containsKey(word[i]))return 0;
                node=node->get(word[i]);
            }
            return node->getWordCount();
    	}

	    int countWordsStartingWith(string word) {
	        int n=word.length();
            Node* node = root;
            for(int i=0;i<n;++i){
                if(!node->containsKey(word[i]))return 0;
                node = node->get(word[i]);
            }
            return node->getPrefixCount();
    	}

	    void erase(string word) {
	        int n= word.length();
            Node* node = root;
            for(int i=0;i<n;++i){
                if(!node->containsKey(word[i]))return;
                node=node->get(word[i]);
                node->reducePrefix();

            }
            node->reduceEnd();
	    }
};
int main(){

}
