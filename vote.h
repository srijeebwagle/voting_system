#pragma once

class Party{
private:
    char* name;
    char* symbol;
public:

    Party();
    ~Party();

    friend void votingInterface(Party*, char*&);
    friend void readParty(Party*);
};