/*
 * Name: Jack Primiani
 * Date: April 22nd, 2020
 * Class: CSCE 355
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    int numStates;
    vector<int> acceptStates;
    vector<char> alpha;
    vector<vector<int> > tTable;
    vector<vector<char> > input;
    
    //Parse the dfa file.
    string dfaString;
    ifstream dfaFile;
    dfaFile.open(argv[1]);

    //get number of states from first line at index 18
    getline(dfaFile, dfaString);
    numStates = atoi(dfaString.substr(18).c_str());
    
    //get accepting states from second line, beginning at index 18
    getline(dfaFile, dfaString);
    dfaString = dfaString.substr(18);
    int pos = 0;
    string tempState;
    while((pos = dfaString.find(" ")) != string::npos) {
        tempState = dfaString.substr(0, pos);
        acceptStates.push_back(atoi(tempState.c_str()));
        dfaString.erase(0, pos + 1);
    }
    acceptStates.push_back(atoi(dfaString.c_str())); //get last state from line
    
    //get alphabet from third line, beginning at index 10
    getline(dfaFile, dfaString);
    dfaString = dfaString.substr(10);
    for (int i = 0; i < dfaString.length(); i++) {
        alpha.push_back(dfaString.at(i));
    }
    
    //finally parse the transition table, starting on line four
    while (getline(dfaFile, dfaString)) {
        vector<int> transRow;
        pos = 0;
        string tempRow;
        while((pos = dfaString.find(" ")) != string::npos) {
            tempRow = dfaString.substr(0, pos);
            transRow.push_back(atoi(tempRow.c_str()));
            dfaString.erase(0, pos + 1); 
        }
        transRow.push_back(atoi(dfaString.c_str()));
        tTable.push_back(transRow);
    }
    dfaFile.close(); //finished reading dfa file

    //Parse the string(s) file
    string inputString;
    ifstream inputFile;
    inputFile.open(argv[2]);
    int count = 0;

    while(getline(inputFile, inputString)) {
        vector<char> inputLine;
        for(int i = 0; i < inputString.length(); i++) {
            inputLine.push_back(inputString.at(i));
        }
        input.push_back(inputLine);
    }
    inputFile.close(); //finished reading input file

   
    //Process DFA
    for (int i = 0; i < input.size(); i++) {
        //alphaPos == current input char's position in alphabet vector
        int alphaPos;
        int currentState = 0; //0 is always start state
        bool accept = false;
        //if input is blank, stay at start state
        if (input.at(i).size() != 0) {
            for (int j = 0; j < input.at(i).size(); j++) {
                for (int k = 0; k < alpha.size(); k++) {
                    if (alpha.at(k) == input.at(i).at(j)) {
                        alphaPos = k;
                        break;
                    }
                }
                currentState = tTable.at(currentState).at(alphaPos);
            }
        }
        for (int j = 0; j < acceptStates.size(); j++) {
            if (currentState == acceptStates.at(j)) {
                cout << "accept" << endl;
                accept = true;
                break;
            }
        }
        if (!accept) {
            cout << "reject" << endl;
        }
    }
    return 0;
}
