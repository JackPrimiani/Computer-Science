/*
Jack Primiani
CSCE 350
December 5th, 2019
*/
#include <string>
#include <iostream>
using namespace std;

int cutPalindrome(string s) {
    int len = s.size();
//Milti-array for tracking palindromes
    bool pal[len][len];
    bool goux=true;
    int cut[len];
//Initialize tracking array with non-null values
    for(int i=0; i<len; i++){
        for(int j=i; j<len; j++){
            pal[i][j] = false;
        }
    }
//Track palindromes in odd length strings
    for(int k=0; k<len; k++){
        int l = k;
        int r = k;
        while(l>=0 && r<len && s[l]==s[r]){
            pal[l][r] = true;
            l--; 
            r++;
        }
    }
//Track palindromes in even length string
    for(int x=0; x<len; x++){
        int l = x;
        int r = x+1;
        while(l>=0 && r<len && s[l]==s[r]){
            pal[l][r] = true;
            l--; 
            r++;
        }
    }
//Initialize array used for dynamic programming
    for(int m=0; m<len; m++){
        cut[m] = len+10;
    }
    cut[0] = 0;
//Dynamic programming implementaion to find least amount of cuts
    for(int n=1; n<len; n++){
        goux=false;
//If first index is 0 amount of cuts is 0
        if(pal[0][n]==true){
            cut[n]=0; 
            goux=true;
        }
//As long as we were not in the if statement above proceed
        if(!goux){
            for(int p=n; p>0; p--){
                if(pal[p][n]==true) {
//Continually take the minimum number of cuts and continue
                    cut[n] = min(cut[p], cut[p-1]+1);
                }
            }
        }
    }
    return cut[len-1];
}

int main (int argc, char **argv) {
    string palin="";
    cout << "Enter Strings to be cut into palindromes, enter a single exclaimation point '!' to stop" << endl;
    while(palin!="!") {
        cin >> palin;
        if(palin!="!") {
            int cut = cutPalindrome(palin);
            cout << "---The Minimum amount of cuts: " << cut << endl;
        }
    }
    cout << "Finished." <<  endl;
}
