#ifndef BF2C_ABSCONTEXT_HPP
#define BF2C_ABSCONTEXT_HPP
#include <string>
#include <vector>
	
//! \brief An object of a class represents a series of instructions, generally
//!        in the form of a while( *ptr ) loop.
class AbsContext : public AbsInst {
    public:
	AbsContext( bool rootContext );
	virtual std::string toC( unsigned int tabDepth ) const;
	void push( AbsInst* in );
	void push( const& BFInst bfin );
	bool mayMove();
	bool mayHalt();
    private:
	void calcMoveAndHalt();
	void endLoop();
	bool mayMove;
	bool mayHalt;
	bool calcSinceLastUpdate;
	unsigned int openContextDepth;
	bool rootContext;
	std::vector<AbsInst*> contentvec;
};

#endif // BF2C_ABSCONTEXT_HPP
