#include <string>
#include <iostream>
#include <vector>
#include "huffencode.h"
#include <sstream>

using namespace std;
namespace THNGEO002
{
//constructor
Huffencode::Huffencode(string inF, string outF)
{
    iFile = inF + ".txt";
    oFile = outF + ".txt";
}
//destructor
Huffencode::~Huffencode()
{
}
//copy constructor
Huffencode::Huffencode(const Huffencode& rhs):root(new HuffmanNode(*rhs.root)){
    this->fTable=rhs.fTable;

}
//move constructor
Huffencode::Huffencode( Huffencode&& rhs):root(new HuffmanNode(*rhs.root)){
    this->fTable=move(rhs.fTable);
    rhs.root.reset();
    rhs.fTable.clear();
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
            int inc=fTable.at(ch);
            inc++;
            fTable[ch]=inc;
        }
        }
    
    for (auto x : fTable) 
      cout<<x.first<<" "<<x.second<<endl; 
}

} // namespace THNGEO002