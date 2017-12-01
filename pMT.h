#pragma once

#include "bTREE.h"
#include <string>
using namespace std;
class pMT
{
private:
    int selectedHash;
    bTREE myMerkle;

    string hash_1(string);
    string hash_2(string);
    string hash_3(string);

public:
    pMT(int);
    ~pMT();

    bTREE getMerkle() const
    {
        return myMerkle;
    }
    int getQueueLength() const
    {
        return myMerkle.myQueue.size();
    }
    int insert(string s, int i);
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
//    string hash_selected(bTREE merkle)
//    {
//        if(merkle.isl)
//        hash_selected(myMerkle.getLeftTree());
//        hash_selected(myMerkle.getRightTree());
//        myMerkle.getRootNodeData() = hash
//
//    }

//    void update()
//    {
//        if(!myMerkle.isRootNodeLeaf())
//        {
//            myMleftTree.update();
//            rightTree.update();
//            string hashLeft = hash_selected(myMerkle.getLeftTree().getRootNodeData());
//            string hashRight = hash_selected(myMerkle.getRightTree().getRootNodeData());
//            myMerkle.
//        }

    void update();

    void rhash(bTREE *tree);

    string hash_selected(string data);
};

