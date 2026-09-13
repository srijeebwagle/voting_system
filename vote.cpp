#include "vote.h"

#include<iostream>
#include<iomanip>
#include<cstring>

using namespace std;

Party::Party(){
    name = new char[10];
    symbol = new char[10];
}

Party::~Party(){
    delete[] name;
    delete[] symbol;
}

void votingInterface(Party* p, char*& vote){

    cout << setw(65) << "-------------- Voting System ----------------" << endl << endl;
    cout << setw(43) << "Pratashya" << endl << endl << endl;

    for(int i = 0; i < 6; i ++){
        if(i % 2 == 0){
            cout << setw(16) << p[i].name << " ( " << p[i].symbol << " )";
            continue;
        }
        cout << setw(30) << p[i].name << " ( " << p[i].symbol << " )";
        cout << endl << endl << endl << endl;
    }

    cout << endl;

    cout << setw(58) << "Enter the symbol of the party you want to vote: ";
    cin >> vote;

    cout << endl;

    // This display is done only after storing the vote in the file
    // cout << setw(25) << "Your vote for (" << vote << ") has been successfully registered!" << endl << endl;

}

void readParty(Party* p){
    strcpy(p[0].name, "Yamale");
    strcpy(p[0].symbol, "Surya");

    strcpy(p[1].name, "Congress");
    strcpy(p[1].symbol, "Rukh");

    strcpy(p[2].name, "Maobadi");
    strcpy(p[2].symbol, "Hatoda");

    strcpy(p[3].name, "RaSwaPa");
    strcpy(p[3].symbol, "Ghanti");

    strcpy(p[4].name, "RaPraPa");
    strcpy(p[4].symbol, "Halo");

    strcpy(p[5].name, "ShSanPa");
    strcpy(p[5].symbol, "Mato");
}