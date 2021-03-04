#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base {
	private:
        std::string removeTrailing (const std::string& s)
        {
            std::string str = s;
            str.erase ( str.find_last_not_of('0') + 1, std::string::npos ); 
            str.erase ( str.find_last_not_of('.') + 1, std::string::npos );
            return str;
        }
	protected:
		double value; 
	public:
		Rand() : Base() { value = rand() % 100; }
		virtual double evaluate() { return value; }
		virtual std::string stringify() { return removeTrailing(std::to_string(value)); }

		virtual std::string print() {return stringify();}

		//int number_of_children() {return 0;}
        Base* get_child(int i) {return nullptr;}

		void accept(Visitor* visitor, int index) {
			visitor->visit_rand(this);
		}

};

#endif //__RAND_HPP__