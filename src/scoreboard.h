/* A Scoreboard class to read and write scoreboard rankings */

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <fstream>
#include <iostream>
#include <string>

class Scoreboard{
public:
    Scoreboard(const std::string &filePath) : _filePath(filePath){};
    ~Scoreboard();
    
    std::string GetName();
    void SetName(std::string &name);

    // Request name input from user for scoreboard ranking
    void RequestName();
    
    void WriteToFile(int &&score, int &&size); // Use of rvalue reference to avoid unnecessary copy

private:
    // Path to scoreboard data (.txt)
    std::string _filePath;

    // Score board buffer
    std::string _name;    
};

#endif