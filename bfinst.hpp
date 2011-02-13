#ifndef BF2C_INST_HPP
#define BF2C_INST_HPP
#include <string>
	
//! \brief An object of this class holds a single brainfuck instruction, and
//!        the number of times it should be repeated, if this is relevant.
//!
//! Due to brainfuck having instructions that are the precise opposite of
//! another instruction (+ and -, > and <), only 6 are needed, and another is
//! added to provide comments.
class BFInst {
    public:
	//! Type of the instruction.
	enum {
		move,
		add,
		output,
		input,
		loopstart,
		loopend
	} type;
	//! Constructor, sets the instruction to be of a certain type.
	BFInst( char c );
	//! Increases the count of the instruction, if this is relevant, or
	//! throws if it isn't.
	void operator++();
	//! Decreases the count of the instruction, if this is relevant, or
	//! throws if it isn't.
	void operator--();
	//! Outputs the C instruction equivalent to this.
	std::string toC() const;

    private:
	// How many times the instruction must be performed.
	int count;
};

#endif // BF2C_INST_HPP
