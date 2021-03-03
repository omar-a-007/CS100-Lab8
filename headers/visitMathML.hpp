#ifndef __VISIT_MATHML_HPP__
#define __VISIT_MATHML_HPP__

#include <string>
#include <iostream>

#include "visitor.hpp"
#include "iterator.hpp"

class VisitMathML : public Visitor {
    private:
        std::string print; 
        unsigned indent;
        std::string repeat(unsigned num, const std::string& input = "  ")
        {
            std::string ret;
            ret.reserve(input.size() * num);
            while (num--) ret += input;
            return ret;
        }
    public:
        std::string PrintMathML(Base* ptr)
        {
            print = "";
            print += "<math>\n";
            indent = 0;
            Iterator iter (ptr);
            while (!iter.is_done())
            {
                iter.current_node()->accept(this, iter.current_index());
		        iter.next();
		    }
            print += "</math>\n";
            return print;
        }
        virtual void visit_rand(Rand* node)        { print += repeat(indent) + "<cn>" + node->print() + "</cn>\n"; }
        virtual void visit_op(Op* node)            { print += repeat(indent) + "<cn>" + node->print() + "</cn>\n"; }
        virtual void visit_add_begin(Add* node)    { print += repeat(indent) + "<apply>\n" + repeat(++indent) + "<plus/>\n"; }
        virtual void visit_sub_begin(Sub* node)    { print += repeat(indent) + "<apply>\n" + repeat(++indent) + "<minus/>\n"; }       
        virtual void visit_mult_begin(Mult* node)  { print += repeat(indent) + "<apply>\n" + repeat(++indent) + "<times/>\n"; }       
        virtual void visit_div_begin(Div* node)    { print += repeat(indent) + "<apply>\n" + repeat(++indent) + "<divide/>\n"; }
        virtual void visit_pow_begin(Pow* node)    { print += repeat(indent) + "<apply>\n" + repeat(++indent) + "<power/>\n"; }
                        
        virtual void visit_add_end(Add* node)      { print +=  repeat(--indent) + "</apply>\n"; }
        virtual void visit_sub_end(Sub* node)      { print +=  repeat(--indent) + "</apply>\n"; }
        virtual void visit_mult_end(Mult* node)    { print +=  repeat(--indent) + "</apply>\n"; }
        virtual void visit_div_end(Div* node)      { print +=  repeat(--indent) + "</apply>\n"; }
        virtual void visit_pow_end(Pow* node)      { print +=  repeat(--indent) + "</apply>\n"; }

        virtual void visit_add_middle(Add* node)   { }
        virtual void visit_sub_middle(Sub* node)   { }
        virtual void visit_mult_middle(Mult* node) { }
        virtual void visit_div_middle(Div* node)   { }
        virtual void visit_pow_middle(Pow* node)   { }
};

#endif
