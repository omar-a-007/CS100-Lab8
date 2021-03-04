#ifndef __VISIT_MATHML_HPP__
#define __VISIT_MATHML_HPP__

#include <string>
#include <sstream>

#include "visitor.hpp"
#include "iterator.hpp"

class VisitMathML : public Visitor {
    private:
        std::stringstream stream;
        unsigned indent;
        std::string repeat(unsigned num, const std::string& input = "  ")
        {
            std::string ret;
            //for (num; num > 0; num--) ret += input;
            while (num--) ret += input;
            return ret;
        }
    public:
        std::string PrintMathML(Base* ptr)
        {
            std::stringstream().swap(stream); // Clears the stringstreams error stat and emptys its contents
            stream << "<math>\n";
            indent = 1;
            Iterator iter (ptr);
            while (!iter.is_done())
            {
                iter.current_node()->accept(this, iter.current_index());
		        iter.next();
		    }
            stream << "</math>\n";
            return stream.str();
        }
        virtual void visit_rand(Rand* node)        { stream << repeat(indent) << "<cn>" + node->print() << "</cn>\n"; }
        virtual void visit_op(Op* node)            { stream << repeat(indent) << "<cn>" + node->print() << "</cn>\n"; }
        virtual void visit_add_begin(Add* node)    { stream << repeat(indent) << "<apply>\n" << repeat(++indent) << "<plus/>\n"  ; }
        virtual void visit_sub_begin(Sub* node)    { stream << repeat(indent) << "<apply>\n" << repeat(++indent) << "<minus/>\n" ; }       
        virtual void visit_mult_begin(Mult* node)  { stream << repeat(indent) << "<apply>\n" << repeat(++indent) << "<times/>\n" ; }       
        virtual void visit_div_begin(Div* node)    { stream << repeat(indent) << "<apply>\n" << repeat(++indent) << "<divide/>\n"; }
        virtual void visit_pow_begin(Pow* node)    { stream << repeat(indent) << "<apply>\n" << repeat(++indent) << "<power/>\n" ; }
                            
        virtual void visit_add_end(Add* node)      { stream << repeat(--indent) << "</apply>\n"; }
        virtual void visit_sub_end(Sub* node)      { stream << repeat(--indent) << "</apply>\n"; }
        virtual void visit_mult_end(Mult* node)    { stream << repeat(--indent) << "</apply>\n"; }
        virtual void visit_div_end(Div* node)      { stream << repeat(--indent) << "</apply>\n"; }
        virtual void visit_pow_end(Pow* node)      { stream << repeat(--indent) << "</apply>\n"; }

        virtual void visit_add_middle(Add* node)   { }
        virtual void visit_sub_middle(Sub* node)   { }
        virtual void visit_mult_middle(Mult* node) { }
        virtual void visit_div_middle(Div* node)   { }
        virtual void visit_pow_middle(Pow* node)   { }
};

#endif
