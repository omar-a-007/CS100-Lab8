#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "../headers/base.hpp"
#include "../headers/op.hpp"
#include "../headers/div.hpp"

/********************************************
 *  Test New Functions
 ********************************************/

TEST(DivTest, numChildren_BlankConstructor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
  
	test = new Div();
	EXPECT_EQ(test->number_of_children(), 0);

	delete test, x, y;
}

TEST(DivTest, numChildren_typicalConstructor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4); y = new Op(8);
	test = new Div(x, y);
	EXPECT_EQ(test->number_of_children(), 2);

	delete test, x, y;
}

TEST(DivTest, getChild_noChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	test = new Div();
	EXPECT_EQ(test->get_child(0), nullptr); 

	delete test, x, y;
}

TEST(DivTest, getChild_twoChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(8);
	test = new Div(x, y);
	EXPECT_EQ(test->get_child(0), x); 
	EXPECT_EQ(test->get_child(1), y); 

	// Anything other than 0 or 1 should return nullptr
	EXPECT_EQ(test->get_child(5), nullptr);
	EXPECT_EQ(test->get_child(-1), nullptr);

	delete test, x, y;
}

TEST(DivTest, getChild_twoChildren_accessingChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(8);
	test = new Div(x, y);
	EXPECT_EQ("4", test->get_child(0)->print()); 
	EXPECT_EQ("8", test->get_child(1)->print()); 

	delete test, x, y;
}

/*
TEST(DivTest, accept_Visitor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	Visitor* = new VisitMathML();
	x = 4;
	y = 8;
	test = new Div();

	EXPECT_EQ("+", test->print());

	delete test, x, y;
}
*/

TEST(DivTest, print){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	test = new Div();
	EXPECT_EQ("/", test->print());

	delete test, x, y;
}




/********************************************
 *  Test Old Functions
 ********************************************/

TEST(DivTest, DivTwelve) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(8);
	test = new Div(x, y);
	EXPECT_EQ(test->evaluate(), 0.5);
	EXPECT_EQ(test->stringify(), "(4 / 8)");

	delete test, x, y;
}

TEST(DivTest, DivOneNegative) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(-6);
	y = new Op(4);
	test = new Div(x, y);
	EXPECT_EQ(test->evaluate(), -1.5);

	delete test, x, y;
}

TEST(DivTest, DivTwoNegatives) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(-6);
	y = new Op(-4);
	test = new Div(x, y);
	EXPECT_EQ(test->evaluate(), 1.5);

	delete test, x, y;
}

TEST(DivTest, StringNegative) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(3.5);
	y = new Op(-6);
	test = new Div(x, y);
	EXPECT_EQ(test->stringify(), "(3.5 / -6)");

	delete test, x, y;
}

TEST(DivTest, largeNumber) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(965478264);
	y = new Op(6);
	test = new Div(x, y);
	EXPECT_EQ(test->evaluate(), 160913044);
	EXPECT_EQ(test->stringify(), "(965478264 / 6)");

	delete test, x, y;
}

TEST(DivTest, largeNegNumber) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(965478264);
	y = new Op(-6);
	test = new Div(x, y);
	EXPECT_EQ(test->evaluate(), -160913044);
	EXPECT_EQ(test->stringify(), "(965478264 / -6)");

	delete test, x, y;
}

#endif //__DIV_TEST_HPP__
