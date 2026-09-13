#include "registerVote.h"
#include "readDatabase.h"

#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>

using namespace std;

VoteCount::VoteCount(){
    vote = new int[8];
    for(int i = 0; i < 8; i++){
        *(vote + i) = 0;
    }
}
VoteCount::~VoteCount(){
    delete[] vote;
}

void registerVote(Person* p, char* vote, char* userNID){

    VoteCount vc;

    ifstream fin("voteCount.txt");
    if(!fin){
        throw VOTEFILEERRORIN();
    }
    
    int i = 0;
    while(fin >> vc.vote[i]){
        i++;
    }

    //Update vote
    if(!(strcmpi(vote, "Surya")))
        vc.vote[0] += 1;
    else if(!(strcmpi(vote, "Rukh")))
        vc.vote[1] += 1;
    else if(!(strcmpi(vote, "Hatoda")))
        vc.vote[2] += 1;
    else if(!(strcmpi(vote, "Ghanti")))
        vc.vote[3] += 1;  
    else if(!(strcmpi(vote, "Halo")))
        vc.vote[4] += 1;
    else if(!(strcmpi(vote, "Mato")))
        vc.vote[5] += 1;
    else if(!(strcmpi(vote, "NOTA")))
        vc.vote[6] += 1;
    else
        vc.vote[7] += 1;

    
    fin.close();

    ofstream fout("voteCount.txt");
    if(!fout){
        throw VOTEFILEERROROUT();
    }

    for(i = 0; i < 8; i++){
        fout << vc.vote[i] << "\t";
    }
    fout.close();

    cout << setw(25) << "Your vote for (" << vote << ") has been successfully registered!" << endl << endl;

    for(i = 0; i < Person::count; i++){
        if( strcmpi(p[i].NID, userNID) == 0 ){
            p[i].isVote = 1;
            break;
        }
    }

    updateDatabase(p);

    // fout.open("database.txt");
    // if(!fout){
    //     fout.close();
    //     throw DATABASEUPDATEERROR();
    // }

    // for(int i = 0; i < Person::count; i++){
    //     fout << setw(8) << left << p[i].NID << setw(11) << left << p[i].name << setw(8) << left << p[i].gender << setw(6) << left << p[i].age << setw(17) << p[i].address << p[i].isVote << endl;
    // }

    // fout.close();
}

void updateDatabase(Person* p){
    ofstream fout;
    fout.open("database.txt");
    if(!fout){
        fout.close();
        throw DATABASEUPDATEERROR();
    }

    for(int i = 0; i < Person::count; i++){
        fout << setw(8) << left << p[i].NID << setw(11) << left << p[i].name << setw(8) << left << p[i].gender << setw(6) << left << p[i].age << setw(17) << p[i].address << p[i].isVote << endl;
    }

    fout.close();
}