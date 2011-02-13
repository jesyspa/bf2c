#ifndef BF2C_BFINSTLIST_HPP
#define BF2C_BFINSTLIST_HPP

#include <vector>
#include "bfinst.hpp"

//! \brief This class is the list of brainfuck instructions that will end up
//!        being translated into a program.
class BFInstList {
    public:
	//! Creates an empty list of instructions.
	BFInstList();
	//! Adds an instruction onto the back of the list. Ignores any
	//! instructions it cannot read.
	void push( char c );
	//! Returns a string containing the concatenated C code of the entire
	//! list.
	std::string toC();
    private:
	std::vector<BFInst> instvec;
	unsigned int startindent;
	unsigned int lastindent;
};

#endif // BF2C_INSTLIST_HPP
