#include "readDatabase.h"
#include "checkAuthorisation.h"
#include<iostream>
#include<cstring>
using namespace std;

bool isEligible(Person* p, char* userNID){

    //Check if citizen exist and its age and if he/she has already voted
    int i;
    for(i = 0; i < Person::count; i++){
        if( strcmpi(p[i].NID, userNID) == 0 ){

            if(p[i].isVote){
                throw ALREADYVOTED();
            }
            if(p[i].age < 18)
                throw UNDERAGE();
            else
                break;
        }
    }
    if(i == Person::count){
        throw USERNOTFOUND();
    }

    return 1;
}