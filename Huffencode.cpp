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
        //calling the method to build the tree
    }
            this->root=huffmanTreeBuilder(priorityq);

    
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

//Huffman tree builder method that returns a pointer to the parent huffman node
shared_ptr<HuffmanNode> Huffencode::huffmanTreeBuilder(priority_queue<shared_ptr<HuffmanNode>,vector<shared_ptr<HuffmanNode>>, compare>& pQ){
    
    //automatically deletes the tree node representation
    shared_ptr<HuffmanNode> pNode=nullptr;

    //the tree will now loop through all the nodes and allocate the left and right nodes until there is only one node left onthe tree.
    while(pQ.size()>1){
        //leftnode
        shared_ptr<HuffmanNode> leftP=pQ.top();
        //removing the node
        pQ.pop();
        //rightnode
        shared_ptr<HuffmanNode> rightP=pQ.top();
        //removing the node
        pQ.pop();
        //adding the frequency of both the nodes (left and right) to the parent node
        int pFreq;
        pFreq=(*rightP).getF() + (*leftP).getF();
        //setting the parent node frequency
        pNode.reset(new HuffmanNode('\0',pFreq));
        //parents left child is set
        pNode->left=leftP;
        //parents right child is set
        pNode->right=rightP;
        //pushing back the parentNode to the priority queue
        pQ.push(pNode);

    }
    //returns the root node
    return pNode;

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