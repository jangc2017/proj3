cmake_minimum_required(VERSION 3.6)
project(project3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -pedantic-errors")

set(SOURCE_FILES
        TweetMgrTest.cpp
        Tweet.cpp
        Tweet.h
        TweetMgr.cpp
        TweetMgr.h
        TweetNode.h)

add_executable(project3 ${SOURCE_FILES})