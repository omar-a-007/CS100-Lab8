#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <sstream>


class Op : public Base {

	protected:
		double value; 
	public:
		Op(double value) : Base(), value(value) { }
		virtual double evaluate() { return value; }
		virtual std::string stringify() { return std::to_string(value); }

		void print(std::ostream& stream = std::cout) {stream << value;}
		//int number_of_children() override {return 0;}
		Base* get_child(int i)	 {return nullptr;}

		void accept(Visitor* visitor, int index) {
			visitor->visit_op(this);
		}
};

#endif //__OP_HPP__
