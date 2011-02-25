#include <string>
#include <sstream>
#include "abscontext.hpp"
#include "bfinst.hpp"

AbsContext::AbsContext( bool root ) : calcSinceLastUpdate( false ),
    openContextDepth( 0 ), rootContext( root ) {
}

std::string AbsContext::toC( unsigned int tabDepth ) const {
	std::stringstream ss;
	if( !rootContext ) {
		for( size_t i = 0; i < tabDepth; ++i ) 
			ss << '\t';
		ss << "while( *ptr ) {\n";
	}
	for( size_t a = 0; a < contentvec.size(); ++a ) {
		ss << contentvec[a]->toC(tabDepth+1);
	}
	if( !rootContext ) {
		for( size_t i = 0; i < tabDepth; ++i ) 
			ss << '\t';
		ss << "}\n";
	}
	return ss.str();
}

void AbsContext::push( AbsInst* in );

void AbsContext::push( const& BFInst bfin ) {
	AbsInst* in;
	switch( bfin.type ) {
		case BFInst::add:
			in = new AbsAdd( bfin );
			break;
		case BFInst::move:
			in = new AbsMove( bfin );
			break;
		case BFInst::output:
			in = new AbsOutput( bfin );
			break;
		case BFInst::input:
			in = new AbsInput( bfin );
			break;
		case BFInst::loopstart:
			in = new AbsContext( false );
			openContextDepth++;
			break;
		case BFInst::loopend:
			endLoop();
			return;
	}
}

bool AbsContext::mayMove();
bool AbsContext::mayHalt();
void AbsContext::calcMoveAndHalt();

void AbsContext::endLoop() {
	if( !openContextDepth )
		throw; // Closing bracket without matching opening bracket.
	openContextDepth--;
	static_cast<AbsContext*>(contentvec.last())->endLoop();
}
