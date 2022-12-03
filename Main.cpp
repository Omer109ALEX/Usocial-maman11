#include "USocial.h"
#include "User.h"

#include <exception>
#include <iostream>

int main()
{
	USocial us;

	User* u1 = us.registerUser("Liron");
	User* u2 = us.registerUser("Yahav");
	User* u3 = us.registerUser("Shachaf");
	User* u4 = us.registerUser("Tsur", true);
	User* u5 = us.registerUser("Elit");
	u1->post("Hello world!");
	u2->post("I'm having a great time here :)", new Audio());
	u3->post("This is awesome!", new Photo());
	u5->addFriend(u1);
	u5->addFriend(u2);
	u5->viewFriendsPosts(); // should see only u1, u2 s' posts
	u4->sendMessage(u5, new Message("Buy Falafel!"));
	u5->viewReceivedMessages();
	try
	{
		u3->sendMessage(u5, new Message("All your base are belong to us"));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	u5->viewReceivedMessages();
	u3->addFriend(u5);
	u3->sendMessage(u5, new Message("All your base are belong to us"));
	u5->viewReceivedMessages();

	//another checks i added:
	us.removeUser(u1);

	try
	{
		u3->addFriend(u5);//try to add but already a friend
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		u3->addFriend(u3);//try to add myself as a friend
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		u3->sendMessage(u3, new Message("hello"));//try to send myself a message
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		u3->removeFriend(u3);//try remove not a friend
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		u3->post("");//try to post empty  post
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		u3->post("", NULL);//try to post empty post with no media
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}


	return 0;
}