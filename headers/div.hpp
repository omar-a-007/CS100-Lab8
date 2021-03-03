#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {

	public:
		Div() : Base() { }
		Div(Base* x, Base* y) : Base(x, y) { }
		virtual double evaluate() { return x->evaluate() / y->evaluate(); }
		virtual std::string stringify() { return "(" + x->stringify() + " / " + y->stringify() + ")"; }

		void print(std::ostream& stream = std::cout) override {stream << "/";}
		int number_of_children() override;
        Base* get_child(int i) override
		{
			if (i == 0) return x;
			else if (i == 1) return y;
			return nullptr;
		}

        void accept(Visitor* visitor) override;
};

#endif // __DIV_HPP__
