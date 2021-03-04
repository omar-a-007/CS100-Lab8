#ifndef __VISIT_MATHML_TEST_HPP__
#define __VISIT_MATHML_TEST_HPP__

#include "gtest/gtest.h"

#include "../headers/base.hpp"
#include "../headers/op.hpp"
#include "../headers/rand.hpp"
#include "../headers/add.hpp"
#include "../headers/sub.hpp"
#include "../headers/mult.hpp"
#include "../headers/div.hpp"
#include "../headers/pow.hpp"

#include "../headers/visitMathML.hpp"
#include "../headers/iterator.hpp"

TEST(VisitMathMLtest, basicOp)
{   
    Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9) };

    VisitMathML* mathML = new VisitMathML();
    std::string expect = "<math>\n  <cn>0</cn>\n</math>\n";    
    EXPECT_EQ(mathML->PrintMathML(num[0]), expect);

    for (auto i : num) delete i;
    delete mathML;
}

// Example 1: 1+(5-0)    
TEST(VisitMathMLtest, twoComposites)
{
    Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9) };
    
    Base* a = new Sub(num[5], num[0]);
    Base* test = new Add(num[0], a);

    VisitMathML* mathML = new VisitMathML();
    std::string expect = "<math>\n    <apply>\n    <plus/>\n    <cn>0</cn>\n      <apply>\n      <minus/>\n      <cn>5</cn>\n      <cn>0</cn>\n    </apply>\n  </apply>\n</math>\n";
    EXPECT_EQ(mathML->PrintMathML(test), expect);

    for (auto i : num) delete i;
    delete mathML, a, test;
}

TEST(VisitMathMLtest, multipleComposites)
{
    Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9) };
       
    // Example 3: 2*5
        Base* a = new Mult(num[2], num[5]);
    // Example 2: 5^2
        Base* b = new Pow(num[5], num[2]);
    // Example 5: (2*5) / (5^2)
        Base* test = new Div(a, b);

    VisitMathML* mathML = new VisitMathML();
    std::string expect = "<math>\n    <apply>\n    <divide/>\n      <apply>\n      <times/>\n      <cn>2</cn>\n      <cn>5</cn>\n    </apply>\n      <apply>\n      <power/>\n      <cn>5</cn>\n      <cn>2</cn>\n    </apply>\n  </apply>\n</math>\n";
    EXPECT_EQ(mathML->PrintMathML(test), expect);

    for (auto i : num) delete i;
    delete mathML, a, b, test;
}

TEST(VisitMathMLtest, allComposites)
{
    Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9) };
    Base *add, *sub, *mult, *div, *test;
    Base *neg = new Op(-2);

    add   = new Add(neg,    num[3]);   // 3 + (-2) = 1
    sub   = new Sub(num[4], add);      // 4 - 1 = 3
    mult  = new Mult(neg,   sub);      // (-2)  * 3 = -6
    div   = new Div(mult,   num[4]);   // (-6) / 4 = 1.5
    test  = new Pow(div,    num[4]);   // 1.5 ^ 4 = 5.0625

    VisitMathML* mathML = new VisitMathML();
    std::string expect = "<math>\n    <apply>\n    <power/>\n      <apply>\n      <divide/>\n        <apply>\n        <times/>\n        <cn>-2</cn>\n          <apply>\n          <minus/>\n          <cn>4</cn>\n            <apply>\n            <plus/>\n            <cn>-2</cn>\n            <cn>3</cn>\n          </apply>\n        </apply>\n      </apply>\n      <cn>4</cn>\n    </apply>\n    <cn>4</cn>\n  </apply>\n</math>\n";
    EXPECT_EQ(mathML->PrintMathML(test), expect);

    for (auto i : num) delete i;
    delete mathML, test;
    delete add, sub, mult, div;
}


#endif