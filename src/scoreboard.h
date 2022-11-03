/* A Scoreboard class to read and write scoreboard rankings */

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

class Scoreboard{
public:
    Scoreboard(const std::string &filePath) : _filePath(filePath){};
    ~Scoreboard(){};

    void Start();

    // Use of rvalue reference to avoid unnecessary copy
    void Stop(int &&score, int &&size);
    
    // Request name input from user for scoreboard ranking
    void RequestName();

    // Setter and getter
    void SetName(std::string &name);
    std::string GetName();
    
    
private:
    // Path to scoreboard data (.txt)
    std::string _filePath;
    std::vector < std::vector< std::string > > _contents{};

    // Score board buffer
    std::string _name;    

    void ReadScoreBoard();
    void DisplayRankings();

    // Check if current user score higher than the scores on rankings
    void CheckScores(int &score, int &size);

    // Arrange scores on score board from high to low
    void ArrangeScores();

    // Write data back to file
    void WriteToFile(int &score, int &size); 
};

#endif