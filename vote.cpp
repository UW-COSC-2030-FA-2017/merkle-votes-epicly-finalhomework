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
		while (getline(myfile, temp))
		{
            
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
    while((theMerkleTree.getQueueLength())*2<=noOfVotes) //.getMerkle()
    {
        theMerkleTree.insert("a", 0);
		//cout << theMerkleTree << endl;
    }
    for(int i = 0; i<noOfVotes; i++)
    {
        theMerkleTree.insert(votes[i],timeStamps[i]);
		//cout << theMerkleTree << endl;
    }
    theMerkleTree.update();
	cout << theMerkleTree << endl;
	cout << "The hash in the rootNode is: " << theMerkleTree.getMerkle()->rootNode->data << endl;
	//cout << "The directions to 1211A3C787:Candidate2	6:	" << theMerkleTree.getMerkle()->locate("4FCF8F701") << endl;
	//cout << "Trying to find 1211A3C787:Candidate2	6:	" << theMerkleTree.getMerkle()->find("1211A3C78lmkoklmklnm") << endl;
	
    //============================================================================
	vector<string> votes1;
	vector<int> timeStamps1;
	int noOfVotes1 = 0;
    promptAndFillInVariables(votes1, timeStamps1, noOfVotes1);
    pMT merkleTree1(1);
	while ((merkleTree1.getQueueLength()) * 2 <= noOfVotes1) //.getMerkle()
	{
		merkleTree1.insert("a", 0);
		//cout << theMerkleTree << endl;
	}
	for (int i = 0; i<noOfVotes1; i++)
	{
		merkleTree1.insert(votes1[i], timeStamps1[i]);
		//cout << theMerkleTree << endl;
	}
	merkleTree1.update();
    //-------------------------------------------------------------
	vector<string> votes2;
	vector<int> timeStamps2;
	int noOfVotes2 = 0;
    promptAndFillInVariables(votes2, timeStamps2, noOfVotes2);
    pMT merkleTree2(1);
    //fill all data into merkleTree2
	while ((merkleTree2.getQueueLength()) * 2 <= noOfVotes2) //.getMerkle()
	{
		merkleTree2.insert("a", 0);
		//cout << theMerkleTree << endl;
	}
	for (int i = 0; i<noOfVotes2; i++)
	{
		merkleTree2.insert(votes2[i], timeStamps2[i]);
		//cout << theMerkleTree << endl;
	}
	merkleTree2.update();

    if(merkleTree1 == merkleTree2)
    {
        cout<<"Validated!"<<endl;
    }
    else
    {
        cout<<"Not Validated"<<endl;
    }
    return 0;
}
