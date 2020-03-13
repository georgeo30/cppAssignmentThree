#include <string>
#include <iostream>
#include <vector>
#include "huffencode.h"
#include <sstream>
#include <queue>

using namespace std;
namespace THNGEO002
{
//constructor
Huffencode::Huffencode(string inF, string outF)
{
    iFile = inF + ".txt";
    oFile = outF + ".txt";
    readFile();
    std::priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, compare> priorityq;
    for (auto x : fTable) 
    { 
        priorityq.push(shared_ptr<HuffmanNode> (new HuffmanNode(x.first,x.second)));
       // cout<<priorityq.size<<endl;
    }
    
}
//destructor
Huffencode::~Huffencode()
{
}
//copy constructor
Huffencode::Huffencode(const Huffencode &rhs) : root(new HuffmanNode(*rhs.root))
{
    this->fTable = rhs.fTable;
}
//move constructor
Huffencode::Huffencode(Huffencode &&rhs) : root(new HuffmanNode(*rhs.root))
{
    this->fTable = move(rhs.fTable);
    rhs.root.reset();
    rhs.fTable.clear();
}
//copy assignment operator
Huffencode &Huffencode::operator=(const Huffencode &rhs)
{
    this->fTable = rhs.fTable;
    root.operator=(rhs.root);
    return *this;
}
//movve assignment operator
Huffencode &Huffencode::operator=(const Huffencode &&rhs)
{
    this->root = move(rhs.root);
    this->fTable = move(rhs.fTable);
    return *this;
}

//reading file into unorderedMap
void Huffencode::readFile()
{
    char ch;
    int count = 0;
    fstream fin(iFile, fstream::in);
    while (fin.get(ch))
    {

        if (fTable.find(ch) == fTable.end())
        {
            fTable[ch] = 1;
        }
        else
        {
            int inc = fTable.at(ch);
            inc++;
            fTable[ch] = inc;
        }
    }
}


} // namespace THNGEO002