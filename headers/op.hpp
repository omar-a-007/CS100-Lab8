#ifndef __OP_HPP__
#define __OP_HPP__

#include <sstream>

#include "base.hpp"

class Op : public Base {

	protected:
		double value; 
	public:
		Op(double value) : Base(), value(value) { }
		virtual double evaluate() { return value; }
		virtual std::string stringify() { return std::to_string(value); }

		void print(std::ostream& stream = std::cout) override {stream << value;}
		int number_of_children() override {return 0;}
        Base* get_child(int i)	 override {return nullptr;}

        void accept(Visitor* visitor) override;
};

#endif //__OP_HPP__