#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add : public Base {

	public:
		Add(Base* x, Base* y) : Base(x, y) { }
		virtual double evaluate() { return x->evaluate() + y->evaluate(); }
		virtual std::string stringify() { return "(" + x->stringify() + " + " + y->stringify() + ")"; }
};

#endif // __ADD_HPP__
