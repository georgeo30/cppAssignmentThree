#ifndef _HUFFENCODE_H
#define _HUFFENCODE_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map> 


namespace THNGEO002
{
    using namespace std;

class Huffencode
{
private:
    string iFile;
    string oFile;
    unordered_map<char, int> fTable;                                  
public:                                   
    Huffencode(string inF,string outF);                           
    ~Huffencode();
    void readFile();                          

};

} // namespace THNGEO002
#endif