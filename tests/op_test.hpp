#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "../headers/op.hpp"
/********************************************
 *  Test New Functions
 ********************************************/

TEST(OpTest, numChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
  
	test = new Op(8);
	EXPECT_EQ(test->number_of_children(), 0);

	delete test, x, y;
}

TEST(OpTest, getChild1){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	test = new Op(8);
	EXPECT_EQ(test->get_child(0), nullptr); 

	delete test, x, y;
}

TEST(OpTest, getChild2){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	test = new Op(8);
	EXPECT_EQ(test->get_child(5), nullptr); 

	delete test, x, y;
}

TEST(OpTest, getChild3){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	test = new Op(8);
	EXPECT_EQ(test->get_child(-1), nullptr); 

	delete test, x, y;
}

/*
TEST(OpTest, accept_Visitor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	Visitor* = new VisitMathML();
	x = 4;
	y = 8;
	test = new Op();

	EXPECT_EQ("+", test->print());

	delete test, x, y;
}
*/

TEST(OpTest, print){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	test = new Op(8);
	EXPECT_EQ("8", test->print());

	delete test, x, y;
}

TEST(OpTest, printNegative){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	test = new Op(-8);
	EXPECT_EQ("-8", test->print());

	delete test, x, y;
}

TEST(OpTest, printDecimals){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	test = new Op(-8.36);
	EXPECT_EQ("-8.36", test->print());

	delete test, x, y;
}



/********************************************
 *  Test Old Functions
 ********************************************/
TEST(OpTest, OpEvaluateNonZero) {
    Base* test = new Op(8);

    EXPECT_EQ(test->evaluate(), 8);

    delete test;
}

TEST(OpTest, OpZero) {
    Base* test = new Op(0);

    EXPECT_EQ(test->evaluate(), 0);

    delete test;
}

TEST(OpTest, OpNegative) {
    Base* test = new Op(-2);

    EXPECT_EQ(test->evaluate(), -2);

    delete test;
}

TEST(OpTest, OpLarge) {
    Base* test = new Op(8658946);

    EXPECT_EQ(test->evaluate(), 8658946);

    delete test;
}

TEST(OpTest, OpLargeNegative) {
    Base* test = new Op(-8658946);
    
    EXPECT_EQ(test->evaluate(), -8658946);

    delete test;
}

#endif //__OP_TEST_HPP__
