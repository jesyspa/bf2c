#ifndef BF2C_ABSMOVE_HPP
#define BF2C_ABSMOVE_HPP
#include <string>

class BFInst;
	
//! \brief An object of a class represents an instruction that modifies the
//!        pointer.
class AbsMove : public AbsInst {
    public:
	AbsMove();
	AbsMove( const& BFInst in );
	virtual std::string toC( unsigned int tabDepth ) const;
    private:
	int count_;
};

#endif // BF2C_ABSMOVE_HPP
