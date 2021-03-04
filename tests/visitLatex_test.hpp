#ifndef __VISIT_LATEX_TEST_HPP__
#define __VISIT_LATEX_TEST_HPP__

#include "gtest/gtest.h"

#include "../headers/base.hpp"
#include "../headers/op.hpp"
#include "../headers/rand.hpp"
#include "../headers/add.hpp"
#include "../headers/sub.hpp"
#include "../headers/mult.hpp"
#include "../headers/div.hpp"
#include "../headers/pow.hpp"

#include "../headers/visitorLatex.hpp"
#include "../headers/iterator.hpp"

TEST(VisitLatextest, basicOp)
{   
    Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9) };

    VisitorLaTeX* latex = new VisitorLaTeX();
    std::string expect = "${0}$\n";    
    EXPECT_EQ(latex->PrintLaTeX(num[0]), expect);

    for (auto i : num) delete i;
    delete latex;
}

// Example 1: 1+(5-0)    
TEST(VisitLatextest, twoComposites)
{
    Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9) };
    
    Base* a = new Sub(num[5], num[0]);
    Base* test = new Add(num[0], a);

    VisitorLaTeX* latex = new VisitorLaTeX();
    std::string expect = "$({0}+({5}-{0}))$\n";
    EXPECT_EQ(latex->PrintLaTeX(test), expect);

    for (auto i : num) delete i;
    delete latex, a, test;
}

TEST(VisitLatextest, multipleComposites)
{
    Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9) };
       
    // Example 3: 2*5
        Base* a = new Mult(num[2], num[5]);
    // Example 2: 5^2
        Base* b = new Pow(num[5], num[2]);
    // Example 5: (2*5) / (5^2)
        Base* test = new Div(a, b);

    VisitorLaTeX* latex = new VisitorLaTeX();
    std::string expect = "$(\\frac{({2}\\cdot{5})}{({5}^{2}))$\n";
    EXPECT_EQ(latex->PrintLaTeX(test), expect);

    for (auto i : num) delete i;
    delete latex, a, b, test;
}

TEST(VisitLatextest, allComposites)
{
    Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9) };
    Base *add, *sub, *mult, *div, *test;
    Base *neg = new Op(-2);

    add   = new Add(neg,    num[3]);   // 3 + (-2) = 1
    sub   = new Sub(num[4], add);      // 4 - 1 = 3
    mult  = new Mult(neg,   sub);      // (-2)  * 3 = -6
    div   = new Div(mult,   num[4]);   // (-6) / 4 = 1.5
    test  = new Pow(div,    num[4]);   // 1.5 ^ 4 = 5.0625

    VisitorLaTeX* latex = new VisitorLaTeX();
    std::string expect = "$((\\frac{({-2}\\cdot({4}-({-2}+{3})))}{{4})^{4})$\n";
    EXPECT_EQ(latex->PrintLaTeX(test), expect);

    for (auto i : num) delete i;
    delete latex, test;
    delete add, sub, mult, div;
}


#endif