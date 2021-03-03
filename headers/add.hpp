#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add : public Base {

	public:
		Add() : Base() { }
		Add(Base* x, Base* y) : Base(x, y) { }
		virtual double evaluate() { return x->evaluate() + y->evaluate(); }
		virtual std::string stringify() { return "(" + x->stringify() + " + " + y->stringify() + ")"; }

		void print(std::ostream& stream = std::cout) override {stream << "+";}

		int number_of_children() override;

        Base* get_child(int i) override
		{
			if (i == 0) return x;
			else if (i == 1) return y;
			return nullptr;
		}

        void accept(Visitor* visitor, int index) override{
  		if(index == 0){
			visitor->visit_add_begin(this);
		}	
		else if(index == 1) {
			visitor->visit_add_middle(this);
		}

		else {
			visitor->visit_add_end(this);
		}	
	}
};

#endif // __ADD_HPP__
