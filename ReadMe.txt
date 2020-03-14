Read Me
---------------------------------------------------

Makefile Details:

make : this will run the very first method in the make file which is create. This method will compile all the necessary files and create an executable called huffencode

make create : same as above

make test : 	this is used for the unit testing. it will compile all the neccessary files for the unit testing. This includes the huffman tree and huffman node aswell as the unitTest cpp files along with their respective header files
		it will also create an executable called "test"

make clean : this will clean all the binary and executables created when make is typed

make cleanTest : this wwill clean all the binary and executables that are created when make test is typed

---------------------------------------------------

To Run the program through terminal.

1)Assuming you have already typed in "make" and compiled the files

2) you can then test by typing in as specified in the pdf

    example:
            1) ./huffencode in out -->	this will run the executable with "in" as the input file and "out" as the output file
					the expected output is that it will print the file sizes and then the write the compressed bit stream to an output file called "out.txt" and its respective header in "out.hdr" which contains
					code table for the output file.
            

    	**  Please remember to preceed the name of the executable with "./" as shown above  **
	** please note that huffencode is the huffman tree class i just named it differently when i started **

    
---------------------------------------------------
UNIT TESTING

use makefile command "make test" to compile and create an executable called make test
which you can then execute using "./test"

I had 6 unit tests explained below:

	1) testing the frequency table
	2) testing the "<" less than operator
	3) testing the priority queue
	4) testing the tree building method
	5) testing the code table
	6) testing the output bitstream that gets created

All test cases passed and you can see this when you run the executable "./test"

---------------------------------------------------

File structure

HuffmanNode.cpp -- Huffman tree node class
HuffmanNode.h -- its corresponfing header file
Huffencode.cpp -- this is the huffman tree class 
huffencode.h -- its corresponding header file
UnitTests.cpp -- unit testing class
unitTests.h its corresponding header file
driver.cpp -- contains the main 


---------------------------------------------------

Git Details:

attached within the tar.gz is the .git repo
If this does not open or causes errors to run. Please view the repo on my gitHub which i will make available to public few days after submissions is closed.
GitHub Link : https://github.com/georgeo30/cppAssignmentThree