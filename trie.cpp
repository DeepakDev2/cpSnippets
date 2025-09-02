#include<bits/stdc++.h>
using namespace std;
struct BinaryTrie{
    BinaryTrie* node[2];
    int cnt;
    int index;

    BinaryTrie(){
        node[0]=node[1]=NULL;
        cnt=0;
        index=-1;
    }
    
};

void insert(BinaryTrie* trie,int num,int idx=-1){
    int mask = 1<<30;
    while(mask){
        int bit = (mask&num)>0;
        if(trie->node[bit]==NULL){
            trie->node[bit]=new BinaryTrie();
        }
        trie=trie->node[bit];
        mask>>=1;
        trie->cnt++;
    }
    trie->index=idx;
}

void erase(BinaryTrie* trie, int num) {
    int mask = (1 << 30);

    function<void(BinaryTrie*&, int)> f = [&](BinaryTrie*& node, int mask) {
        if (node == nullptr || mask == 0) return;

        int bit = (num & mask) ? 1 : 0;
        f(node->node[bit], mask >> 1);

        node->cnt--;
        if (node->cnt == 0) {
            delete (node);
            node = nullptr;
        }
    };

    f(trie, mask);
}



