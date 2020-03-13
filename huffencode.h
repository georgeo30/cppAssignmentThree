#ifndef _HUFFENCODE_H
#define _HUFFENCODE_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "HuffmanNode.h"

namespace THNGEO002
{
using namespace std;
struct compare
{
    bool operator()(const std::shared_ptr<HuffmanNode> &a, const std::shared_ptr<HuffmanNode> &b) const
    {
        return !((*a) < (*b));
    }
};
class Huffencode
{
private:
    string iFile;
    string oFile;
    std::unordered_map<char, int> fTable;
    std::shared_ptr<HuffmanNode> root;

public:
    //default const
    Huffencode();
    //default argument passed const
    Huffencode(string inF, string outF);
    //destructor
    ~Huffencode();
    //copy const
    Huffencode(const Huffencode &rhs);
    //move constructor
    Huffencode(Huffencode &&rhs);
    //reading in the char into a frequency table
    void readFile();
    //copy assignment operator
    Huffencode &operator=(const Huffencode &rhs);
    //move assignment operator
    Huffencode &operator=(const Huffencode &&rhs);
};

} // namespace THNGEO002
#endif