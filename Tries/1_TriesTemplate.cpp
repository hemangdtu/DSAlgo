#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    unordered_map<char,Node*> children;
    bool terminal;
    Node(char d)
    {
        data = d;
        terminal = false;
    }
};

class Trie
{
private:
    Node* root;
    int cnt;

public:
    Trie()
    {
        root = new Node('\0');
        cnt = 0;
    }

    void insert(char *w)
    {
        Node* temp = root;
        for(int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if(temp -> children.count(ch))
                temp = temp -> children[ch];
            else
            {
                Node* n = new Node(ch);
                temp -> children[ch] = n;
                temp = n;
            }
        }
        temp -> terminal = true;
    }

    bool find(char *w)
    {
        Node* temp = root;
        for(int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if(temp -> children.count(ch) == 0)
                return false;
            else
                temp = temp -> children[ch];
        }
        return temp -> terminal;
    }
};

int main()
{
    Trie names;
    char words[][10] = {"A", "Hello", "Hemang", "Apple", "Mango", "App"};
    char searchWord[10];
    cin>>searchWord;

    for(int i = 0; i<6; i++)
        names.insert(words[i]);

    if(names.find(searchWord))
        cout<<"Present";
    else
        cout<<"Absent";
    
    return 0;   
}