#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {

	public:
		Div(Base* x, Base* y) : Base(x, y) { }
		virtual double evaluate() { return x->evaluate() / y->evaluate(); }
		virtual std::string stringify() { return "(" + x->stringify() + " / " + y->stringify() + ")"; }
};

#endif // __DIV_HPP__
