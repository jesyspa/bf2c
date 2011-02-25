#ifndef BF2C_ABSOUTPUT_HPP
#define BF2C_ABSOUTPUT_HPP
#include <string>
	
//! \brief An object of a class represents an instruction that outputs the
//!        value of the current cell.
class AbsOutput : public AbsInst {
    public:
	AbsOutput();
	virtual std::string toC( unsigned int tabDepth ) const;
};

#endif // BF2C_ABSOUTPUT_HPP
