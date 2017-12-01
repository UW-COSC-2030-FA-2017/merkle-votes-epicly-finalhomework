#include <stdio.h>
#include "pMT.h"
#include <vector>
#include <fstream>
#include<string>
#include <iostream>
#include <sstream>
using namespace std;

void promptAndFillInVariables(vector<string>& votes, vector<int>& timeStamps, int& noOfVotes)
{
    string filename;
    string temp;
	string vote1;
	int timestamp = 0;
    cout<<"Enter the filename: ";
    cin>>filename;
    //vector<string> votes;
    //vector<int> timeStamps;
	ifstream myfile;
    //int noOfVotes = 0;
	myfile.open(filename);
	int index = 0;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
            getline(myfile,temp);
			if (index > 0 )
			{
				//getline(myfile, temp);
				istringstream iss(temp);
				iss >> vote1 >> timestamp;
				int pos = vote1.find(":");
				//int pos2 = temp.find(" ");
				if (pos!=std::string::npos)
				{
				    string vote = vote1.substr(0,pos);
				    //int timeStamp = stoi(temp.substr(pos2+1));

                    votes.push_back(vote);
                    timeStamps.push_back(timestamp);
                    noOfVotes++;
				}
			}
			index++;
		}

	}
	else{
        cout<<"There was an error in opening the file: Please check filename."<<endl;
	}
}
int main(int argc, char **argv)
{
    //do we have to use these arguments/parameters?
    vector<string> votes;
    vector<int> timeStamps;
    int noOfVotes = 0;
    promptAndFillInVariables(votes, timeStamps, noOfVotes);
    //Till here the file has been read and the info has been stored in the two vectors declared above.
    pMT theMerkleTree(1);
    //Here insert all the data into theMerkleTree
    while((theMerkleTree.getQueueLength())*2<=noOfVotes)
    {
        theMerkleTree.insert("", 0);
    }
    for(int i = 0; i<noOfVotes; i++)
    {
        theMerkleTree.insert(votes[i],timeStamps[i]);
    }
    theMerkleTree.update();
    cout<<"The hash in the rootNode is: "<< theMerkleTree.getMerkle().getRootNodeData()<<endl;
    //============================================================================
//    promptAndFillInVariables(votes, timeStamps, noOfVotes);
//    pMT merkleTree1(1);
//    //fill all data into merkleTree1.
//    //-------------------------------------------------------------
//    promptAndFillInVariables(votes, timeStamps, noOfVotes);
//    pMT merkleTree2(1);
//    //fill all data into merkleTree2
//
//    if(merkleTree1==merkleTree2)
//    {
//        cout<<"Validated!"<<endl;
//    }
//    else
//    {
//        cout<<"Not Validated"<<endl;
//    }
    return 0;
}
