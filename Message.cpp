#include "Message.h"

Message::Message(std::string text)
{
	if (text.empty())
		throw std::exception("Can't creat empty message\n");
	else
		this->text = text;
}

std::string Message::getText()
{
	return this->text;
}
