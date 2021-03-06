#ifndef __ADD_HPP__
#define __ADD_HPP__

#include <iostream>
#include "base.hpp"

class Add : public Base {

	public:
		Add() : Base() { }
		Add(Base* x, Base* y) : Base(x, y) { }
		
		virtual double evaluate() { return x->evaluate() + y->evaluate(); }
		virtual std::string stringify() { return "(" + x->stringify() + " + " + y->stringify() + ")"; }

		virtual std::string print() {return "+";}

		//int number_of_children() override;

        Base* get_child(int i) 
		{
			     if (i == 0) return x;
			else if (i == 1) return y;
			return nullptr;
		}

        void accept(Visitor* visitor, int index) {
				 if(index == 0) { visitor->visit_add_begin(this);  }	
			else if(index == 1) { visitor->visit_add_middle(this); }
			else {visitor->visit_add_end(this); }	
		}
};

#endif // __ADD_HPP__
