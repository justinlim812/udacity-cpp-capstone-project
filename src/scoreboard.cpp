#include <cstring>

#include "scoreboard.h"

Scoreboard::~Scoreboard(){

}



void Scoreboard::RequestName(){
   std::string input;
   std::cout << "Please enter your first name:" << std::endl;
   std::cin >> input;
   Scoreboard::SetName(input);
   // std::cout << "Name entered: " << Scoreboard::GetName() << std::endl;
   // std::cout << "Total name length: " << Scoreboard::GetName().length() << std::endl;
}

std::string Scoreboard::GetName(){
   return _name;
}

void Scoreboard::SetName(std::string name){
   _name = name;
}


// #include <fstream>
// #include <iostream>
// using namespace std;
 
// int main () {
//    char data[100];

//    // open a file in write mode.
//    ofstream outfile;
//    outfile.open("afile.dat");

//    cout << "Writing to the file" << endl;
//    cout << "Enter your name: "; 
//    cin.getline(data, 100);

//    // write inputted data into the file.
//    outfile << data << endl;

//    cout << "Enter your age: "; 
//    cin >> data;
//    cin.ignore();
   
//    // again write inputted data into the file.
//    outfile << data << endl;

//    // close the opened file.
//    outfile.close();

//    // open a file in read mode.
//    ifstream infile; 
//    infile.open("afile.dat"); 
 
//    cout << "Reading from the file" << endl; 
//    infile >> data; 

//    // write the data at the screen.
//    cout << data << endl;
   
//    // again read the data from the file and display it.
//    infile >> data; 
//    cout << data << endl; 

//    // close the opened file.
//    infile.close();

//    return 0;
// }