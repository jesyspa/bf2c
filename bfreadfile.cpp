#include <fstream>
#include "bfreadfile.hpp"

BFReadFile::BFReadFile( std::string fname ) {
	std::ifstream ifile( fname.c_str() );
	while( ifile.good() )
		instlist.push( ifile.get() );
}

