#ifndef _HUFFMANNODE_H
#define _HUFFMANNODE_H
#include <string>
#include <memory>

namespace THNGEO002
{
    using namespace std;

class HuffmanNode
{
private:
    char ch;
    int frequency;
                               
public:
        std::shared_ptr<HuffmanNode> left = nullptr;
        std::shared_ptr<HuffmanNode> right = nullptr;                                   

    //default constructor
    HuffmanNode();
    //constructor
    HuffmanNode(char c,int freq);
    //destructor
    ~HuffmanNode();       
    //copy constructor
    HuffmanNode(const HuffmanNode & rhs);
    //move constructor
    HuffmanNode(HuffmanNode && rhs);

    //copy assignment op
    HuffmanNode& operator=(const HuffmanNode & rhs);
    //move assignment op
    HuffmanNode& operator=(const HuffmanNode && rhs);
    //compare perator
    bool operator<(const HuffmanNode &rhs)const;
    //returns the char 
    char getCh() const;
    //returns the frequency number
    int getF() const;
    



};

} // namespace THNGEO002
#endif