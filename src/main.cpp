#include "../headers/base.hpp"
#include "../headers/op.hpp"
#include "../headers/rand.hpp"
#include "../headers/add.hpp"
#include "../headers/sub.hpp"
#include "../headers/mult.hpp"
#include "../headers/div.hpp"
#include "../headers/pow.hpp"

//#include "../headers/visitorLaTeX.hpp"
#include "../headers/visitMathML.hpp"
#include "../headers/iterator.hpp"

#include <iostream>
#include <vector>

int main()
{

    Base* num[10] = {
        new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), 
        new Op(5), new Op(6), new Op(7), new Op(8), new Op(9) };
    Base* r[5] = {new Rand(), new Rand(), new Rand(), new Rand(), new Rand()};

    VisitMathML* mathML = new VisitMathML();
    //VisitorLaTeX* latex = new VisitorLaTeX();

    // Example 1: 1+(5-0)
        Base* a = new Sub(num[5], num[0]);
        Base* example1 = new Add(num[1], a);
    
    // Example 2: 5^2
        Base* example2 = new Pow(num[5], num[2]);
    
    // Example 3: 2*5
        Base* example3 = new Mult(num[2], num[5]);
    
    // Example 4: 2/3
        Base* example4 = new Add(num[2], num[3]);
    
    // Example 5: (2*5) / (5^2)
        Base* example5 = new Div(example3, example2);
    

    
    std::cout << mathML->PrintMathML(example1);
    
    std::cout << "\n\n";
    //std::cout << latex->PrintLaTeX(example1);

    // 
    // std::cout << latex->PrintMathML(b);

    delete a;
    delete example1, example2, example3, example4, example5;
    for (auto i : num) delete i;
    for (auto i : r) delete i;
    delete mathML;
}
