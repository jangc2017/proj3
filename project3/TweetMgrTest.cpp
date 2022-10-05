// File name: TweetMgrTest.cpp
// Author: Christopher Jang
// VUnetid: jangc
// Email: christopher.jang@vanderbilt.edu
// Class: CS2201
// Date: 10/01/2022
// Honor statement: I attest that I understand the honor code for this class and have neither given
// nor received any unauthorized aid on this assignment
// Assignment Number: 3
// Description: This program will test the TweetMgr class

#include <iostream>
#include <string>
#include <stdexcept>
#include "TweetMgr.h"

std::string fail = "failed";
size_t MAX_TIMESTAMP = 100;
TweetMgr emptyTweetMgr();//create an empty TweetMgr
TweetMgr createTweetMgr();//create TweetMgr from t1~t5 timestamp 0,1,5,3,17
void TestTweetMgr();//Test if TweetMgr() successfully creates an empty class
void TestgetNumTweets();
void Testinsert();
void Testretrieve();
void Testexists();
void Testcount();
void TestgetTweets();
void TestgetTweetssender();
void TestgetTweetstimestamp();
void TestgetTweetsrange();
void TestdeleteTweets();
void TestdeleteTweetstimestamp();
void TestdeleteTweetssender();
void TestdeleteTweetsrange();
void Testmerge();
void Testasgnop();
void Testcopyctor();

int main() {

    TestTweetMgr();//Test if TweetMgr() successfully creates an empty class
    TestgetNumTweets();
    Testcopyctor();
    Testinsert();
    Testretrieve();
    Testexists();
    Testcount();
    TestgetTweets();
    TestgetTweetssender();
    TestgetTweetstimestamp();
    TestgetTweetsrange();
    TestdeleteTweets();
    TestdeleteTweetstimestamp();
    TestdeleteTweetssender();
    TestdeleteTweetsrange();
    Testmerge();
    Testasgnop();


//    TweetMgr tw2;
//    Tweet ta(0,"@Jack","First Tweet");
//    Tweet tb(1,"@Eddie","Second Tweet");
//    Tweet tc(5,"@Chris","Third Tweet");
//    Tweet td(3,"@Eddie","Wassup");
//    Tweet te(17,"@Jack","Hey Eddie");
//    Tweet tf(1,"@Chris","Hello World");
//    Tweet tk(20,"@Jack","Hey Eddie");
//
//
//
//    tw2.insert(ta);
//    tw2.insert(tb);
//    tw2.insert(tc);
//    tw2.insert(td);
//    tw2.insert(tf);

//
//    TweetMgr tw3;
//    tw3.insert(td);
//
//
//    tw2.getTweets();
//    tw2.insert(ta);
//    tw2.insert(ta);
//    tw2.insert(ta);
//    tw2.insert(te);
//    tw2.insert(tk);
//    std::cout<<tw2.getNumTweets()<<std::endl;
//    std::cout<<tw2.getTweets()<<std::endl;
//    tw2.deleteTweets(19,21);
//    std::cout<<tw2.getNumTweets()<<std::endl;
//    std::cout<<tw2.getTweets()<<std::endl;

}
TweetMgr emptyTweetMgr(){
    TweetMgr tw1;
    return tw1;
}

TweetMgr createTweetMgr(){
    TweetMgr tw2;
    Tweet ta(0,"@Jack","First Tweet");
    Tweet tb(1,"@Eddie","Second Tweet");
    Tweet tc(5,"@Chris","Third Tweet");
    Tweet td(3,"@Eddie","Wassup");
    Tweet te(17,"@Jack","Hey Eddie");
    Tweet tf(1,"@Chris","Hello World");


    tw2.insert(ta);
    tw2.insert(tb);
    tw2.insert(tc);
    tw2.insert(td);
    tw2.insert(te);
    tw2.insert(tf);
    return tw2;
}

void TestTweetMgr(){
    std::cout<<"Testing TweetMgr()..."<<std::endl;
    TweetMgr tw1;
    if(tw1.getNumTweets()!=0){
        std::cout<<fail<<std::endl;
    }

}//CHECKED


