#ifndef __ITERATOR_TEST_HPP__
#define __ITERATOR_TEST_HPP__

#include "gtest/gtest.h"

#include "../headers/base.hpp"
#include "../headers/op.hpp"
#include "../headers/rand.hpp"
#include "../headers/add.hpp"
#include "../headers/sub.hpp"
#include "../headers/mult.hpp"
#include "../headers/div.hpp"
#include "../headers/pow.hpp"

#include "../headers/visitor.hpp"
#include "../headers/iterator.hpp"

/*
TEST(IteratorTest, emptySimpleTree){
	Base *test = nullptr, *x = nullptr, *y = nullptr;

    std::string print = "";
    Iterator iter (test);
    EXPECT_TRUE(iter.is_done());
    while (!iter.is_done())
    {

        print += iter.current_node()->print();
        iter.next();
    }
    EXPECT_TRUE(iter.is_done());
	EXPECT_EQ(print, "");

	delete test, x, y;
}
*/

TEST(IteratorTest, iterateSingleNode){
	Base *test = nullptr, *x = nullptr, *y = nullptr;

    test = new Op(8);

    std::string print = "";
    Iterator iter (test);
    EXPECT_FALSE(iter.is_done());
    while (!iter.is_done())
    {
        print += iter.current_node()->print();
        iter.next();
    }
    EXPECT_TRUE(iter.is_done());
	EXPECT_EQ(print, "8");

	delete test, x, y;
}

TEST(IteratorTest, iterateEmptyCompositeNode){
	Base *test = nullptr, *x = nullptr, *y = nullptr;

    test = new Add();

    std::string print = "";
    Iterator iter (test);
    while (!iter.is_done())
    {
        print += iter.current_node()->print();
        iter.next();
    }

	EXPECT_EQ(print, "+");

	delete test, x, y;
}


TEST(IteratorTest, iterateCompositeNode){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
    
    x = new Op(4);
    y = new Op(8);
    test = new Add(x,y);

    std::string print = "";
    Iterator iter (test);
    while (!iter.is_done())
    {
        print += iter.current_node()->print();
        iter.next();
    }

	EXPECT_EQ(print, "+4+8+");

	delete test, x, y;
}

TEST(IteratorTest, iterateCompositeNodeIndex){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
    
    x = new Op(4);
    y = new Op(8);
    test = new Add(x,y);

    std::string print = "";
    Iterator iter (test);
    while (!iter.is_done())
    {
        print += std::to_string(iter.current_index());
        iter.next();
    }

	EXPECT_EQ(print, "00102");  // +4+8+ --> 00102 vist number on each item

	delete test, x, y;
}

TEST(IteratorTest, multiLevelTree){
	Base *add, *sub, *mult, *div, *power;
    Base *test = nullptr, *x = new Op(3), *y = new Op(4), *z = new Op(-2);

    add = new Add(z, x);     // 3 + (-2) = 1
    sub = new Sub(y, add);   // 4 - 1 = 3
    mult = new Mult(z, sub); // (-2)  * 3 = -6
    div = new Div(mult, y);  // (-6) / 4 = 1.5
    power = new Pow(div, y); // 1.5 ^ 4 = 5.0625

    test = power;

    std::string print = "";
    Iterator iter (test);
    while (!iter.is_done())
    {
        print += iter.current_node()->print();
        iter.next();
    }

	EXPECT_EQ(print, "**/*-2*-4-+-2+3+-*/4/**4**");

    delete add, sub, mult, div, power;
	delete test, x, y, z;
}

#endif