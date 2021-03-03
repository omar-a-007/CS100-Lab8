#ifndef __VISIT_MATHML_HPP__
#define __VISIT_MATHML_HPP__

#include <string>
#include <iostream>

#include "visitor.hpp"
#include "iterator.hpp"

class VisitMathML : public Visitor {
    public:
        std::string PrintMathML(Base* ptr)
        {
            Iterator iter (ptr);
            std::cout  << "<math>";
            while (!iter.is_done())
                ptr->accept(this, iter.current_index());
            std::cout  << "</math>";
        }
        virtual void visit_op(Op* node)
        {
            std::cout << "\t<cn>";
            node->print(std::cout);
            std::cout << "</cn>";
        }
        virtual void visit_rand(Rand* node)
        {            
            std::cout << "\t<cn>";
            node->print(std::cout);
            std::cout << "</cn>";
        }
        virtual void visit_add_begin(Add* node) 
        {
            std::cout << "<apply>\n";
        }
        virtual void visit_add_middle(Add* node)
        {
            std::cout << "\t<plus/>\n\t";
        }
        virtual void visit_add_end(Add* node)
        {
            std::cout << "</apply>";
        }

        virtual void visit_sub_begin(Sub* node)
        {

        }

        virtual void visit_sub_middle(Sub* node)
        {

        }

        virtual void visit_sub_end(Sub* node)
        {

        }

        virtual void visit_mult_begin(Mult* node)
        {

        }

        virtual void visit_mult_middle(Mult* node)
        {

        }

        virtual void visit_mult_end(Mult* node)
        {

        }

        virtual void visit_div_begin(Div* node)
        {

        }

        virtual void visit_div_middle(Div* node)
        {

        }

        virtual void visit_div_end(Div* node)
        {

        }

        virtual void visit_pow_begin(Pow* node)
        {

        }

        virtual void visit_pow_middle(Pow* node)
        {

        }

        virtual void visit_pow_end(Pow* node)
        {

        }


};

#endif