void Testcopyctor(){
    std::cout<<"Testing copy constructor..."<<std::endl;
    TweetMgr tw2 = createTweetMgr();
    TweetMgr tw1 (tw2);
    if(tw1.getTweets() != tw2.getTweets() || tw1.getNumTweets() != tw2.getNumTweets()){
        std::cout<<fail<<std::endl;
    }
    Tweet t(15,"Chris","Hi");
    tw2.insert(t);
    if(tw1.getTweets() == tw2.getTweets() || tw1.getNumTweets() == tw2.getNumTweets()){
        std::cout<<fail<<std::endl;
    }

}

void Testasgnop(){
    std::cout<<"Testing assignment operator..."<<std::endl;
    TweetMgr tw2 = createTweetMgr();
    TweetMgr tw1;
    tw1 = tw2;
    if(tw1.getTweets() != tw2.getTweets()){
        std::cout<<fail<<std::endl;
    }

    Tweet t(15,"Chris","Hi");
    tw2.insert(t);
    if(tw1.getTweets() == tw2.getTweets()){
        std::cout<<fail<<std::endl;
    }

    tw1 = tw2;
    if(tw1.getTweets() != tw2.getTweets()){
        std::cout<<fail<<std::endl;
    }
}


void Testmerge(){
    std::cout<<"Testing merge()..."<<std::endl;
    Tweet t1(0,"@Chris1","Hello");
    Tweet t2(1,"@Jackt1","Hellot1");
    Tweet t3(0,"@Chris2","HelloT2");
    Tweet t4(1,"@Jackt2","HelloY2");
    TweetMgr tw1;
    TweetMgr tw2;
    TweetMgr twe,twf;
    twf.insert(t1);
    twf.insert(t2);
    twf.merge(twe);

    if(twf.getTweets() != t1.toString() + "\n" + t2.toString() + "\n"){
        std::cout<<fail<<std::endl;
    }

    TweetMgr tww, twg;
    tww.insert(t1);
    tww.insert(t2);
    twg.merge(tww);

    if(twg.getTweets() != t1.toString() + "\n" + t2.toString() + "\n"){
        std::cout<<fail<<std::endl;
    }

    tw1.insert(t1);
    tw1.insert(t2);
    tw2.insert(t3);
    tw2.insert(t4);
    tw1.merge(tw2);
    if(tw1.getNumTweets() != 4){
        std::cout<<fail<<std::endl;
    }

    if(tw1.getTweets() != t1.toString() + "\n" + t3.toString() + "\n" + t2.toString() + "\n" +
                          t4.toString() + "\n"){
        std::cout<<"FAILED"<<std::endl;
    }

    TweetMgr tw3,tw4;
    for(int i=0;i<50;i++){
        tw3.insert(t1);
    }
    for(int i=0;i<15;i++){
        tw4.insert(t3);
    }
    tw3.merge(tw4);
    if(tw3.getNumTweets()!=65){
        std::cout<<fail<<std::endl;
    }

}


void TestgetNumTweets(){
    std::cout<<"Testing getNumTweets()..."<<std::endl;
    TweetMgr tw1 = emptyTweetMgr();
    if(tw1.getNumTweets() != 0){
        std::cout<<fail<<std::endl;
        std::cout<<"getNumTweets() returned "<<tw1.getNumTweets()<<"for an empty TweetMgr"
                 <<std::endl;
    }

    TweetMgr tw2 = createTweetMgr();
    if(tw2.getNumTweets() != 6){
        std::cout<<fail<<std::endl;
        std::cout<<"getNumTweets() returned "<<tw2.getNumTweets()<<"for TweetMgr with 6 tweets"
                 <<std::endl;
    }

    Tweet t(0,"@Test","Test");
    for(size_t i =0;i<50;i++){
        tw1.insert(t);
    }
    if(tw1.getNumTweets()!=50){
        std::cout<<fail<<std::endl;
    }
}//CHECKED

