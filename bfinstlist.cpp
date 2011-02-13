#include <iterator>
#include <sstream>
#include "bfinstlist.hpp"

BFInstList::BFInstList() {
	startindent = 0;
	lastindent = 0;
}

void BFInstList::push( char c ) {
	if( !instlist.empty() ) {
		switch( c ) {
			case '>':
				if( instlist.back().type == BFInst::move ) {
					++instlist.back();
					return;
				}
				break;
			case '<':
				if( instlist.back().type == BFInst::move ) {
					--instlist.back();
					return;
				}
				break;
			case '+':
				if( instlist.back().type == BFInst::add ) {
					++instlist.back();
					return;
				}
				break;
			case '-':
				if( instlist.back().type == BFInst::add ) {
					--instlist.back();
					return;
				}
				break;
			case '[':
				lastindent++;
				break;
			case ']':
				if( lastindent )
					lastindent--;
				else
					startindent++;
				break;
			case '.':
			case ',':
				break;
			default:
				return;
		}
	}
	instlist.push_back(BFInst(c));
}

std::string BFInstList::toC() {
	std::stringstream ss;
	std::vector<BFInst>::const_iterator it;
	unsigned int indent = startindent;
	for( it = instlist.begin(); it < instlist.end(); ++it ) {
		if( it->type == BFInst::loopend )
			indent--;
		for( unsigned int i = 0; i < indent; ++i ) {
			ss << '\t';
		}
		ss << it->toC();
		if( it->type == BFInst::loopstart )
			indent++;
		ss << '\n';
	}
	return ss.str();
}
