#include "readDatabase.h"
#include "checkAuthorisation.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>

using namespace std;

Person::Person(){
    NID = new char[10];
    name = new char[15];
    gender = new char[10];
    address = new char[20];
}

Person::~Person(){
    delete[] name;
    delete[] gender;
    delete[] address;
}

void Person::display(){
    cout << "( " << setw(6) << NID << setw(15) << name << setw(10) << gender << setw(5) << age << setw(20) << address << setw(5) << isVote << " )";
}

void readDatabase(Person* p){
    fstream fin;
    fin.open("database.txt");
    if(!fin){
        fin.close();
        throw INPFILEERROR();
    }

    //collects the first row of the database
    char nid[10], nm[15], gend[10], ag[10], add[15], hasVote[15];
    fin >> nid >> nm >> gend >> ag >> add >> hasVote;

    int i = 0;
    while(fin >> p[i].NID >> p[i].name >> p[i].gender >> p[i].age >> p[i].address >> p[i].isVote){
        i++;
    }
    Person::count = i;
    fin.close();

}

void displayDatabase(Person* p){
    for(int i = 0; i < Person::count; i++){
        p[i].display();
        cout << endl;
    }
}

int Person::count = 0;