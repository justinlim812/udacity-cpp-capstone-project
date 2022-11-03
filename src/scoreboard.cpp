#include <cstring>
#include <sstream>
#include <algorithm> // For sort()

#include "scoreboard.h"

void Scoreboard::Start(){
   ReadScoreBoard();
   DisplayRankings();
   RequestName();
}


void Scoreboard::Stop(int &&score, int &&size){
   CheckScores(score, size);
   ArrangeScores();
   DisplayRankings();
   WriteToFile(score, size);
}


void Scoreboard::RequestName(){
   std::string input;
   std::cout << "Player, enter your first name:" << std::endl;
   std::cin >> input;
   Scoreboard::SetName(input);
}


std::string Scoreboard::GetName(){ return _name; }


void Scoreboard::SetName(std::string &name){ _name = name; }


// Helper function to parse line for ReadScoreBoard()
std::vector<std::string> ParseLine(std::string line) {
   std::istringstream sline(line);
   std::vector<std::string> row;
   std::string value; 
   while(sline >> value){
      row.emplace_back(value);
   }
   return row;
}

void Scoreboard::ReadScoreBoard(){
   std::ifstream infile(_filePath);
   
   // Check if the read file exists, otherwise file will be created at the end of program by outfile
   if(infile){
      std::string line;
      std::string name, score, size;
      int i = 0;

      while(std::getline(infile, line)){
         // _contents.emplace_back(line);
         std::vector< std::string > row = ParseLine(line);
         _contents.emplace_back(row);
      }
   }
   else{
      std::cout << "Scoreboard does not exist yet, continue playing to be the first to be on the Scoreboard!" << std::endl;
   }
   infile.close();
}


void Scoreboard::DisplayRankings(){
   std::cout << "\nAll-time Score Rankings" << std::endl;

   // A group of content consists of 3 elements in order [Name, score, size], display top 5 rankings
   for (int i = 0; i < 5; i++){
      std::cout << "#" << i+1 << " " << _contents[i][0] << ", Score: " << _contents[i][1] << ", Size: " << _contents[i][2] << std::endl;
   }
   std::cout << std::endl;
}


// Check if current player score higher than ranking scores
void Scoreboard::CheckScores(int &score, int &size){
   for(int i = 0; i < _contents.size(); i++){

      // Add score to score board if higher
      if(score > std::stoi(_contents[i][1])){
         std::vector< std::string > newRow{};
         newRow.emplace_back(_name);
         newRow.emplace_back(std::to_string(score));
         newRow.emplace_back(std::to_string(size));
         _contents.emplace_back(newRow);
         std::cout << "Congrats, you made it into the Rankings!" << std::endl;
         break;
      }
   }
   std::cout << "Unfortunately you did not make it into rankings, try again next time." << std::endl;
}


// Helper function to sort using 2nd element of a vector
bool SortByColumn(const std::vector< std::string >& v1, const std::vector< std::string >& v2){
   return std::stoi(v1[1]) > std::stoi(v2[1]);
}

// Compare and rearrange score from high to low
void Scoreboard::ArrangeScores(){
   std::sort(_contents.begin(), _contents.end(), SortByColumn);
}


// Write data back to file
void Scoreboard::WriteToFile(int &score, int &size){
   std::ofstream outfile(_filePath);

   if(outfile){

      // Keep only 5 entries
      for(int i = 0; i < 5; i++){
         outfile << _contents[i][0] << " ";
         outfile << _contents[i][1] << " ";
         outfile << _contents[i][2] << " " << std::endl;
      }
      outfile.close();
   }
}