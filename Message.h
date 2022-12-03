#pragma once


#ifndef Message_H_
#define Message_H_

#include <string>

class Message {

	std::string text;

public:
	Message(std::string);
	std::string getText();

};

#endif /* #define Message_H_ */