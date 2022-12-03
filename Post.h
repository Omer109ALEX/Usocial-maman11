#pragma once


#ifndef Post_H_
#define Post_H_

#include <string>
#include "Media.h"

class Post {

	std::string text;
	Media* media;


public:
	Post(std::string);
	Post(std::string, Media* media);
	~Post();
	std::string getText();
	Media* getMedia();


};

#endif /* #define Post_H_ */