void Testinsert(){
    std::cout<<"Testing insert()..."<<std::endl;
    TweetMgr tw1 = emptyTweetMgr();
    TweetMgr tw2 = createTweetMgr();
    Tweet t1(4,"@test","Adding tweet to t1");
    Tweet t2(0,"@Aiden","Ah, Test Tweets");

    //Testing Behavior 1
    tw1.insert(t1);
    if(tw1.retrieve(0) != t1) {
        std::cout << "No tweet has been added to the empty TweetMgr" << std::endl;
    }

    // Testing Behavior 3
    tw2.insert(t1);
    if(tw2.retrieve(4)!=t1){//The index of t1 in retrieve is 4, as it
        // is the fifth tweet in timestamp order
        std::cout<<"Insert function has not inserted accurate tweet"<<std::endl;
    }

    //Testing behavior 4
    tw2.insert(t2);
    if(tw2.getTweets(0)!=tw2.retrieve(0).toString()+"\n"+t2.toString()+"\n"){
        std::cout<<fail<<std::endl;
    }//Since tw2 has two tweets at timestamp 0, tw2,getTweets(0) retrieves two Tweets:
    //First one should be tw2.retrieve(0), the one that was originally added,
    //Second one should be t2.
    //since getTweets() returns as a string format, retrieve and t2 should also be converted to
    // string to compare, and with "\n" added to each line as well.

    //Testing Behavior 5
    if(tw2.insert(t2)!=2){
        std::cout<<fail<<std::endl;
    }


    TweetMgr tw4;
    for(int i=0;i<51;i++){
        tw4.insert(t1);
    }
    if(tw4.getNumTweets() != 51){
        std::cout<<fail<<std::endl;
    }
    std::string s2;
    for(int i=0;i<51;i++){
        s2 += tw4.retrieve(i).toString()+"\n";
    }
    if(tw4.getTweets() != s2){
        std::cout<<fail<<std::endl;
    }

}//CHECKED

void Testretrieve(){
    TweetMgr tw1 = emptyTweetMgr();
    Tweet t1(1,"@Chris","Test");

    std::cout<<"Testing retrieve()..."<<std::endl;

    //Valid index
    tw1.insert(t1);
    if(tw1.retrieve(0)!=t1){
        std::cout<<"retrieve function did not retrieve the tweet added"<<std::endl;
    }

    //Invalid Index
    try {
        tw1.retrieve(3);
        std::cout<<"This msg should not be shown, as we are accessing invalid index"<<std::endl;
    }
    catch(std::invalid_argument &excpt){
        std::cout<<"Exception successfully thrown & caught: "<<excpt.what()<<std::endl;
    }

}//CHECKED

void Testexists(){
    std::cout<<"Testing exists()..."<<std::endl;
    TweetMgr tw1 = emptyTweetMgr();
    TweetMgr tw2 = createTweetMgr();

    //testing on empty TweetMgr
    if(tw1.exists(0)){
        std::cout<<"exists() produced an error; returned true for invalid index"<<std::endl;
    }

    size_t ts1 = 0;
    //testing on a valid timestamp
    if(!tw2.exists(ts1)){
        std::cout<<"exists() produced an error; returned false for an existing Tweet"<<std::endl;
    }

    size_t ts2 = 25;
    //testing on a valid timestamp
    if(tw2.exists(ts2)){
        std::cout<<"exists() produced an error; returned true for an invalid index "<<std::endl;
    }


}//CHECKED

