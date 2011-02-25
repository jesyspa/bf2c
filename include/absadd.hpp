#ifndef BF2C_ABSADD_HPP
#define BF2C_ABSADD_HPP
#include <string>
	
//! \brief An object of a class represents an instruction that modifies the
//!        cell currently being pointed to.
class AbsAdd : public AbsInst {
    public:
	virtual std::string toC( unsigned int tabDepth ) const;
    private:
	int count_;
};

#endif // BF2C_ABSADD_HPP
