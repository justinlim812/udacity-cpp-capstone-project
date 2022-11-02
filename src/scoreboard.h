/* A Scoreboard class to read and write scoreboard rankings */

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <fstream>
#include <iostream>
#include <string>

class Scoreboard{
public:
    Scoreboard(std::string filePath) : _filePath(filePath){};
    ~Scoreboard();
    
    std::string GetName();
    void SetName(std::string name);

    // Request name input from user for scoreboard ranking
    void RequestName();
    
    

private:
    // Path to scoreboard data (.txt)
    std::string _filePath;

    // Score board buffer
    std::string _name;    
};

#endif