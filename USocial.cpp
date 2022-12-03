#include "USocial.h"
#include "User.h"
#include <climits>
#include <iostream>

User* USocial::registerUser(std::string name, bool isBusinessUser)
{
    if (name.length() > 0) {
        if (this->lastUsedId >= ULLONG_MAX) {
            throw std::exception("alredy used maximun numbers of id,so dont have new id to use");
        }
        ++this->lastUsedId;
        User* user;
        if (isBusinessUser) {
            user = new BusinessUser(this, this->lastUsedId, name);
        }
        else {
            user = new User(this, this->lastUsedId, name);
        }

        users.insert(std::pair<const unsigned long, User*>(user->id, user));
        return user;
    }
    return NULL;
}

User* USocial::registerUser(std::string name)
{
	return registerUser(name, false);
}

void USocial::removeUser(User* userToRemove)
{
    std::cout << "Removing user: " << userToRemove->getName() +"\n" << std::endl;
    auto it = users.find(userToRemove->getId());
    if (it != users.end()) {
        for (auto&& user : users) {
            if (user.second->isFriend(userToRemove))
                user.second->removeFriend(userToRemove);
        }
        this->users.erase(userToRemove->id);
        delete userToRemove;
    }
    else
        throw std::exception("Can't remove a User that not connected to the USocial!!!");
}

User* USocial::getUserById(unsigned long id)
{
    auto it = users.find(id);
    if (it != users.end()) {
        return (it->second);
    }
    throw std::exception("User not found!!!");
}
