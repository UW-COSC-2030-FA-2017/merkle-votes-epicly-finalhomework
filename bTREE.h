#pragma once
#include <string>
using namespace std;

class bTREE
{
    struct treeNode{
        // how to handle the 32 characters requirement.
        string data;
        int time;
        // do we need these? i am using two pointers to bTREE's in the private section.
		//treeNode* left;
		//treeNode * right;
		bool isLeaf;
    };

private:
	treeNode* rootNode;
	bTREE * leftTree;
	bTREE * rightTree;
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need



public:
    bTREE();
    ~bTREE();

    int dataInserted();
    int numberOfNodes();
    // to help access data by pMT class objects
    string getRootNodeData() const;

    int insert(string, int);

    int find(string);

    string locate(string);


    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);

};