void Testcount(){
    std::cout<<"Testing count()..."<<std::endl;
    TweetMgr tw1 = emptyTweetMgr();
    TweetMgr tw2 = createTweetMgr();

    std::string user = "@Jack";//User string that I wish to test

    //testing on empty TweetMgr
    if(tw1.count(user)!=0){
        std::cout<<"count() produced a non-zero value for an empty TweetMgr"<<std::endl;
    }

    //Testing on non-empty TweetMgr & existing sender
    if(tw2.count(user)!=2){
        std::cout<<"Expected number of tweet from" << user <<" to be 2, count() returned: "
                 <<tw2.count(user)<<std::endl;
    }

    user = "@jack";
    if(tw1.count(user)!=0){
        std::cout<<"count() produced a non-zero value for an invalid user"<<std::endl;
    }

    user = "Jack";
    if(tw1.count(user)!=0){
        std::cout<<"count() produced a non-zero value for an invalid user"<<std::endl;
    }

    //Testing on non-empty TweetMgr & non-existing sender
    if(tw2.count("@Nobody")!=0){
        std::cout<<"non-zero returned from a non-existing sender; count returned: "
                 <<tw2.count("@Nobody")<<std::endl;
    }
}//CHECKED

void TestgetTweets(){
    std::cout<<"Testing getTweets()..."<<std::endl;
    TweetMgr tw1 = emptyTweetMgr();
    TweetMgr tw2 = createTweetMgr();

    //Testing with empty TweetMgr
    if(!tw1.getTweets().empty()){
        std::cout<<"getTweets() returned the following non-empty string from an empty TweetMgr: "
                 <<tw1.getTweets()<<std::endl;
    }

    //Testing with non-empty TweetMgr
    if(tw2.getTweets()!=tw2.retrieve(0).toString()+"\n"+tw2.retrieve(1).toString()+"\n"
                        +tw2.retrieve(2).toString()+"\n"+tw2.retrieve(3).toString()+"\n"
                        +tw2.retrieve(4).toString()+"\n"+
                        tw2.retrieve(5).toString()+"\n"){
        std::cout<<"getTweets() returned string that is not equivalent to its content of TweetMgr"
                 <<std::endl;
    }
}//CHECKED

void TestgetTweetssender(){
    std::cout<<"Testing getTweets(sender)..."<<std::endl;
    TweetMgr tw1 = emptyTweetMgr();

    //Testing against empty string
    if(!tw1.getTweets("@Nobody").empty()){
        std::cout<<fail<<std::endl;
    }

    Tweet t1(0,"@Chris","Hi");
    Tweet t2(1,"@Chris","anyone there?");
    tw1.insert(t1);
    tw1.insert(t2);
    //Testing against non-empty string, invalid sender
    if(!tw1.getTweets("@Nobody").empty()){
        std::cout<<fail<<std::endl;
    }

    //Testing against non-empty string, valid sender
    std::string user;
    user = tw1.retrieve(0).getUser();
    if(tw1.getTweets(user)!=tw1.retrieve(0).toString()+"\n"
                            +tw1.retrieve(1).toString()+"\n"){
        std::cout<<fail<<std::endl;
    }
    //Testing for case sensitivity
    if(!tw1.getTweets("@chris").empty()){
        std::cout<<fail<<std::endl;
    }
    //Testing for absense of "@"
    if(!tw1.getTweets("Chris").empty()){
        std::cout<<fail<<std::endl;
    }
}//CHECKED

void TestgetTweetstimestamp(){
    std::cout<<"Testing getTweets(ts)..."<<std::endl;
    TweetMgr tw1 = emptyTweetMgr();
    TweetMgr tw2 = createTweetMgr();

    //Testing with empty TweetMgr
    for(size_t i = 0;i<MAX_TIMESTAMP;i++)
    {
        if(!tw1.getTweets(i).empty()){
            std::cout<<fail<<std::endl;
        }
    }

    //Testing with non-empty
    for(size_t i=0;i<MAX_TIMESTAMP;i++){
        if(tw2.getTweets(i)!=tw2.getTweets(i,i)) {
            std::cout<<fail<<std::endl;
        }
    }


}//CHECKED

