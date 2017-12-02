#pragma once
#include <string>
#include <queue>
using namespace std;

class bTREE
{
    struct treeNode{
        // how to handle the 32 characters requirement.
        string data="";
        int time;
        // do we need these? i am using two pointers to bTREE's in the private section.
		//treeNode* left;
		//treeNode * right;
		bool isLeaf;
    };

private:

    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
    //queue<bTREE*> myQueue;


public:
    bTREE();
    ~bTREE();
    //transferred from private to public to avoid accessibility issues.
    treeNode* rootNode;
	bTREE * leftTree;
	bTREE * rightTree;
    queue<bTREE*> myQueue=queue<bTREE*>();
	int myQueueSize = 0;
	/*int getQueueLength() const
	{
		return myQueue.size();
	}*/
    //----------------------------------------------------------------
    int dataInserted();
    int numberOfNodes();
    // to help access data by pMT class objects
    string getRootNodeData() const;
    bTREE getLeftTree() const;
    bTREE getRightTree() const;
    bool isRootNodeLeaf() const
    {
        return rootNode->isLeaf;
    }
    int insert(string, int);

    int find(string);

    string locate(string);


    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);

    static void displayLeft( std::ostream & outfile,
      bTREE * subtree, std::string prefix );

    static void displayRight( std::ostream & outfile,
      bTREE * subtree, std::string prefix );

};

