#include "readDatabase.h"
#include "checkAuthorisation.h"
#include "vote.h"
#include "registerVote.h"

#include<iostream>
using namespace std;

int main(){

    char* userNID = new char[10];

    Person* p = new Person[7];
    Party* party = new Party[6];

    try{
        readDatabase(p);
        // displayDatabase(p);
    }
    catch(INPFILEERROR){
        cout << "Error opening the citizen database!";
    }

    while(1){

        cout << "Enter your NID number: ";
        cin >> userNID;

        try{
            bool check = isEligible(p, userNID);
        
            if(check){

                char* vote = new char[13];

                readParty(party);
                votingInterface(party, vote);

                registerVote(p, vote, userNID);

            }
        }
        catch(ALREADYVOTED){
            cout << "You have already voted. You cannot vote again!";
            getchar();
            getchar();
            cout << endl;
        }
        catch(UNDERAGE){
            cout << "You are underage, you cannot vote!";
            getchar();
            getchar();
            cout << endl;
        }
        catch(USERNOTFOUND){
            cout << "You aren't found in the database!";
            getchar();
            getchar();
            cout << endl;
        }
        catch(VOTEFILEERRORIN){
            cout << "Error updating the vote (reading error)";
            return 1;
        }
        catch(VOTEFILEERROROUT){
            cout << "Error updating the vote (writing error)";
            return 1;
        }
        catch(DATABASEUPDATEERROR){
            cout << "Failed to update the database";
            return 1;
        }
    }
    return 0;
}