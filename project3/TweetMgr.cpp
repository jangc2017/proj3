// File name: TweetMgrTest.cpp
// Author: Christopher Jang
// VUnetid: jangc
// Email: christopher.jang@vanderbilt.edu
// Class: CS2201
// Date: 10/01/2022
// Honor statement: I attest that I understand the honor code for this class and have neither given
// nor received any unauthorized aid on this assignment
// Assignment Number: 3
// Description: These methods implement the TweetMgr class


#include "TweetMgr.h"
#include <string>
#include <stdexcept>
#include <cassert>

// Default Constructor
// Create an empty collection (one with zero Tweets)
TweetMgr::TweetMgr():numTweets(0),tweetList(nullptr) {
}


// Copy ctor
TweetMgr::TweetMgr(const TweetMgr &rhs) : numTweets(rhs.numTweets),tweetList(nullptr) {
    if(rhs.tweetList != nullptr){
        tweetList = new TweetNode;
        tweetList -> tweet = rhs.tweetList -> tweet;
        tweetList -> next = nullptr;
        TweetNodePtr newPtr = tweetList;
        for(TweetNodePtr origptr=rhs.tweetList->next; origptr!=nullptr; origptr=origptr->next){
            newPtr ->next = new TweetNode;
            newPtr = newPtr->next;
            newPtr->tweet = origptr->tweet;
            newPtr->next = nullptr;
        }
    }
}


// Assignment operator
const TweetMgr &TweetMgr::operator=(const TweetMgr &rhs) {
    if(this != &rhs){
        TweetMgr tmp(rhs);
        std::swap(tweetList,tmp.tweetList);
        std::swap(numTweets,tmp.numTweets);
    }
    return *this;
}

// Destructor
TweetMgr::~TweetMgr() {
    while(tweetList != nullptr){
        TweetNodePtr tmp = tweetList;
        tweetList = tweetList->next;
        delete tmp;
    }
    numTweets = 0;
}


// getnumTweets
// Return the total number of Tweets in the collection
size_t TweetMgr::getNumTweets() const {
    return numTweets;
}


// insert(const Tweet &t)
//
// Purpose: add/insert a Tweet to the list of Tweet objects
// Parameters: Tweet t - the Tweet to be added
// Returns: size_t - the index position of the inserted Tweet
//
// Behavior:
// 1. In case of the list being empty: insert as the first element
// 2. In case of a non-empty list: insert the Tweet in sorted
//    order by timestamp
// 3. In case of already existing Tweet with same timestamp: insert new tweet
//    after (behind) the existing one
// 4. Return the index of the inserted tweet, using zero-based indexing
// Note: Normally this method would be a void method and not return any value. We have it
// return the index of where the tweet was inserted so that we can verify that the tweet
// was inserted in the correct position in the list.
size_t TweetMgr::insert(const Tweet &t) {
    size_t count (0);
    TweetNodePtr newnode = new TweetNode;
    newnode->tweet = t;
//    if(tweetList == nullptr){
//        tweetList = newnode;
//        numTweets++;
//        return 0;
//    }
//    else{
//        TweetNodePtr prev(nullptr);
//        TweetNodePtr cur  (tweetList);
//        while(cur->next != nullptr){
//            count++;
//            if(temp->next->tweet.getTimestamp() > t.getTimestamp()){
//                TweetNodePtr nextnext = temp->next;
//                temp ->next = newnode;
//                temp->next->next = nextnext;
//                numTweets++;
//                break;
//            }
//            else temp = temp->next;
//        }
//        if(temp->next == nullptr){
//            temp->next = newnode; // if reaches the end, insert at the end
//            numTweets++;
//        }
    TweetNodePtr prev (nullptr);
    TweetNodePtr cur (tweetList);
    while(cur != nullptr && cur->tweet.getTimestamp()<=newnode->tweet.getTimestamp()) {
        count++;
        prev = cur;
        cur = cur->next;
    }
    if(prev==nullptr){
        tweetList = newnode;
    }
    else{
        prev->next = newnode;
    }
    newnode->next = cur;
    numTweets++;

    return count;
}////checked


