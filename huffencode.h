#ifndef _HUFFENCODE_H
#define _HUFFENCODE_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "HuffmanNode.h"
#include <queue>


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
    std::unordered_map<char, string> codeTableMap;
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
    //method to build a huffman tree
    shared_ptr<HuffmanNode> huffmanTreeBuilder(priority_queue<shared_ptr<HuffmanNode>,vector<shared_ptr<HuffmanNode>>, compare>& pQ);
    //building the code table
    void codeTable(shared_ptr<HuffmanNode> r,string str);
    //CONVERTING EACH CHAR IN STRING TO A BIT REPRESENTATION AND WRITING THIS TO THE OUTPUT FILE
    void writeFile();

};

} // namespace THNGEO002
#endif