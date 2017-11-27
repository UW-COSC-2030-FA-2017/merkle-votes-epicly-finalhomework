#include "bTREE.h"
#include <vector>
using namespace std;

//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	//rootNode->left = leftTree->rootNode;
	//rootNode->right = rightTree->rootNode;
	rootNode = new treeNode;
	leftTree = new bTREE;
	rightTree = new bTREE;
	rootNode->data = "";
	rootNode->time = 0;
	rootNode->isLeaf = true;
//	leftTree->rootNode = NULL;
//	rightTree->rootNode = NULL;
}

bTREE::~bTREE()
{
	delete rootNode;
	delete leftTree;
	delete rightTree;
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

string bTREE::getRootNodeData() const
{
    return rootNode->data;
}
int bTREE::insert(string data, int time)
{
    // once we insert a node to another node, have to change the parent node's isLeaf status.
    bool insert;
	treeNode * newNode = new treeNode();
	newNode->data = data1;
	newNode->time = time1;
	if(rootNode->left == NULL) //change root
	{
		rootNode->left = newNode;
		insert = true;
	}
	
	else if(rootNode->right == NULL)
	{
		rootNode->right = newNode;
		insert = true;
	}
	
	else 
	{
		if (leftTree->insert(data1,time1) == 0)
		{
		}
		else (rightTree->insert(data1,time1) == 0)
		{
		}
	}
	
		if(insert)
		{
			rootNode->isLeaf = false; 
			return 1;
		}
		return 0;
}
//0 is false i.e the string was not found, any other number indicates the number of operations.
// how to count the number of operations in a function for individual submission?
int bTREE::find(string x)
{
    static bool found = false;
    int steps = 0;
    if(rootNode->data != x)
    {
        steps = 1 + rightTree->find(x)+leftTree->find(x);
    }
    else
    {
       steps = 1;
       found = true;
    }
    if(found)
    {
        return steps;
    }
    return 0;
}

string bTREE::locate(string x)
{
    static string directions;
    if(find(x)==0)
    {
        directions = ".";
    }
    else
    {

        if(rootNode->data == x)
        {
            directions = directions+(" ");
        }
        else
        {
            if(rightTree->find(x)!=0)
            {
                directions = directions+"R";
                rightTree->locate(x);
            }
            else
            {
                directions = directions + "L";
                leftTree->locate(x);
            }

        }
    }
    return directions;
}

bool operator ==(const bTREE& lhs, const bTREE& rhs)
{
    if(lhs != rhs)
    {
        return false;
    }
    return true;
}

bool operator!=(const bTREE & lhs, const bTREE & rhs)
{
    static bool not_equality = false;
    if(lhs.rootNode->data != rhs.rootNode->data)
    {
        not_equality = true;
    }
    else if((lhs.leftTree != rhs.leftTree) || (lhs.rightTree != rhs.rightTree))
    {
        not_equality = true;
    }
    return not_equality;
}

std::ostream & operator<<(std::ostream & out, const bTREE & p)
{
	// TODO: insert return statement here
	return out;
}
