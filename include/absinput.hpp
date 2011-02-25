#ifndef BF2C_ABSINPUT_HPP
#define BF2C_ABSINPUT_HPP
#include <string>
	
//! \brief An object of a class represents an instruction that requests input
//!        into the current cell.
class AbsInput : public AbsInst {
    public:
	AbsInput();
	virtual std::string toC( unsigned int tabDepth ) const;
};

#endif // BF2C_ABSINPUT_HPP
