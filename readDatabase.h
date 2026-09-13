#pragma once

class INPFILEERROR{};

class Person{
private:
    char* NID;
    char* name;
    char* gender;
    int age;
    char* address;
    bool isVote;

    static int count;
public:
    Person();
    ~Person();
    void display();
    friend void readDatabase(Person*);
    friend void displayDatabase(Person*);
    friend bool isEligible(Person*, char*);
    friend void registerVote(Person*, char*, char*);
    friend void updateDatabase(Person*);
};

void readDatabase(Person*);
void displayDatabase(Person*);