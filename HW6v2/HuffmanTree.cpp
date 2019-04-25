#include"HuffmanTree.h"

/********** HuffmanTree *************/
Node* makeHuf(const string &);
void dfs(const Node*,bool[][128],int[]);
string btoa(bool[],int);
string toGoal(const Node*,const string&,int&);
HuffmanTree::HuffmanTree(const string &str)
{
	root = makeHuf(str);
	return;
}
HuffmanTree::~HuffmanTree()
{
	queue<InternalNode>q;
	q.push(*(InternalNode*)root);
	while(!q.empty())
	{
		delete q.front().here;
		Node *L = q.front().getLChild();
		Node *R = q.front().getRChild();
		q.pop();
		if(L->getNodeType())q.push(*(InternalNode*)L);
		else delete (TerminalNode*)L;
		if(R->getNodeType())q.push(*(InternalNode*)R);	
		else delete (TerminalNode*)R;
	}
	return;
}
string HuffmanTree::encode(const string &str)const
{
	string en;
	bool table[128][128];
	int len[128] = {};
	dfs(root,table,len);	
	for(int i=0;i<str.size();i++)
		if(len[str[i]])en += btoa(table[str[i]],len[str[i]]);
		else 
		{
			string s(1,str[i]);
			en = "error: character " + s + " cannot be encoded\n";
			break;
		}
	en += "\0";
	return en;
}

string HuffmanTree::decode(const string &str)const
{
	string de = "";
	int i,i0;
	for(i=0;i<str.size();)
	{
		i0 = i;
		de += toGoal(root,str,i);
	}
	if(i>str.size())
	{
			string s = &str[i0];
			de = "error: sequence " + s + " cannot be decoded\n";
	}
	de += "\0";
	return de;
}
//*****friend and others*****//

