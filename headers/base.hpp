#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
#include <iostream>
#include <sstream>

#include "visitor.hpp"

class Base {
    protected:
        Base* x;
        Base* y;

    public:
        Base() : x(nullptr), y(nullptr) { }
        Base(Base* x, Base* y) : x(x), y(y) { }
        virtual ~Base()  {delete x; delete y;};

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;

        virtual void print(std::ostream& stream = std::cout) = 0;
        virtual int number_of_children() = 0;
        virtual Base* get_child(int i) = 0;

        virtual void accept(Visitor* visitor) = 0;
};

#endif //__BASE_HPP__