void TestgetTweetsrange(){
    std::cout<<"Testing getTweets(ts1,ts2)..."<<std::endl;
    TweetMgr tw1 = emptyTweetMgr();
    TweetMgr tw2 = createTweetMgr();

    //Testing with empty TweetMgr
    if(!tw1.getTweets(0,MAX_TIMESTAMP).empty()){
        std::cout<<fail<<std::endl;
    }

    //Testing full range with non-empty TweetMgr
    if(tw2.getTweets(0,MAX_TIMESTAMP)!=tw2.getTweets()){
        std::cout<<fail<<std::endl;
    }

    //Testing partial range with non-empty TweetMgr
    size_t ts1 = 0;
    size_t ts2 = 3; // Range of timestamp that I wish to check
    std::string result; //Expected string output

    for(size_t i=ts1;i<=ts2;i++){
        if(tw2.exists(i)){
            result += tw2.getTweets(i);
        }
    }
    if(tw2.getTweets(ts1,ts2)!=result){
        std::cout<<fail<<std::endl;
    }

    result = "";
    ts1 = 1;
    ts2 = 5; // Range of timestamp that I wish to check

    for(size_t i=ts1;i<=ts2;i++){
        if(tw2.exists(i)){
            result += tw2.getTweets(i);
        }
    }
    if(tw2.getTweets(ts1,ts2)!=result){
        std::cout<<fail<<std::endl;
    }

    result = "";
    ts1 = 5;
    ts2 = 1; // Range of timestamp that I wish to check

    for(size_t i=ts2;i<=ts1;i++){
        if(tw2.exists(i)){
            result += tw2.getTweets(i);
        }
    }
    if(tw2.getTweets(ts1,ts2)!=result){
        std::cout<<fail<<std::endl;
    }

    result = "";
    ts1 = 25;
    ts2 = 30; // Range of timestamp that I wish to check

    for(size_t i=ts1;i<=ts2;i++){
        if(tw2.exists(i)){
            result += tw2.getTweets(i);
        }
    }
    if(tw2.getTweets(ts1,ts2)!=result){
        std::cout<<fail<<std::endl;
    }

    result = "";
    TweetMgr tw3;
    Tweet t1(25,"@Chris","Test");
    Tweet t2(17,"@Chris","Test");
    tw3.insert(t1);
    tw3.insert(t2);
    ts1 = 1;
    ts2 = 5; // Range of timestamp that I wish to check

    for(size_t i=ts1;i<=ts2;i++){
        if(tw2.exists(i)){
            result += tw2.getTweets(i);
        }
    }
    if(tw2.getTweets(ts1,ts2)!=result){
        std::cout<<fail<<std::endl;
    }
}///////////////////

void TestdeleteTweets(){
    std::cout<<"Testing deleteTweets()..."<<std::endl;
    TweetMgr tw1 = emptyTweetMgr();
    TweetMgr tw2 = createTweetMgr();

    //Testing with empty TweetMgr
    if(tw1.deleteTweets()!=0){
        std::cout<<fail<<std::endl;
    }

    if(!tw1.getTweets().empty()){
        std::cout<<fail<<std::endl;
    }

    //Testing with non-empty TweetMgr

    if(tw2.getNumTweets() != tw2.deleteTweets()){
        std::cout<<fail<<std::endl;
    }
    //Check after deletion
    if(tw2.getNumTweets() != 0){
        std::cout<<fail<<std::endl;
    }

}//CHECKED

void TestdeleteTweetssender(){
    std::cout<<"Testing deleteTweets(sender)"<<std::endl;
    TweetMgr tw1 = emptyTweetMgr();
    TweetMgr tw2 = createTweetMgr();

    //Testing with empty TweetMgr
    std::string user = "@Eddie"; //Specific user that deleteTweet is tested with
    if(tw1.deleteTweets(user)!=0){
        std::cout<<fail<<std::endl;
    }
    //Testing with non-empty TweetMgr, invalid user
    if(tw2.deleteTweets("@Nobody")!=0){
        std::cout<<fail<<std::endl;
    }
    //Checking capitalization
    if(tw2.deleteTweets("@eddie")!=0){
        std::cout<<fail<<std::endl;
    }
    //Checking @
    if(tw2.deleteTweets("Eddie")!=0){
        std::cout<<fail<<std::endl;
    }
    //Valid user
    if(tw2.count(user)!=tw2.deleteTweets(user)) {
        std::cout << fail << std::endl;
    }

}

