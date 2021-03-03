#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {

	public:
		Div() : Base() { }
		Div(Base* x, Base* y) : Base(x, y) { }
		virtual double evaluate() { return x->evaluate() / y->evaluate(); }
		virtual std::string stringify() { return "(" + x->stringify() + " / " + y->stringify() + ")"; }

		virtual std::string print() {return "/";}

		//int number_of_children() override;
        Base* get_child(int i)
		{
			if (i == 0) return x;
			else if (i == 1) return y;
			return nullptr;
		}

        void accept(Visitor* visitor, int index) {
				if(index == 0) { visitor->visit_div_begin(this);  }	
			else if(index == 1) { visitor->visit_div_middle(this); }
			else {visitor->visit_div_end(this); }	
		}
};

#endif // __DIV_HPP__
