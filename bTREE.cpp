#include "bTREE.h"


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	rootNode->left = leftTree->rootNode;
	rootNode->right = rightTree->rootNode;
	rootNode->data = "";
	rootNode->time = 0;
	rootNode->isLeaf = true;
	leftTree->rootNode = NULL;
	rightTree->rootNode = NULL;
}

bTREE::~bTREE()
{
	delete rootNode;
}

int bTREE::dataInserted()
{
	int noOfData = 0;
	if (rootNode == NULL)
	{
		noOfData= 0;
	}
	else if (rootNode->isLeaf == true)
	{
		noOfData = 1;
	}
	else
	{
		noOfData = leftTree->dataInserted() + rightTree->dataInserted();
	}
	return noOfData;
}

int bTREE::numberOfNodes()
{
	int numNodes = 0;
	if (rootNode == NULL)
	{
		numNodes = 0;
	}
	else if (leftTree->rootNode == NULL && rightTree->rootNode == NULL)
	{
		numNodes = 1;
	}
	else
	{
		numNodes = 1 + leftTree->numberOfNodes() + rightTree->numberOfNodes();
	}
	return numNodes;
}

int bTREE::insert(string data, int time)
{
	//bool found;
	//if (rootNode->left == NULL)
	//{
	//	//add to the left
	//	found = true;
	//}
	//else if (rootNode->right == NULL)
	//{
	//	//add to the right
	//	found = true;
	//}
	//else
	//{
	//	leftTree->insert(data, time);
	//	right
	//}
}

int bTREE::find(string)
{
}

string bTREE::locate(string x)
{
}

bool operator ==(const bTREE& lhs, const bTREE& rhs)
{
	return false;
}

bool operator!=(const bTREE & lhs, const bTREE & rhs)
{
	return false;
}

std::ostream & operator<<(std::ostream & out, const bTREE & p)
{
	// TODO: insert return statement here
}