// retrieve(size_t index)
//
// Purpose:    returns the Tweet at the specified index in the collection,
//             throw exception if index is bad
// Parameters: size_t index - the index of the desired Tweet; using zero-based indexing
// Returns:    Tweet  - the Tweet at the specified index
//
// Behavior:
// 1. If the index is invalid, throw an std::invalid_argument exception
// 2. Otherwise, return the Tweet at the specified index
// NOTE: Normally a TweetMgr class would not support indexing to access tweets, as the user
// does not think of storing tweets by index. We have only added this method so that we
// can verify that your insert method works correctly. You should not call this method
// in any code, as it only exists for testing and should later be deleted.
Tweet TweetMgr::retrieve(size_t index) const {

    if(index >= numTweets){
        throw std::invalid_argument("Invalid Index");
    }
    TweetNodePtr cur (tweetList);
    for(size_t i=0;i<index;i++) {
        cur = cur->next;
    }
    return cur->tweet;//// checked
}


// exists(size_t ts)
//
// Purpose: Returns true if a tweet exists at the given timestamp
// Parameters: size_t ts - the timestamp we are supposed to check
// Returns:    bool - true if such a Tweet exists, otherwise false
bool TweetMgr::exists(size_t ts) const {
    TweetNodePtr cur (tweetList);
    while(cur != nullptr){
        if(cur->tweet.getTimestamp() == ts){
            return true;
        }
        cur = cur->next;
    }return false;
}


// count(const string& sender)
//
// Purpose:    Returns the number of tweets from a specified sender
// Parameters: string sender - the author of the Tweets we are to count
// Returns:    size_t - the number of tweets from the specified sender
size_t TweetMgr::count(const std::string& sender) const {
    TweetNodePtr cur = tweetList;
    size_t count = 0;
    if(numTweets == 0){
        return 0;
    }
    while(cur!= nullptr){
        if(cur->tweet.getUser() == sender){
            count++;
        }
        cur = cur->next;
    }return count;
}


// getTweets()
//
// Purpose:    Return a string of all Tweets
// Parameters: None
// Returns:    string - containing all the Tweets in sorted order with each & every
//             Tweet followed immediately by a newline character.
//             Returns an empty string if the collection is empty
std::string TweetMgr::getTweets() const {
    std::string result = "";
    TweetNodePtr cur = tweetList;
    //size_t i =0;i<numTweets;i++
    while(cur!=nullptr){
        result += cur->tweet.toString() + "\n";
        cur = cur->next;
    }
    return result;
}


// getTweets(const string &sender)
//
// Purpose:    Return a string of all Tweets sent by the specified sender
// Parameters: string sender - the author of the Tweets we are supposed to return
// Returns:    string     - containing all the Tweets from the specified author, in sorted order,
//                          with each Tweet followed immediately by a newline character.
//
// Behavior:
// 1. Finds all Tweets from the specified sender (matching sender is case sensitive)
// 2. If no such Tweets are found, returns an empty string
// 3. If Tweets are found, append them on the return string in sorted order each
//    followed by a newline character.
std::string TweetMgr::getTweets(const std::string &sender) const {
    std::string result;
    TweetNodePtr cur (tweetList);
    while(cur != nullptr) {
        if(cur->tweet.getUser() == sender){
            result += cur->tweet.toString() + "\n";
        }
        cur = cur->next;
    }
    return result;
}

// getTweets(size_t ts)
//
// Purpose:    Return a string of all Tweets for a given timestamp
// Parameters: size_t ts - the timestamp we are supposed to check for match
// Return:     string - containing all the matching Tweets, in sorted order,
//             each tweet followed immediately by a newline character.
//
// Behavior:
// 1. Finds all Tweeets with the given timestamp
// 2. If no match is found, returns an empty string
// 3. If matches are found, append them on the return string in sorted order each
//    followed by a newline character.
//
// Note: see insert() for the definition of sorted order of Tweets with the same timestamp.
std::string TweetMgr::getTweets(size_t ts) const {
    std::string result;
    result = getTweets(ts,ts);
    return result;
}


