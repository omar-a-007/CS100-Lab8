#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base {

	protected:
		double value; 
	public:
		Rand() : Base(), value(rand() % 100) { }
		virtual double evaluate() { return value; }
		virtual std::string stringify() { return std::to_string(value); }

		virtual std::string print() {return "+";}
		
		//int number_of_children() override {return 0;}
        Base* get_child(int i)	 override {return nullptr;}

		void accept(Visitor* visitor, int index) override{
			visitor->visit_rand(this);
		}

};

#endif //__RAND_HPP__