#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
	
	public:
		Mult() : Base () { }
		Mult(Base* x, Base* y) : Base(x, y) { }
		virtual double evaluate() { return x->evaluate() * y->evaluate(); }
		virtual std::string stringify() { return "(" + x->stringify() + " * " + y->stringify() + ")"; }

		virtual std::string print() {return "*";}

		//int number_of_children() override;
        Base* get_child(int i) 
		{
			if (i == 0) return x;
			else if (i == 1) return y;
			return nullptr;
		}

        void accept(Visitor* visitor, int index) {
				if(index == 0) { visitor->visit_mult_begin(this);  }	
			else if(index == 1) { visitor->visit_mult_middle(this); }
			else {visitor->visit_mult_end(this); }	
		}
};

#endif //__MULT_HPP__