// getTweets(size_t ts1, size_t ts2)
//
// Purpose:    Return a string of all Tweets in a range of two given timestamps
// Parameters: ts1 and ts2 (the range of timestamps)
// Return:     string containing all the matching Tweets, in sorted order,
//             each Tweet followed immediately by a newline character.
//
// Behavior:
// 1. If the collection contains no timestamps in the given range, return an empty string
// 2. Create a string containing all the Tweets, in sorted order, which are later
//    than or equal to the smaller of the two timestamps and are earlier than or equal to
//    the larger of the two timestamps, with each tweet followed immediately by a
//    newline character.
// Note: the relative order of ts1 and ts2 is unknown
std::string TweetMgr::getTweets(size_t ts1, size_t ts2) const {
    std::string result;
    TweetNodePtr cur (tweetList);
    if(ts1>ts2) {
        std::swap(ts1, ts2);
    }
    while(cur != nullptr && cur->tweet.getTimestamp() <=ts2){
        if(cur->tweet.getTimestamp() >= ts1 && cur->tweet.getTimestamp() <= ts2) {
            result += cur->tweet.toString() + "\n";
        }
        cur = cur->next;
    }
    return result;
}

// deleteTweets()
//
// Purpose:    Deletes all Tweets from the collection
// Parameters: None
// Return:     size_t - the number of Tweets deleted (a size_t value)
size_t TweetMgr::deleteTweets() {
    TweetNodePtr cur (tweetList);
    TweetNodePtr next (nullptr);
    size_t total = numTweets;
    if(tweetList == nullptr){
        return 0;
    }
    else{
        while(cur!=nullptr){
            next = cur->next;
            delete cur;
            cur = next;

        }
        tweetList = nullptr;
        numTweets = 0;
        return total;

    }
}

// deleteTweets(const string &sender)
//
// Purpose:    Delete all Tweets from the specified sender
// Parameters: string sender - author of tweets to be deleted, comparison is case sensitive
// Return:     size_t - number of Tweets deleted (size_t value)
size_t TweetMgr::deleteTweets(const std::string &sender) {
    TweetNodePtr prev(nullptr);
    TweetNodePtr cur(tweetList);
    size_t count (0);
    while(cur!= nullptr){
        if(cur->tweet.getUser() == sender){
            if(prev==nullptr){
                tweetList = cur->next;
                delete cur;
                cur = tweetList;
                count++;
            }
            else{
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
                count++;
            }
        }
        else{
            prev = cur;
            cur = cur->next;
        }
    } return count;
}


// deleteTweets(size_t ts)
//
// Purpose:    Deletes all Tweets whose timestamps are earlier than the parameter ts
// Parameters: size_t ts - the specified timestamp
// Return:     size_t - the number of Tweets deleted (a size_t value)
//
// Notes:
// 1. If there are no timestamps earlier than ts, no deletions will be performed and
//    zero is returned
size_t TweetMgr::deleteTweets(size_t ts) {
    size_t count (0);
    if(ts==0){
        return 0;
    }
    else{
        count = deleteTweets(0,ts-1);
    }
    return count;
}


