#ifndef __RAND_HPP__
#define __RAND_HPP__

#include <time.h>

#include "base.hpp"

class Rand : public Base {

	protected:
		double value; 
	public:
		Rand() : Base() { 
			srand(time(NULL));
			value = rand() % 100;
		}
		virtual double evaluate() { return value; }
		virtual std::string stringify() { return std::to_string(value); }

		virtual std::string print() {return std::to_string(value);}

		//int number_of_children() {return 0;}
        Base* get_child(int i) {return nullptr;}

		void accept(Visitor* visitor, int index) {
			visitor->visit_rand(this);
		}

};

#endif //__RAND_HPP__