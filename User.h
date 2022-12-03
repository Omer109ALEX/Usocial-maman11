#pragma once

#ifndef User_H_
#define User_H_

#include "Post.h"
#include "Message.h"

#include <iostream>
#include <string>
#include <list>
#include "USocial.h"

class User
{
    friend class USocial;

protected:
    USocial* us;
    unsigned long id;
    std::string name;
    std::list<unsigned long> friends;
    std::list<Post*> posts;
    std::list<Message*> recievedMessages;
    bool isFriend(User*);

    User();
    User(USocial*, unsigned long, std::string);
    ~User();

public:
    unsigned long getId();
    std::string getName();
    void addFriend(User*);
    void removeFriend(User*);
    void post(std::string);
    void post(std::string, Media*);
    std::list<Post*> getPosts();
    void viewFriendsPosts();
    void recieveMessage(Message*);
    virtual void sendMessage(User*, Message*);
    void viewReceivedMessages();
};

class BusinessUser : public User {
    friend class USocial; 
    BusinessUser(USocial*, unsigned long, std::string);
    void sendMessage(User*, Message*);
};

#endif /* #define User_H_ */