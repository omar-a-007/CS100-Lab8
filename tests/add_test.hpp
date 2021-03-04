#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "../headers/op.hpp"
#include "../headers/add.hpp"

/********************************************
 *  Test New Functions
 ********************************************/

TEST(AddTest, numChildren_BlankConstructor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
  
	test = new Add();
	EXPECT_EQ(test->number_of_children(), 0);

	delete test; delete x; delete y;
}

TEST(AddTest, numChildren_typicalConstructor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4); y = new Op(8);
	test = new Add(x, y);
	EXPECT_EQ(test->number_of_children(), 2);

	delete test; delete x; delete y;
}

TEST(AddTest, getChild_noChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	test = new Add();
	EXPECT_EQ(test->get_child(0), nullptr); 

	delete test; delete x; delete y;
}

TEST(AddTest, getChild_twoChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(8);
	test = new Add(x, y);
	EXPECT_EQ(test->get_child(0), x); 
	EXPECT_EQ(test->get_child(1), y); 

	// Anything other than 0 or 1 should return nullptr
	EXPECT_EQ(test->get_child(5), nullptr);
	EXPECT_EQ(test->get_child(-1), nullptr);

	delete test; delete x; delete y;
}

TEST(AddTest, getChild_twoChildren_accessingChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(8);
	test = new Add(x, y);
	EXPECT_EQ("4", test->get_child(0)->print()); 
	EXPECT_EQ("8", test->get_child(1)->print()); 

	delete test; delete x; delete y;
}

/*
TEST(AddTest, accept_Visitor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	Visitor* = new VisitMathML();
	x = 4;
	y = 8;
	test = new Add();

	EXPECT_EQ("+", test->print());

	delete test; delete x; delete y;
}
*/

TEST(AddTest, print){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	test = new Add();
	EXPECT_EQ("+", test->print());

	delete test; delete x; delete y;
}




/********************************************
 *  Test Old Functions
 ********************************************/

TEST(AddTest, AddTwelve) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(8);
	test = new Add(x, y);
	EXPECT_EQ(test->evaluate(), 12);
	EXPECT_EQ(test->stringify(), "(4 + 8)");

	delete test; delete x; delete y;
}

TEST(AddTest, AddOneNegative) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(-6);
	test = new Add(x, y);
	EXPECT_EQ(test->evaluate(), -2);

	delete test; delete x; delete y;
}

TEST(AddTest, AddTwoNegatives) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(-4);
	y = new Op(-6);
	test = new Add(x, y);
	EXPECT_EQ(test->evaluate(), -10);

	delete test; delete x; delete y;
}

TEST(AddTest, StringNegative) {
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(3.5);
	y = new Op(-6);
	test = new Add(x, y);
	EXPECT_EQ(test->stringify(), "(3.5 + -6)");

	delete test; delete x; delete y;
}

#endif