// deleteTweets(size_t ts1, size_t ts2)
//
// Purpose:    Deletes all Tweets between a range of two given timestamps
// Parameters: ts1 and ts2 - the range of timestamps
// Return:     size_t - number of Tweets deleted (size_t value)
//
// Behavior:
// 1. If the collection contains no timestamps in the given range, perform no deletions
//    and return zero
// 2. Delete all Tweets which are later than or equal to the smaller of the two
//    timestamps and are earlier than or equal to the larger of the two timestamps.
//    Return the number deleted.
// Note: the relative order of ts1 and ts2 is unknown
size_t TweetMgr::deleteTweets(size_t ts1, size_t ts2) {
    TweetNodePtr prev(nullptr);
    TweetNodePtr cur(tweetList);
    size_t count (0);

    if(ts1>ts2){
        std::swap(ts1,ts2);
    }

    while(cur != nullptr && cur->tweet.getTimestamp() <= ts2){
        if(cur->tweet.getTimestamp()>=ts1 && cur->tweet.getTimestamp()<=ts2){
            if(prev == nullptr){
                tweetList = cur->next;
                delete cur;
                cur = tweetList;
                count++;
            }
            else {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
                count++;
            }
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    } return count;
}


// merge(const TweetMgr& tm)
//
// Purpose:    Merge a received tweet collection into this collection
// Parameters: TweetMgr tm (the TweetMgr collection to be merged)
// Return:     None
//
// Behavior:
// 1. Add each tweet of the parameter TweetMgr to the object TweetMgr;
//    may result in duplicate entries if both TweetMgrs had the same tweets.
// 2. All tweets that are added remain in the same order as they appeared in the
//    parameter TweetMgr.
// 3. Any added tweet with the same timestamp of an existing tweet is added
//    after (behind) the existing tweet.
// 4. You are guaranteed that the parameter TweetMgr object tm is a different
//    TweetMgr object than the ‘this’ TweetMgr object.
//void TweetMgr::merge(const TweetMgr& tm) {
//    TweetNodePtr dummy = new TweetNode;
//    TweetNodePtr curr(dummy);
//    TweetNodePtr objCur(tweetList);
//    TweetNodePtr otherCur(tm.tweetList);
//    while (objCur != nullptr && otherCur != nullptr) {
//        if (objCur->tweet.getTimestamp() <= otherCur->tweet.getTimestamp()) {
//            curr->next = objCur;
//            objCur = objCur->next;
//        } else {
//            TweetNodePtr newNode = new TweetNode;
//            newNode->tweet = Tweet(otherCur->tweet.getTimestamp(),
//                                   otherCur->tweet.getUser(), otherCur->tweet.getText());
//            curr->next = newNode;
//            otherCur = otherCur->next;
//        }
//        curr = curr->next;
//    }
//    if (objCur != nullptr) {
//        curr->next = objCur;
//    }
//    while (otherCur != nullptr) {
//        TweetNodePtr newNode = new TweetNode;
//        newNode->tweet = Tweet(otherCur->tweet.getTimestamp(),
//                               otherCur->tweet.getUser(), otherCur->tweet.getText());
//        curr->next = newNode;
//        otherCur = otherCur->next;
//        curr = curr->next;
//    }
//    tweetList = dummy->next;
//    delete dummy;
//    numTweets += tm.numTweets;
//}
void TweetMgr::merge(const TweetMgr& tm){
    TweetNodePtr insertail = tweetList;
    TweetNodePtr insertPrev = nullptr;
    TweetMgr tw(tm);
    TweetNodePtr other = tm.tweetList;

    if(insertail == nullptr && other != nullptr){//this is empty and tm is not empty
        tweetList = other;
        numTweets += tw.numTweets;
        return;
    }
    else if(other == nullptr){//this is not empty and tm is empty
        return;
    }
    while(insertail != nullptr && other != nullptr){
        if(other->tweet.getTimestamp() < insertail->tweet.getTimestamp()){
            if(insertPrev == nullptr){
                tweetList = other;
            }
            else{
                insertPrev -> next = other;
            }
            TweetNodePtr nextother = other->next;
            other->next = insertail;

            insertPrev = other;
            other = nextother;
        }
        else{
            if(insertail->next != nullptr){
                insertPrev = insertail;
                insertail = insertail->next;
            }
            else{
                insertail ->next = other;
                numTweets += tm.numTweets;

                return;
            }

        }
    }
    if(other != nullptr){
        insertPrev->next = other;
    }
    numTweets += tm.numTweets;
}
//void TweetMgr::merge(const TweetMgr& tm) {
//    TweetNodePtr prev (nullptr);//current position
//    TweetNodePtr cur (tweetList);//original linked list
//    TweetNodePtr addnext (nullptr);
//    TweetNodePtr add (tm.tweetList);//adding linked list
//
//    while(cur!=nullptr && add!=nullptr){//condition where cu is null but add isnt, vice versa
//        if(cur->tweet.getTimestamp() > add->tweet.getTimestamp()){
//            if(prev == nullptr){//If first of add should be added to the head
//                tweetList = add;
//                prev = add;
//                add = add->next;
//            }
//            else{
//                addnext = add->next;
//                prev->next = add;
//                add->next = cur;
//                prev = add;
//                add = addnext;
//            }
//        }
//        else{
//            prev = cur;
//            cur = cur->next;
//        }
//    } numTweets += tm.numTweets;
//}