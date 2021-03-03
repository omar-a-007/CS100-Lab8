#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base {

	public:
		Sub(Base* x, Base* y) : Base(x, y) { }
		virtual double evaluate() { return x->evaluate() - y->evaluate(); }
		virtual std::string stringify() { return "(" + x->stringify() + " - " + y->stringify() + ")"; }
};

#endif // __SUB_HPP__

