#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "unittests.h"
#include "huffencode.h"
#include "HuffmanNode.h"
#include <unordered_map>
#include <queue>
#include <memory>
using namespace std;
using namespace THNGEO002;
//Test case 1
TEST_CASE("Testing frequency table", "[HuffmanTree]")
{

    Huffencode huffmanTree = Huffencode();

    SECTION("Testing letter frequency table")
    {
        //Test string
        huffmanTree.readFile("inTest.txt");

        //Check if letter frequency table is correct
        REQUIRE(int(huffmanTree.fTable.at('g')) == 2);
        REQUIRE(int(huffmanTree.fTable.at('h')) == 2);
        REQUIRE(int(huffmanTree.fTable.at('H')) == 1);
        REQUIRE(int(huffmanTree.fTable.at('i')) == 2);
        REQUIRE(int(huffmanTree.fTable.at('n')) == 2);
        REQUIRE(int(huffmanTree.fTable.at('a')) == 5);
    }
}
//Test case 2
TEST_CASE("HuffmanNode < operator", "[HuffmanTree]")
{

    HuffmanNode NodeOne = HuffmanNode('a', 10);
    HuffmanNode NodeTwo = HuffmanNode('c', 8);
    SECTION("HuffmanNode < operator")
    {

        //Checking if the compare (<) operator works
        REQUIRE((NodeOne < NodeTwo) == false);
        REQUIRE((NodeTwo < NodeOne) == true);
    }
}
//Test case 3
TEST_CASE("Testing the priority queue operator", "[HuffmanTree]")
{
    std::priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, compare> priorityq;
    priorityq.push(shared_ptr<HuffmanNode>(new HuffmanNode('a', 6)));
    priorityq.push(shared_ptr<HuffmanNode>(new HuffmanNode('c', 3)));
    priorityq.push(shared_ptr<HuffmanNode>(new HuffmanNode('u', 4)));
    priorityq.push(shared_ptr<HuffmanNode>(new HuffmanNode('q', 1)));
    SECTION("Testing the priority queue operator")
    {

        //priority queue top check
        shared_ptr<HuffmanNode> top=priorityq.top();
        REQUIRE((*top).getF() ==1 );
        priorityq.pop();
        REQUIRE((*priorityq.top()).getF() ==3);
        priorityq.pop();
        REQUIRE((*priorityq.top()).getF() ==4);
        priorityq.pop();
        REQUIRE((*priorityq.top()).getF() ==6);
    }
}
//Test case 4
TEST_CASE("Tree building", "[HuffmanTree]")
{
    Huffencode huffmanTree = Huffencode();
    std::priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, compare> priorityq;
    priorityq.push(shared_ptr<HuffmanNode>(new HuffmanNode('a', 6)));
    priorityq.push(shared_ptr<HuffmanNode>(new HuffmanNode('c', 3)));
    priorityq.push(shared_ptr<HuffmanNode>(new HuffmanNode('u', 4)));
    priorityq.push(shared_ptr<HuffmanNode>(new HuffmanNode('q', 1)));
    priorityq.push(shared_ptr<HuffmanNode>(new HuffmanNode('r', 8)));

    shared_ptr<HuffmanNode> root =huffmanTree.huffmanTreeBuilder(priorityq);
    SECTION("Tree building")
    {

        //should be the total of frequency from the frequency table
        REQUIRE((*root).getF()==22 );
        //left and rright children of root
        REQUIRE((root).use_count()==2 );
        //left child's children
        REQUIRE((root->left).use_count()==1 );
        //right child's children
        REQUIRE((root->right).use_count()==1 );
        
    }
     
}
//Test case 5
TEST_CASE("code table testing", "[HuffmanTree]")
{
    Huffencode huffmanTree = Huffencode();
    std::priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, compare> priorityq;
    priorityq.push(shared_ptr<HuffmanNode>(new HuffmanNode('a', 6)));
    priorityq.push(shared_ptr<HuffmanNode>(new HuffmanNode('c', 2)));
    priorityq.push(shared_ptr<HuffmanNode>(new HuffmanNode('u', 4)));
    priorityq.push(shared_ptr<HuffmanNode>(new HuffmanNode('q', 1)));
    priorityq.push(shared_ptr<HuffmanNode>(new HuffmanNode('r', 8)));

    shared_ptr<HuffmanNode> root =huffmanTree.huffmanTreeBuilder(priorityq);
    huffmanTree.codeTable(root,"");  
    SECTION("code table testing")
    {

        //testing if the code table is correct
        REQUIRE(huffmanTree.codeTableMap.at('r')=="0" );
        REQUIRE(huffmanTree.codeTableMap.at('a')=="10" );
        REQUIRE(huffmanTree.codeTableMap.at('q')=="1100" );
        REQUIRE(huffmanTree.codeTableMap.at('c')=="1101" );
        REQUIRE(huffmanTree.codeTableMap.at('u')=="111" );
        
    }
     
}
//Test case 6
TEST_CASE("equivilant bitstream in compressed file", "[HuffmanTree]")
{
    Huffencode huffmanTree = Huffencode();
    huffmanTree.readFile("inTest.txt");
    std::priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, compare> priorityq;
    //pushing the elements from the uunordered map into the priority queue
    for (auto x : huffmanTree.fTable) 
    { 
        priorityq.push(shared_ptr<HuffmanNode> (new HuffmanNode(x.first,x.second)));
    }

    shared_ptr<HuffmanNode> root =huffmanTree.huffmanTreeBuilder(priorityq);
    huffmanTree.codeTable(root,"");  
    SECTION("equivilant bitstream in compressed file")
    {

        //testing if output bit stream is correct
        REQUIRE((huffmanTree.writeFile("inTest.txt"))=="100110111110101110010110101011110110011100111000011001010010110000101010010110110010010001111010111010010001110001111" );
        
        
    }
     
}