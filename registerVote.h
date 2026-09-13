#pragma once

#include "readDatabase.h"

class VOTEFILEERRORIN{};
class VOTEFILEERROROUT{};
class DATABASEUPDATEERROR{};

class VoteCount{
private:
    int* vote;
public:
    VoteCount();
    ~VoteCount();
    friend void registerVote(Person*, char*, char*);
};

void registerVote(Person*, char*, char*);
void updateDatabase(Person*);