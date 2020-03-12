#include "HuffmanNode.h"

namespace THNGEO002
{
//DEFAULT
HuffmanNode::HuffmanNode()
{
}
//default const to build
HuffmanNode::HuffmanNode(char c, int freq)
{
    this->ch = c;
    this->frequency = freq;
}
//destructor
HuffmanNode::~HuffmanNode()
{
}
//copy const
HuffmanNode::HuffmanNode(const HuffmanNode &rhs) : right(new HuffmanNode(*rhs.right)), left(new HuffmanNode(*rhs.left))
{
    this->frequency = rhs.frequency;
    this->ch = rhs.ch;
}
//move const
HuffmanNode::HuffmanNode(HuffmanNode &&rhs)
{
    left = move(rhs.left);
    right = move(rhs.right);
    this->ch = move(rhs.ch);
    this->frequency = move(rhs.frequency);
}
//copy assignment op
HuffmanNode &HuffmanNode::operator=(const HuffmanNode &rhs)
{
    this->ch = rhs.ch;
    this->frequency = rhs.frequency;
    this->right.operator=(rhs.right);
    this->left.operator=(rhs.left);
    return *this;
}
//move assignment op
HuffmanNode &HuffmanNode::operator=(const HuffmanNode &&rhs)
{
    this->right = move(rhs.right);
    this->left = move(rhs.left);
    this->ch = move(rhs.ch);
    this->frequency = move(rhs.frequency);
}
//compare operator
bool HuffmanNode::operator<(const HuffmanNode& rhs)const{
    return(this->frequency<rhs.frequency());
}
} // namespace THNGEO002