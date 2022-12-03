#include "Post.h"
#include "Media.h"


Post::Post(std::string text)
{
    if (text.empty())
        throw std::exception("Can't creat empty post\n");
    else
        this->text = text;
}

Post::Post(std::string text, Media* media)
{
    if (text.empty() && (media == NULL))
        throw std::exception("Can't creat empty post with no media\n");
    else {
        this->text = text;
        this->media = media;
    }
    
}

Post::~Post() {
    delete this->media;
}

std::string Post::getText()
{
    return this->text;
}

Media* Post::getMedia()
{
    return this->media;
}
