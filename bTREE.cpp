#include "bTREE.h"


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	rootNode->left = leftTree->rootNode;
	rootNode->right = rightTree->rootNode;
	rootNode->time = 0;
	rootNode->data = "";
	rootNode->isLeaf = true;
	
}

bTREE::~bTREE()
{
	delete rootNode;
}

int bTREE::dataInserted() //only number of leaves
{
}

int bTREE::numberOfNodes()
{
}

bool inserthelper(string data1, int time1, treeNode * node)
{
	treeNode * newNode = new treeNode();
	if(node->isLeaf == true)
	{
		newNode->data = data1;
		newNode->time = time1;
		node->left = newNode;
	}
	else 
	{
		if(node->left == NULL)//check for left
		{
			newNode->data = data1;
			newNode->time = time1;
			node->left = newNode;
		}
		
		else if(node->right == NULL)//check for right
		{
			newNode->data = data1;
			newNode->time = time1;
			node->right = newNode;
		}
	}
	 
	return true;
}
int bTREE::insert(string data1, int time1)
{
	treeNode * newNode = new treeNode();
	if(rootNode->isLeaf == true)
	{
		newNode->data = data1;
		newNode->time = time1;
		rootNode->left = newNode;
		return 0;
	}
	else 
	{
		inserthelper(data1,time1,rootNode);
	}
	 
	return true;
}


int bTREE::find(string)
{
}

string bTREE::locate()
{
}

friend bool bTREE::operator ==(const bTREE& lhs, const bTREE& rhs)
{
}

friend bool bTREE::operator !=(const bTREE& lhs, const bTREE& rhs)
{
}

friend std::ostream& bTREE::operator <<(std::ostream& out, const bTREE& p)
{
}
