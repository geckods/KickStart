#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int ALPHABET_SIZE = 26; 
  
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
    struct TrieNode *parent;
    int isEndOfWord;
    int wordsCount;
    int score;
}; 
  
struct TrieNode *getNode(void)
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = 0; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 

    pNode->parent==NULL;

    pNode->score=0;
  
    return pNode; 
} 
  
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 

    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'A'; 
        if (!pCrawl->children[index]){
        // cerr<<key[i]<<endl;  
            pCrawl->children[index] = getNode(); 
            pCrawl->children[index]->parent=pCrawl;
            pCrawl->children[index]->score=pCrawl->score+1;
        } 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    pCrawl->isEndOfWord++; 
} 
  
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'A'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 

void buildWordsCount(struct TrieNode *root){
    for(int i=0;i<ALPHABET_SIZE;i++){
        if(root->children[i]!=NULL){
            buildWordsCount(root->children[i]);
            root->wordsCount+=root->children[i]->wordsCount;
        }
    }
    root->wordsCount+=root->isEndOfWord;
}

//for all children, call function
//return mySize/k
//sendUp mySize%k

ll globalAns=0;

ll computeAns(struct TrieNode *node, ll k){
    ll hasHere=node->isEndOfWord;
    for(int i=0;i<ALPHABET_SIZE;i++){
        if(node->children[i]!=NULL){
            hasHere+=computeAns(node->children[i],k);
        }
    }

    globalAns+=(hasHere/k)*node->score;
    return hasHere%k;
}



int main(){

    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
        freopen("error", "w", stderr);
    #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    for(int test=0;test<t;test++){
        ll n,k;
        cin>>n>>k;
        struct TrieNode *root = getNode();
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            insert(root,s);
        // cerr<<"HI"<<" "<<s<<endl;
        }

        globalAns=0;
        computeAns(root,k);
        cout<<"Case #"<<test+1<<": "<<globalAns<<endl;
    }
}
