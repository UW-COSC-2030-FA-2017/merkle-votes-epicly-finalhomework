#include "pMT.h"
#include <cstring>
#include<stdlib.h>
pMT::pMT(int hashSelect)
/**
 * @brief
 * @param hashSelect a number corresponding to the hashfunction to use for this pMT
 * @return
 */
{
    selectedHash = hashSelect;
}

pMT::~pMT()
/**
 * @brief destructor
 * @return nada
 */
{
}

int pMT::insert(string vote, int time)
/**
 * @brief insert a vote and time into a leaf node of tree
 * @param vote - a string
 * @param time - an int representing the time
 * @return the number of operations needed to do the insert, -1 if out of memory
 */

{
    return 0;
}

int pMT::find(string vote, int time, int hashSelect)
/**
 * @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
 * @param vote, a string
 * @param time, an int
 * @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
 * @return 0 if not found, else number of operations required to find the matching vote
 */
{
    string Hash;
    if(hashSelect<=1)
    {
        Hash = hash_1(vote);
    }
    else if(hashSelect==2)
    {
        Hash = hash_2(vote);
    }
    else if(hashSelect>=3)
    {
        Hash = hash_3(vote);
    }
    return myMerkle.find(Hash);

}

int pMT::findHash(string mhash)
/**
 * @brief does this hash exist in the tree?
 * @param mhash, a string to search for in the tree
 * @return 0 if not found, else number of opperations required to find the matching hash
 */
{
    return myMerkle.find(mhash);
}

string pMT:: locate(string dataOrHash)
{
    return myMerkle.locate(dataOrHash);
}
//
//string pMT::locateData(string vote)
///**
// * @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root.
// * @param vote, the data to search for
// * @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
// */
//{
//    return myMerkle.locate(vote);
//}
//
//string pMT::locateHash(string mhash)
///**
// * @brief Function takes a hash and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root.
// * @param mhash, the hash to search for
// * @return sequence of L's and R's comprising the movement to the hash node, ; else return a dot '.'
// */
//{
//     return myMerkle.locate(mhash);
//}


//how to handle collisions?
string pMT::hash_1(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
    char hashString[32];
    char* str = new char[32];
    strcpy(str, key.c_str());
    unsigned int length = key.length();
    unsigned int seed = 4231;
    unsigned int hash = 0;
    unsigned int i    = 0;

    for (i = 0; i < length; ++str, ++i)
    {
       hash = (hash * seed) + (*str);
    }
    itoa(hash, hashString, 16);

    return hashString;
}

string pMT::hash_2(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
    return "";
}

string pMT::hash_3(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
    return "";
}
// can i just check if the data(hash) in the rootNode of first tree is equal to the hash in the rootNode of the second tree?
bool operator ==(const pMT& lhs, const pMT& rhs)
/**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if equal, false otherwise
 */
{
    if(lhs.myMerkle.getRootNodeData()== rhs.myMerkle.getRootNodeData())
    {
        return true;
    }
    return false;
}

bool operator !=(const pMT& lhs, const pMT& rhs)
/**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if not equal, false otherwise
 */
{
    if(lhs == rhs)
    {
        return false;
    }
    return true;
}
// why does it matter if we give a tree where it was matching or where it differed?
// what does xor on two trees mean? why do we need it?
pMT operator ^(const pMT& lhs, const pMT& rhs)
/**
 * @brief Where do two trees differ
 * @param lhs
 * @param rhs
 * @return a tree comprised of the right hand side tree nodes that are NOT different from the left
 */
{
    return rhs;
}


std::ostream& operator <<(std::ostream& out, const pMT& p)
/**
 * @brief Print out a tree
 * @param out
 * @param p
 * @return a tree to the screen
 */
{
    return out;
}
