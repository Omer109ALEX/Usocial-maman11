#pragma once

#ifndef USocial_H_
#define USocial_H_

#include <map>
#include <string>
#include <algorithm>

class User;

class USocial
{
private:
    std::map<const unsigned long, User*> users;
    unsigned long lastUsedId;

public:
    User* registerUser(std::string, bool);
    User* registerUser(std::string);
    void removeUser(User*);
    User* getUserById(unsigned long);
};

#endif /* #define USocial_H_ */