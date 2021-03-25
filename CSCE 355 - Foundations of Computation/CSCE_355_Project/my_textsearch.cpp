/*
 * Name: Jack Primiani
 * Date: April 22nd, 2020
 * Class: CSCE 355
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
 
using namespace std;
 
int main(int argc, char** argv) {
    int numStates = 0;
    string str;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    int alphaLen = alpha.length();
    int strLen;
    int acceptState;
    int offset = 97; //char to int offset for lowercase letters

    //read input from text file
    ifstream textFile;
    textFile.open(argv[1]);
    getline(textFile, str);
    strLen = str.length();
    acceptState = strLen;
    numStates = strLen + 1;
 
    //create array for transition table
    int trans[numStates][alphaLen]; 

    //Compute transition table 
    //Process state 1 on its own so we can fill the rest of it with 0's.
    trans[0][str.at(0) - offset] = 1;
    for (int i = 0; i < alphaLen; i++) {
        if (i != str.at(0) - offset)
            trans[0][i] = 0;
    }

    //First copy the mismatch case to account for loops within the substring. 
    //Then set the match case to account for finding the pure string without looping.
    int s = 0; //restart state for mismatch case
    for (int i = 1; i < strLen; i++) {
        for (int j = 0; j < alphaLen; j++) {
            if (j != str.at(i) - offset)
                trans[i][j] = trans[s][j]; //mismatch case
        }
        trans[i][str.at(i) - offset] = i + 1; //match case
        s = trans[s][str.at(i) - offset]; //set restart state
    }

    //the last state will only transition to itself
    for (int i = 0; i < alphaLen; i++) {
        trans[numStates - 1][i] = numStates - 1;
    }
 
    //Print the DFA to stdout.
    cout << "Number of states: " << numStates << endl;
    cout << "Accepting states: " << acceptState << endl;
    cout << "Alphabet: " << alpha << endl;
    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < alphaLen - 1; j++) {
            cout << trans[i][j] << " ";
        }
        cout << trans[i][alphaLen - 1] << endl;
    }
    return 0;
}
