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

		void print(std::ostream& stream = std::cout) override {stream << value;}
		int number_of_children() override {return 0;}
        Base* get_child(int i)	 override {return nullptr;}

        void accept(Visitor* visitor) override;
};

#endif //__RAND_HPP__