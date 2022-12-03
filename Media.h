#pragma once

#ifndef Media_H_
#define Media_H_

class Media {

public:
	virtual void display() = 0;

};

class Audio : public Media
{
public:
    void display();
};

class Video : public Media
{
public:
    void display();
};

class Photo : public Media
{
public:
    void display();
};

#endif /* #define Media_H_ */