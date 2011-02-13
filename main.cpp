#include <iostream>
#include <string>
#include "bfinst.hpp"
#include "bfinstlist.hpp"
#include "bfreadfile.hpp"

int main( int argc, char** argv ) {
	if( argc < 2 ) {
		std::cerr << "Please provide one filename as an argument.\n";
		return 1;
	}
	BFReadFile infile( argv[1] );
	std::cout << infile.instlist.toC();
}
