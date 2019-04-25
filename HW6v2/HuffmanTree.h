#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
class Node;
class InternalNode;
class TerminalNode;
/*******************************/
class HuffmanTree
{
	friend void dfs(const Node*,bool[][128],int[]);
	friend void rdfs(const Node*,const Node,bool[][128],int[],int);
	friend Node* makeHuf(const string&);
	friend ostream &operator<<(ostream&,const HuffmanTree&);
	Node *root;
public:
	HuffmanTree(const string&);
	~HuffmanTree();
	string encode(const string&)const;
	string decode(const string&)const;	
};

class Node
{
	friend bool cmp(Node,Node);
	friend void rdfs(const Node*,const Node,bool[][128],int [],int);
protected:
	int freq;
public:
	Node(int);
	int getFreq()const;
	virtual int getNodeType()const;
	virtual char getValue()const;
	virtual Node* getLChild()const;
	virtual Node* getRChild()const;
};

class TerminalNode:public Node
{
	char value;
public:
	TerminalNode *here;
	TerminalNode(char s='0',int n=0);
	int getNodeType()const;
	Node* getLChild()const;
	Node* getRChild()const;
	char getValue()const;
	bool operator>(const TerminalNode &Right)const{return (freq>Right.freq);}
	bool operator<(const TerminalNode &Right)const{return (freq<Right.freq);}
};

class InternalNode:public Node
{
	friend void dfs(const Node*,bool[][128],int[]);
	Node* lChild;
	Node* rChild;
public:
	InternalNode *here;
	InternalNode(Node *L=NULL,Node *R=NULL,int n=0);
	int getNodeType()const;
	Node* getLChild()const;
	Node* getRChild()const;
	char getValue()const;
	bool operator>(const InternalNode &Right)const{return (freq>Right.freq);}
	bool operator<(const InternalNode &Right)const{return (freq<Right.freq);}
};