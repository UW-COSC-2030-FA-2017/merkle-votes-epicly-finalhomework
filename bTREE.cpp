#include "bTREE.h"
#include <vector>
#include <iostream>
using namespace std;

//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	//rootNode->left = leftTree->rootNode;
	//rootNode->right = rightTree->rootNode;
	rootNode = new treeNode();
	//leftTree = new bTREE;
	//rightTree = new bTREE;
	rootNode->data = "";
	rootNode->time = 0;
	rootNode->isLeaf = true;
	leftTree = NULL;
	rightTree = NULL;
	//leftTree->rootNode = NULL;
	//rightTree->rootNode = NULL;
    myQueue.push(this);
	myQueueSize++;
}

bTREE::~bTREE()
{
	delete rootNode;
	//delete leftTree;
	//delete rightTree;
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

//string bTREE::getRootNodeData() const
//{
//    return rootNode->data;
//}
bTREE* bTREE::getLeftTree() const
{
    return leftTree;
}
bTREE* bTREE::getRightTree() const
{
    return rightTree;
}

int bTREE::insert(string data1, int time1)
{
    // once we insert a node to another node, have to change the parent node's isLeaf status.
	static int noOfSteps = 0;
	bool insert = false;
	bTREE * newTree = new bTREE();
	treeNode* newNode = new treeNode();
	newNode->data = data1;
	newNode->time = time1;
	newNode->isLeaf = true;
	//newTree->rootNode->data = data1;
	//newTree->rootNode->time = time1;
	newTree->rootNode = newNode;
	newTree->leftTree = NULL;
	newTree->rightTree = NULL;

	if (rootNode == NULL)//rootNode->data == ""
	{
		rootNode = newNode;
		myQueue.push(newTree);
		myQueueSize++;
		noOfSteps++;
		insert = true;
	}

	else if(myQueue.front()->leftTree == NULL) //change root
	{
		myQueue.front()->leftTree = newTree;
		myQueue.push(newTree);
		myQueueSize++;
		noOfSteps+=2;
		rootNode->isLeaf = false;
		insert = true;
		
	}

	else if (myQueue.front()->rightTree == NULL)
	{
		myQueue.front()->rightTree = newTree;
		myQueue.push(newTree);
		myQueueSize++;
		myQueue.pop();
		myQueueSize--;
		noOfSteps +=3;
		rootNode->isLeaf = false;
		insert = true;
		
	}
	if(insert)
	{
		
		return noOfSteps;
	}
	return 0;
}
//0 is false i.e the string was not found, any other number indicates the number of operations.
// how to count the number of operations in a function for individual submission?
int bTREE::find(string x)
{
    static bool found = false;
    static int steps= 0;
    if((rootNode->data != x) && (rootNode->isLeaf == false))
    {
        steps = 1 + rightTree->find(x)+leftTree->find(x);
    }
    else
    {
       steps ++;
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
	cout << "test:" << find(x) << endl;
    if(find(x)==0)
    {
        directions = ".";
    }
    else
    {
        if((rootNode->data == x) && (rootNode->isLeaf == false))
        {
            directions = directions+(" ");
        }
        /*else
        {*/
     
		else if((leftTree->find(x) > 0) && (rootNode->isLeaf == false))
            {
                directions = directions + "L";
                leftTree->locate(x);
            }
		else if ((rightTree->find(x)) > 0 && (rootNode->isLeaf == false))
		{
			directions = directions + "R";
			rightTree->locate(x);
		}

       /* }*/
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

void
   bTREE:: displayLeft( std::ostream & outfile,
   bTREE * subtree, std::string prefix )
{
   if( subtree == NULL )
   {
      outfile << prefix + "/" << endl;
   }
   else
   {
      displayLeft( outfile, subtree->leftTree, prefix + "     " );
      //outfile << prefix + "/---" << subtree->getRootNodeData() << std::endl;
	  outfile << prefix + "\\---" << subtree->rootNode->data << std::endl;
      displayRight( outfile, subtree->rightTree, prefix + "|    " );
   }
}


// Display the nodes connected to subtree.
// This is a right subtree.
// Use a line by line display, order nodes from left to
//   right, draw connecting lines.
void
   bTREE:: displayRight( std::ostream & outfile,
   bTREE * subtree, std::string prefix )
{
   if( subtree == NULL )
   {
      outfile << prefix + "\\" << std::endl;
   }
   else
   {
      displayLeft( outfile, subtree->leftTree, prefix + "|    " );
      //outfile << prefix + "\\---" << subtree->getRootNodeData() << std::endl;
	  outfile << prefix + "\\---" << subtree->rootNode->data << std::endl;
      displayRight( outfile, subtree->rightTree, prefix + "     " );
   }
}


std::ostream& operator <<(std::ostream& out, const bTREE* p)
{
   std::string prefix;
   if( p->rootNode->isLeaf == true)
   {
      out << "-" << endl;
   }
   else
   {
      bTREE::displayLeft( out, p->leftTree, "    " );
      //out << "---" << p.getRootNodeData() << std::endl;
	  out << "---" << p->rootNode->data << std::endl;

      bTREE::displayRight( out, p->rightTree, "    " );
   }
   return out;
}

//std::ostream & operator<<(std::ostream & out, const bTREE & p)
//{
//	// TODO: insert return statement here
//	return out;
//}
