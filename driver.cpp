#include <string>
#include <iostream>
#include "huffencode.h"


using namespace std;
int main(int argc, char *argv[])
{
    string iFile;
    string oFile;
    if(argc==3){
        iFile=argv[1];
        oFile=argv[2];
        THNGEO002::Huffencode h(iFile,oFile);
        h.readFile();
        
    }

    return 0;
}