struct wordC
{
	char word;
	int counter;
};
Node* makeHuf(const string &str)
{
	struct wordC strC[128] = {};
	priority_queue<TerminalNode,vector<TerminalNode>,greater<TerminalNode> >leaf;
	priority_queue<InternalNode,vector<InternalNode>,greater<InternalNode> >branch;	
	for(int i=0;i<str.size();i++)
	{
		strC[str[i]].word = (char)str[i];
		strC[str[i]].counter++;
	}
	
	for(int i=32;i<128;i++)
		if(strC[i].counter>0)
		{
			TerminalNode *temp = new TerminalNode((char)i,strC[i].counter);
			leaf.push(*temp);
		}
	int size=0;
	while(size < str.size())
	{
		if(branch.empty())
		{
			
			TerminalNode L = leaf.top();leaf.pop();
			TerminalNode R = leaf.top();leaf.pop();
			InternalNode *temp = new InternalNode(R.here,L.here,L.getFreq()+R.getFreq());
			branch.push(*temp);
		}
		else if(!leaf.empty())
		{
			InternalNode temp = branch.top();branch.pop();
			InternalNode temp2= branch.top();
			TerminalNode top = leaf.top();leaf.pop();
			TerminalNode sec = leaf.top();
			if(temp2.getFreq()<top.getFreq())
			{
				leaf.push(top);
				branch.pop();
				InternalNode *ttemp = new InternalNode(temp.here,temp2.here,temp2.getFreq()+temp.getFreq());
				branch.push(*ttemp);	
			}
			else if(temp.getFreq() < top.getFreq())
			{
				TerminalNode L = top;
				InternalNode *ttemp = new InternalNode(L.here,temp.here,L.getFreq()+temp.getFreq());
				branch.push(*ttemp);
			}
			
			else if(temp.getFreq() < sec.getFreq())
			{
				TerminalNode R = top;
				InternalNode *ttemp = new InternalNode(R.here,temp.here,R.getFreq()+temp.getFreq());
				branch.push(*ttemp);
			}
			else if(!leaf.empty())
			{
				branch.push(temp);
				leaf.pop();
				TerminalNode L = sec;
				TerminalNode R = top;
				InternalNode *ttemp = new InternalNode(R.here,L.here,R.getFreq()+L.getFreq());
				branch.push(*ttemp);	
			}
			else
			{
				TerminalNode R = top;
				InternalNode *ttemp = new InternalNode(R.here,temp.here,R.getFreq()+temp.getFreq());
				branch.push(*ttemp);	
			}
		}
		else
		{
			InternalNode L = branch.top();branch.pop();
			InternalNode R = branch.top();branch.pop();
			InternalNode *ttemp = new InternalNode(R.here,L.here,R.getFreq()+L.getFreq());
			branch.push(*ttemp);
		}
		InternalNode ttemp = branch.top();
		size = ttemp.getFreq();
	}
	
	return branch.top().here;
}
ostream &operator<<(ostream &output,const HuffmanTree& tree)
{
	queue<InternalNode>q;
	q.push(*(InternalNode*)tree.root);
	output<<"*root: "<<q.front().getFreq()<<endl<<endl;
	while(!q.empty())
	{
		Node *L = q.front().getLChild();
		Node *R = q.front().getRChild();
		output<<"R: "<< R->getFreq()<<endl;	
		output<<"L: "<< L->getFreq();	
		q.pop();
		if(L->getNodeType())q.push(*(InternalNode*)L);
		if(R->getNodeType())q.push(*(InternalNode*)R);
		if(!(L->getNodeType())&&!(R->getNodeType()))cout<<endl<<"L: "<<L->getValue()<<" R: "<<R->getValue()<<endl;
		else if(!(L->getNodeType()))cout<<endl<<"L: "<<L->getValue()<<endl;
		else if(!(R->getNodeType()))cout<<endl<<"R: "<<R->getValue()<<endl;
		if(!q.empty())output<<endl<<endl;		
	}
	return output;
}
void rdfs(const Node *root,const Node *now,bool table[][128],int len[],int F)
{
	if(!(now->getNodeType()))
	{
		for(int i=0;i<F;i++)table[now->getValue()][i] = table[0][i];
		len[now->getValue()] = F;
		return;
	}
	Node *L = now->getLChild();
	Node *R = now->getRChild();
	table[0][F] = false;
	rdfs(root,L,table,len,F+1);
	table[0][F] = true;
	rdfs(root,R,table,len,F+1);
	return;
}
void dfs(const Node *root,bool table[][128],int len[])
{
	table[0][0] = false;
	rdfs((InternalNode*)root,root->getLChild(),table,len,1);
	table[0][0] = true;
	rdfs((InternalNode*)root,root->getRChild(),table,len,1);
}
string btoa(bool table[],int len)
{
	string temp = "";
	for(int i=0;i<len;i++)
		if(table[i])temp += "1";
		else temp += "0";
	return temp;
}
string toGoal(const Node *root,const string &str,int &now)
{
	if(!(root->getNodeType()))
	{
		string temp(1,root->getValue());
		return temp;
	}
	if(now>str.size())
	{
		return "";
	}
	if(str[now] == '0')return toGoal(root->getLChild(),str,++now);
	else return toGoal(root->getRChild(),str,++now);
}

/********** Node  *************/
Node::Node(int a):freq(a){}
int Node::getFreq()const{return freq;}
int Node::getNodeType()const{return 3;}
char Node::getValue()const{return '\0';}
Node* Node::getLChild()const{return NULL;}
Node* Node::getRChild()const{return NULL;}
/********** TerminalNode  *************/
TerminalNode::TerminalNode(char s,int n):value(s),Node(n),here(this){}
int TerminalNode::getNodeType()const{return 0;}
Node* TerminalNode::getLChild()const
{
	cout<<"noLChild\n";
	return NULL;
}
Node* TerminalNode::getRChild()const
{
	cout<<"noRChild\n";
	return NULL;
}
char TerminalNode::getValue()const
{
	return value;
}
/********** InternalNode  *************/
InternalNode::InternalNode(Node *L,Node *R,int n):lChild(L),rChild(R),Node(n),here(this){}
int InternalNode::getNodeType()const{return 1;}
Node* InternalNode::getLChild()const{return lChild;}
Node* InternalNode::getRChild()const{return rChild;}
char InternalNode::getValue()const
{
	cout<<"no value\n";
	return 0;
}
