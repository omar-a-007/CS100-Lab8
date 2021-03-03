#ifndef __POW_HPP__
#define __POW_HPP__

#include <math.h>

#include "base.hpp"

class Pow : public Base {

	public:
		Pow() : Base() { }
		Pow(Base* x, Base* y) : Base(x,y ) { }
		virtual double evaluate() { return pow(x->evaluate(), y->evaluate()); }
		virtual std::string stringify() { return "(" + x->stringify() + " ** " + y->stringify() + ")"; }

		void print(std::ostream& stream = std::cout)  {stream << "**";}
		//int number_of_children() override;
        Base* get_child(int i) 
		{
			if (i == 0) return x;
			else if (i == 1) return y;
			return nullptr;
		}

        void accept(Visitor* visitor, int index) {
				if(index == 0) { visitor->visit_pow_begin(this);  }	
			else if(index == 1) { visitor->visit_pow_middle(this); }
			else {visitor->visit_pow_end(this); }	
		}
};

#endif // __POW_HPP__
