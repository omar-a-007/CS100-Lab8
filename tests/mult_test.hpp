#ifndef __MULT_TEST_HPP__
#define _MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "../headers/base.hpp"
#include "../headers/op.hpp"
#include "../headers/rand.hpp"
#include "../headers/add.hpp"
#include "../headers/sub.hpp"
#include "../headers/mult.hpp"
#include "../headers/div.hpp"
#include "../headers/pow.hpp"

/********************************************
 *  Test New Functions
 ********************************************/

TEST(MultTest, numChildren_BlankConstructor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
  
	test = new Mult();
	EXPECT_EQ(test->number_of_children(), 0);

	delete test, x, y;
}

TEST(MultTest, numChildren_typicalConstructor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4); y = new Op(8);
	test = new Mult(x, y);
	EXPECT_EQ(test->number_of_children(), 2);

	delete test, x, y;
}

TEST(MultTest, getChild_noChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	test = new Mult();
	EXPECT_EQ(test->get_child(0), nullptr); 

	delete test, x, y;
}

TEST(MultTest, getChild_twoChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(8);
	test = new Mult(x, y);
	EXPECT_EQ(test->get_child(0), x); 
	EXPECT_EQ(test->get_child(1), y); 

	// Anything other than 0 or 1 should return nullptr
	EXPECT_EQ(test->get_child(5), nullptr);
	EXPECT_EQ(test->get_child(-1), nullptr);

	delete test, x, y;
}

TEST(MultTest, getChild_twoChildren_accessingChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(8);
	test = new Mult(x, y);
	EXPECT_EQ("4", test->get_child(0)->print()); 
	EXPECT_EQ("8", test->get_child(1)->print()); 

	delete test, x, y;
}

/*
TEST(MultTest, accept_Visitor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	Visitor* = new VisitMathML();
	x = 4;
	y = 8;
	test = new Mult();

	EXPECT_EQ("+", test->print());

	delete test, x, y;
}
*/

TEST(MultTest, print){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	test = new Mult();
	EXPECT_EQ("*", test->print());

	delete test, x, y;
}




/********************************************
 *  Test Old Functions
 ********************************************/

TEST(MultTest, MultTwelve) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(8);
	test = new Mult(x, y);
	EXPECT_EQ(test->evaluate(), 32);
	EXPECT_EQ(test->stringify(), "(4 * 8)");

	delete test, x, y;
}

TEST(MultTest, MultOneNegative) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(-6);
	test = new Mult(x, y);
	EXPECT_EQ(test->evaluate(), -24);

	delete test, x, y;
}

TEST(MultTest, MultTwoNegatives) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(-4);
	y = new Op(-6);
	test = new Mult(x, y);
	EXPECT_EQ(test->evaluate(), 24);

	delete test, x, y;
}

TEST(MultTest, StringNegative) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(3.5);
	y = new Op(-6);
	test = new Mult(x, y);
	EXPECT_EQ(test->stringify(), "(3.5 * -6)");

	delete test, x, y;
}

#endif //__MULT_TEST_HPP__
