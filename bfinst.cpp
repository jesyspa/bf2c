#include <sstream>
#include "bfinst.hpp"

BFInst::BFInst( char c ) {
	switch( c ) {
		case '>':
			type = move;
			count = 1;
			break;
		case '<':
			type = move;
			count = -1;
			break;
		case '+':
			type = add;
			count = 1;
			break;
		case '-':
			type = add;
			count = -1;
			break;
		case '.':
			type = output;
			count = 0;
			break;
		case ',':
			type = input;
			count = 0;
			break;
		case '[':
			type = loopstart;
			count = 0;
			break;
		case ']':
			type = loopend;
			count = 0;
			break;
		default:
			throw; // Should never happen
	}
}

void BFInst::operator++() {
	count++;
}

void BFInst::operator--() {
	count--;
}

std::string BFInst::toC() const {
	std::stringstream ss;
	switch( type ) {
		case move:
			if( !count ) {
				return "/* Unused pointer arithmetic. */";
			} else if( count > 0 ) {
				ss << "ptr += " << count << ';';
				return ss.str();
			} else {
				ss << "ptr -= " << -count << ';';
				return ss.str();
			}
		case add:
			if( !count ) {
				return "/* Unused arithmetic. */";
			} else if( count > 0 ) {
				ss << "*ptr += " << count << ';';
				return ss.str();
			} else {
				ss << "*ptr -= " << count << ';';
				return ss.str();
			}
		case output:
			return "putchar( *ptr );";
		case input:
			return "*ptr = getchar();";
		case loopstart:
			return "while( *ptr ) {";
		case loopend:
			return "}";
	}
	return "ERROR!";
}
