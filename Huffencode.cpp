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
//reading file into unorderedMap
void Huffencode::readFile()
{
    char ch;
    int count = 0;
    fstream fin(iFile, fstream::in);
    while (fin >> noskipws >> ch)
    {
        if (fTable.find(ch) == fTable.end())
        {
            fTable[ch] = 1;
        }
        // else
        // {
        //     fTable.find(ch)
        // }
    }
    cout << count << endl;
}

} // namespace THNGEO002