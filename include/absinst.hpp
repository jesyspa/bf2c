#ifndef BF2C_ABSINST_HPP
#define BF2C_ABSINST_HPP
#include <string>
	
//! \brief An object of a class derived from this one holds an abstract
//!        instruction.
//!
//! While a lot of brainfuck instructions will map directly to abstract ones,
//! some will be more convenient to translate as groups.
class AbsInst {
    public:
	virtual std::string toC( unsigned int tabDepth ) = 0 const;
};

#endif // BF2C_ABSINST_HPP
