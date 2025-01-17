#include <string>
#include <iostream>
#include <vector>
#include "huffencode.h"
#include <sstream>
#include <queue>

using namespace std;
namespace THNGEO002
{
Huffencode::Huffencode()
{
}
//constructor
Huffencode::Huffencode(string inF, string outF)
{
    iFile = inF + ".txt";
    oFile = outF + ".txt";
    //reading the file into an unordered map
    readFile();
    //setting up the priority queue
    std::priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, compare> priorityq;
    //pushing the elements from the uunordered map into the priority queue
    for (auto x : fTable)
    {
        priorityq.push(shared_ptr<HuffmanNode>(new HuffmanNode(x.first, x.second)));
    }

    //calling the method to build the tree
    this->root = huffmanTreeBuilder(priorityq);
    codeTable(root, "");
    writeFile();
    string hdr = oFile.erase(oFile.size() - 4) + ".hdr";

    std::ofstream out(hdr);
    for (auto &x : codeTableMap)
    {
        out << x.first << " " << x.second << endl;
    }

    cout << "Size of input file is: " << inSizeBit << endl;
    cout << "Size of output file is: " << outSizeBit << endl;
    cout << "Compression ratio is: " << (float)outSizeBit / (float)inSizeBit << endl;
    cout<< "Compressed file is in "<<oFile<<".txt and code table is in "<<hdr<<endl;
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
        inSizeBit += sizeof(ch);
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
//OVERLOADED METHOD FOR UNIT TESTING
void Huffencode::readFile(string ina)
{
    char ch;
    int count = 0;
    fstream fin(ina, fstream::in);
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
//Huffman tree builder method that returns a pointer to the parent huffman node
shared_ptr<HuffmanNode> Huffencode::huffmanTreeBuilder(priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, compare> &pQ)
{

    //automatically deletes the tree node representation
    shared_ptr<HuffmanNode> pNode = nullptr;

    //the tree will now loop through all the nodes and allocate the left and right nodes until there is only one node left onthe tree.
    while (pQ.size() > 1)
    {
        //leftnode
        shared_ptr<HuffmanNode> leftP = pQ.top();
        //removing the node
        pQ.pop();
        //rightnode
        shared_ptr<HuffmanNode> rightP = pQ.top();
        //removing the node
        pQ.pop();
        //adding the frequency of both the nodes (left and right) to the parent node
        int pFreq;
        pFreq = (*rightP).getF() + (*leftP).getF();
        //setting the parent node frequency
        pNode.reset(new HuffmanNode('\0', pFreq));
        //parents left child is set
        pNode->left = leftP;
        //parents right child is set
        pNode->right = rightP;
        //pushing back the parentNode to the priority queue
        pQ.push(pNode);
    }
    //returns the root node
    return pNode;
}
//creating the code table
void Huffencode::codeTable(shared_ptr<HuffmanNode> r, string str)
{
    //adding a zero the the stream if the traversal is to the right
    if (r->left != nullptr)
    {
        codeTable(r->left, str + "0");
    }
    //inserting the stream of bits and its character to the codeTableMap
    this->codeTableMap.insert({(*r).getCh(), str});
    //adding a one to the stream if the traversal is to the left
    if (r->right != nullptr)
    {
        codeTable(r->right, str + "1");
    }
}

//converting each char from the input file to a bit representation and writing this output a file
void Huffencode::writeFile()
{
    char ch;
    string bitRep;

    fstream fin(iFile, fstream::in);
    while (fin.get(ch))
    {

        for (auto &x : codeTableMap)
        {
            if (x.first == ch)
            {
                bitRep += x.second;
            }
        }
    }
    outSizeBit = sizeof(bitRep);

    std::ofstream out(oFile);
    out << bitRep;
    out.close();
}
//OVERLOADED METHOD FOR UNIT TESTING
string Huffencode::writeFile(string unitTestFile)
{
    char ch;
    string bitRep;
    fstream fin(unitTestFile, fstream::in);
    while (fin.get(ch))
    {

        for (auto &x : codeTableMap)
        {
            if (x.first == ch)
            {
                bitRep += x.second;
            }
        }
    }
    return bitRep;
}

} // namespace THNGEO002