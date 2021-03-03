#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
	
	public:
		Mult(Base* x, Base* y) : Base(x, y) { }
		virtual double evaluate() { return x->evaluate() * y->evaluate(); }
		virtual std::string stringify() { return "(" + x->stringify() + " * " + y->stringify() + ")"; }
};

#endif //__MULT_HPP__
