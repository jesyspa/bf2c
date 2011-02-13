#ifndef BF2C_BFREADFILE_HPP
#define BF2C_BFREADFILE_HPP
#include <string>
#include "bfinstlist.hpp"

//! \brief An object of this class translates a brainfuck file into a
//!        BFInstList.
class BFReadFile {
    public:
	//! Sets a file to be read and reads it.
	BFReadFile( std::string fname );
	BFInstList instlist;
};

#endif // BF2C_READFILE_HPP

