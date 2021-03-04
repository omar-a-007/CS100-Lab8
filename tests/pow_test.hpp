#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

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

TEST(PowTest, numChildren_BlankConstructor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
  
	test = new Pow();
	EXPECT_EQ(test->number_of_children(), 0);

	delete test, x, y;
}

TEST(PowTest, numChildren_typicalConstructor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4); y = new Op(8);
	test = new Pow(x, y);
	EXPECT_EQ(test->number_of_children(), 2);

	delete test, x, y;
}

TEST(PowTest, getChild_noChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	test = new Pow();
	EXPECT_EQ(test->get_child(0), nullptr); 

	delete test, x, y;
}

TEST(PowTest, getChild_twoChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(8);
	test = new Pow(x, y);
	EXPECT_EQ(test->get_child(0), x); 
	EXPECT_EQ(test->get_child(1), y); 

	// Anything other than 0 or 1 should return nullptr
	EXPECT_EQ(test->get_child(5), nullptr);
	EXPECT_EQ(test->get_child(-1), nullptr);

	delete test, x, y;
}

TEST(PowTest, getChild_twoChildren_accessingChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(8);
	test = new Pow(x, y);
	EXPECT_EQ("4", test->get_child(0)->print()); 
	EXPECT_EQ("8", test->get_child(1)->print()); 

	delete test, x, y;
}

/*
TEST(PowTest, accept_Visitor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	Visitor* = new VisitMathML();
	x = 4;
	y = 8;
	test = new Pow();

	EXPECT_EQ("+", test->print());

	delete test, x, y;
}
*/

TEST(PowTest, print){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	test = new Pow();
	EXPECT_EQ("**", test->print());

	delete test, x, y;
}




/********************************************
 *  Test Old Functions
 ********************************************/

TEST(PowTest, PowTwelve) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(8);
	test = new Pow(x, y);
	EXPECT_EQ(test->evaluate(), 65536);
	EXPECT_EQ(test->stringify(), "(4 ** 8)");

	delete test, x, y;
}

TEST(PowTest, PowOneNegative) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(10);
	y = new Op(-2);
	test = new Pow(x, y);
	EXPECT_EQ(test->evaluate(), 0.01);

	delete test, x, y;
}

TEST(PowTest, PowTwoNegatives) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(-10);
	y = new Op(-2);
	test = new Pow(x, y);
	EXPECT_EQ(test->evaluate(), 0.01);

	delete test, x, y;
}

TEST(PowTest, StringNegative) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(-3.5);
	y = new Op(6);
	test = new Pow(x, y);
	EXPECT_EQ(test->stringify(), "(-3.5 ** 6)");

	delete test, x, y;
}

#endif //__POW_TEST_HPP__
