#pragma once

#include "bTREE.h"
#include <string>
#include <cstring>
using namespace std;

class pMT
{
private:
    int selectedHash;
    bTREE myMerkle;
    
    string hash_1(string);
    string hash_2(string);
    string hash_3(string);
    
	struct treeNode{
        string data;
        int time;
		bool isLeaf;
    }; 

public:
	
    pMT(int);
    ~pMT();
    
	void update();
	
	void rhash(bTREE *tree);
	
    string hash_selected(string data);
	
    int insert(string data, int time1);
    
    // ask if changing the number of parameters is ok.
    //changed it from (string) to (string, int, int)
    int find(string, int, int);
    int findHash(string x);
    //both locateData and locateHash do the same thing..then why do we need two different functions?
    string locate(string x);

    friend bool operator==(const pMT& lhs, const pMT& rhs);

    friend bool operator!=(const pMT& lhs, const pMT& rhs);

    friend pMT operator^(const pMT& lhs, const pMT& rhs);

    friend std::ostream& operator<<(std::ostream& out, const pMT& p);
};

