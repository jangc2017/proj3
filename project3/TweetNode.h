// CS2201 Vanderbilt University
// Prof. Roth

#ifndef TWEETNODE_H
#define TWEETNODE_H

#include "Tweet.h"

// the structure of a linked list node contains a single Tweet and a next pointer
struct TweetNode
{
    Tweet tweet;
    TweetNode *next;
};

typedef TweetNode* TweetNodePtr;


#endif //TWEETNODE_H
