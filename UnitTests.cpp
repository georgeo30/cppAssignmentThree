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
TEST_CASE("Testing frequency table","[HuffmanTree]"){

    Huffencode huffmanTree = Huffencode();
    
    SECTION("Testing letter frequency table"){
        //Test string
        huffmanTree.readFile("inTest.txt");

        //Check if letter frequency table is correct
        REQUIRE( int(huffmanTree.fTable.at('g')) == 2);
        REQUIRE( int(huffmanTree.fTable.at('h')) == 2);
        REQUIRE( int(huffmanTree.fTable.at('H')) == 1);
        REQUIRE( int(huffmanTree.fTable.at('i')) == 2);
        REQUIRE( int(huffmanTree.fTable.at('n')) == 2);
        REQUIRE( int(huffmanTree.fTable.at('a')) == 5);
       
    }
}
//Test case 2
TEST_CASE("Testing frequency table","[HuffmanTree]"){

    Huffencode huffmanTree = Huffencode();
    
    SECTION("Testing letter frequency table"){
        //Test string
        huffmanTree.readFile("inTest.txt");

        //Check if letter frequency table is correct
        REQUIRE( int(huffmanTree.fTable.at('g')) == 2);
        REQUIRE( int(huffmanTree.fTable.at('h')) == 2);
        REQUIRE( int(huffmanTree.fTable.at('H')) == 1);
        REQUIRE( int(huffmanTree.fTable.at('i')) == 2);
        REQUIRE( int(huffmanTree.fTable.at('n')) == 2);
        REQUIRE( int(huffmanTree.fTable.at('a')) == 5);
       
    }
}