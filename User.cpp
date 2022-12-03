#include "User.h"

User::User()
{
	this->name = "";//empty constructor
}

User::User(USocial* us, unsigned long id, std::string name)
{
	this->us = us;
	this->id = id;
	this->name = name;
}

User::~User()
{
	// destroy posts - the only "new" objects the User created
	for (auto&& post : posts) {
		delete post;
	}

	//  destroy messages - each user holds pointers to his own recieved messages
	for (auto&& message : recievedMessages) {
		delete message;
	}
}

unsigned long User::getId()
{
	return this->id;
}

std::string User::getName()
{
	return this->name;
}


bool User::isFriend(User* usr)
{
	for (auto x : this->friends) {
		if (x == usr->id) {
			return true;
		}
	}
	return false;
}

void User::addFriend(User* usr)
{
	if (!usr) {
		throw std::exception("Can't add null friend\n");
	}
	else if (this == usr)
		throw std::exception("Can't add yourself as a friend\n");

	else if (this->isFriend(usr))
		throw std::exception("Can't add because hes already in my friend list\n");
	else
		this->friends.push_back(usr->id);
}

void User::removeFriend(User* usr)
{
	if (this->isFriend(usr)) {
		friends.remove(usr->id);
	}
	else
		throw std::exception("Can't remove someone that is not your friend\n");
}


void User::post(std::string text)
{
	Post* post = new Post(text);
	posts.push_back(post);
}

void User::post(std::string text, Media* media)
{
	Post* post = new Post(text, media);
	posts.push_back(post);
}

std::list<Post*> User::getPosts()
{
	return this->posts;
}

void User::viewFriendsPosts()
{
	std::cout << this->name << " viewing posts by friends:" << std::endl;
	for (auto const& friendId : this->friends) {
		try {
			auto userFriend = us->getUserById(friendId);
			std::cout << userFriend->name << " posted:" << std::endl;
			for (auto const& post : userFriend->posts) {
				std::cout << post->getText() << std::endl;
				if (post->getMedia() != NULL) {
					post->getMedia()->display();
				}
			}
		}
		catch (const std::exception& e)
		{
			std::cout << "error: " << e.what() << std::endl;
		}
	}
	std::cout << "\n" << std::endl; 
}

void User::recieveMessage(Message* message)
{
	recievedMessages.push_back(message);
}

void User::sendMessage(User* user, Message* message)
{
	auto it = find(friends.begin(), friends.end(), user->id);
	if (it != friends.end()) {
		user->recieveMessage(message);
	}
	else {
		throw std::runtime_error(this->name + " tried sending a message to a user who is not a friend!\n");
	}
}

void User::viewReceivedMessages()
{
	std::cout << name << " viewing recieved messagess:" << std::endl;
	for (auto const& message : recievedMessages) {
		std::cout << message->getText() << std::endl;
	}
	std::cout << "\n" << std::endl;
}

BusinessUser::BusinessUser(USocial* us, unsigned long id, std::string name)
{
	this->us = us;
	this->id = id;
	this->name = name;
}

void BusinessUser::sendMessage(User* usr, Message* message)
{
	usr->recieveMessage(message);
}