void TestdeleteTweetstimestamp(){
    std::cout<<"Testing deleteTweets(ts)..."<<std::endl;

    TweetMgr tw1 = emptyTweetMgr();
    TweetMgr tw2 = createTweetMgr();
    TweetMgr tw3 = createTweetMgr();
    TweetMgr tw4 = createTweetMgr();

    if(tw1.deleteTweets(5)!=0){
        std::cout<<fail<<std::endl;
    }
    if(tw2.deleteTweets(1)!=1){
        std::cout<<fail<<std::endl;
    }
    if(tw3.deleteTweets(5)!=4){
        std::cout<<fail<<std::endl;
    }
    if(tw4.getNumTweets()!=tw4.deleteTweets(20)){
        std::cout<<fail<<std::endl;
    }

    TweetMgr tw5;
    Tweet t(10,"@Chris","Test");
    tw5.insert(t);

    if(tw5.deleteTweets(3)!=0){
        std::cout<<fail<<std::endl;
    }
}

void TestdeleteTweetsrange(){

    std::cout<<"Testing deleteTweets(ts1,ts2)..."<<std::endl;
    TweetMgr tw1 = emptyTweetMgr();
    TweetMgr tw2 = createTweetMgr();

    size_t count = 0;
    size_t ts1,ts2;//timestamp range
    size_t b = 0;//current index
    size_t ts=0;//current timestamp

    ts1 = 5;
    ts2 = 3;

    //Testing with empty TweetMgr
    if(tw1.deleteTweets(ts1,ts2)!=0){//Any range should work, as it is empty
        std::cout<<fail<<std::endl;
    }

    //Testing with non-empty TweetMgr


    std::swap(ts1,ts2);

    while(b!=tw2.getNumTweets()&&ts<=ts2){
        ts = tw2.retrieve(b).getTimestamp();

        if(ts<ts1){
            b++;
        }
        else if(ts<=ts2 && ts>=ts1) {
            count++;
            b++;
        }
    }
    if(tw2.deleteTweets(ts1,ts2)!=count){
        std::cout<<"FAILED"<<std::endl;
    }

    TweetMgr tw3 = createTweetMgr();
    ts = 0;
    ts1 = 0;
    ts2 = MAX_TIMESTAMP;
    count = 0, b = 0;
    if(ts1>ts2){
        std::swap(ts1,ts2);
    }
    while(b!=tw3.getNumTweets()&&ts<=ts2){
        ts = tw3.retrieve(b).getTimestamp();

        if(ts<ts1){
            b++;
        }
        else if(ts<=ts2 && ts>=ts1) {
            count++;
            b++;
        }
    }
    if(tw3.deleteTweets(ts1,ts2)!=count){
        std::cout<<fail<<std::endl;
    }

    TweetMgr tw4 = createTweetMgr();
    ts = 0;
    ts1 = 5;
    ts2 = 5;
    count = 0, b = 0;
    if(ts1>ts2){
        std::swap(ts1,ts2);
    }
    while(b!=tw4.getNumTweets()&&ts<=ts2){
        ts = tw4.retrieve(b).getTimestamp();

        if(ts<ts1){
            b++;
        }
        else if(ts<=ts2 && ts>=ts1) {
            count++;
            b++;
        }
    }
    if(tw4.deleteTweets(ts1,ts2)!=count){
        std::cout<<fail<<std::endl;
    }

    TweetMgr tw5 = createTweetMgr();
    ts = 0;
    ts1 = 20;
    ts2 = 5;
    count = 0, b = 0;

    while(b!=tw5.getNumTweets()&&ts<=ts1){
        ts = tw5.retrieve(b).getTimestamp();

        if(ts<ts2){
            b++;
        }
        else if(ts<=ts1 && ts>=ts2) {
            count++;
            b++;
        }
    }
    if(tw5.deleteTweets(ts1,ts2)!=count){
        std::cout<<fail<<std::endl;
    }

    TweetMgr tw6 = createTweetMgr();
    ts = 0;
    ts1 = 0;
    ts2 = 25;
    count = 0, b = 0;
    if(ts1>ts2){
        std::swap(ts1,ts2);
    }
    while(b!=tw6.getNumTweets()&&ts<=ts2){
        ts = tw6.retrieve(b).getTimestamp();

        if(ts<ts1){
            b++;
        }
        else if(ts<=ts2 && ts>=ts1) {
            count++;
            b++;
        }
    }
    if(tw6.deleteTweets(ts1,ts2)!=count){
        std::cout<<fail<<std::endl;
    }

    TweetMgr tw7 = createTweetMgr();
    ts = 0;
    ts1 = 0;
    ts2 = 0;
    count = 0, b = 0;
    if(ts1>ts2){
        std::swap(ts1,ts2);
    }
    while(b!=tw7.getNumTweets()&&ts<=ts2){
        ts = tw7.retrieve(b).getTimestamp();

        if(ts<ts1){
            b++;
        }
        else if(ts<=ts2 && ts>=ts1) {
            count++;
            b++;
        }
    }
    if(tw7.deleteTweets(ts1,ts2)!=count){
        std::cout<<fail<<std::endl;
    }

    TweetMgr tw8 = createTweetMgr();
    ts = 0;
    ts1 = 25;
    ts2 = 30;
    count = 0, b = 0;
    if(ts1>ts2){
        std::swap(ts1,ts2);
    }
    while(b!=tw8.getNumTweets()&&ts<=ts2){
        ts = tw8.retrieve(b).getTimestamp();

        if(ts<ts1){
            b++;
        }
        else if(ts<=ts2 && ts>=ts1) {
            count++;
            b++;
        }
    }
    if(tw8.deleteTweets(ts1,ts2)!=count){
        std::cout<<fail<<std::endl;
    }

    TweetMgr tw9 = createTweetMgr();
    ts = 0;
    ts1 = 5;
    ts2 = 1;
    count = 0, b = 0;
    if(ts1>ts2){
        std::swap(ts1,ts2);
    }
    while(b!=tw9.getNumTweets()&&ts<=ts2){
        ts = tw9.retrieve(b).getTimestamp();

        if(ts<ts1){
            b++;
        }
        else if(ts<=ts2 && ts>=ts1) {
            count++;
            b++;
        }
    }
    if(tw9.deleteTweets(ts1,ts2)!=count){
        std::cout<<fail<<std::endl;
    }

    TweetMgr tw10 = createTweetMgr();
    ts = 0;
    ts1 = 7;
    ts2 = 10;
    count = 0, b = 0;
    if(ts1>ts2){
        std::swap(ts1,ts2);
    }
    while(b!=tw10.getNumTweets()&&ts<=ts2){
        ts = tw10.retrieve(b).getTimestamp();

        if(ts<ts1){
            b++;
        }
        else if(ts<=ts2 && ts>=ts1) {
            count++;
            b++;
        }
    }
    if(tw10.deleteTweets(ts1,ts2)!=count){
        std::cout<<fail<<std::endl;
    }

    TweetMgr tw11;
    Tweet t1(1,"@Chris","Test");
    Tweet t2(25,"@Chris","Test2");
    tw11.insert(t1);
    tw11.insert(t2);
    ts = 0;
    ts1 = 7;
    ts2 = 10;
    count = 0, b = 0;
    if(ts1>ts2){
        std::swap(ts1,ts2);
    }
    while(b!=tw11.getNumTweets()&&ts<=ts2){
        ts = tw11.retrieve(b).getTimestamp();

        if(ts<ts1){
            b++;
        }
        else if(ts<=ts2 && ts>=ts1) {
            count++;
            b++;
        }
    }
    if(tw11.deleteTweets(ts1,ts2)!=count){
        std::cout<<fail<<std::endl;
    }
}//CHECKED




// uncomment the following lines if you are running the program in a
// DOS or terminal window and you want the window to stay open when
// the testing is done.
//	std::cout << "\nEnd of tests. Press enter to exit.";
//	char tt;
//	tt = std::cin.get();


