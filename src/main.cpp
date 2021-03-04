#include "../headers/base.hpp"
#include "../headers/op.hpp"
#include "../headers/rand.hpp"
#include "../headers/add.hpp"
#include "../headers/sub.hpp"
#include "../headers/mult.hpp"
#include "../headers/div.hpp"
#include "../headers/pow.hpp"

#include "../headers/visitorLatex.hpp"
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
    VisitorLaTeX* latex = new VisitorLaTeX();

    /*
     * Example # | Example 
     *    1      | 1+(5-0)
     *    2      | 5^2
     *    3      | 2*5
     *    4      | 2/3
     *    5      | (2*5) / (5^2)
     *    6      | (((-2 * (4 - (-2 + 3))) / 4) ^ 4)
     */ 
    Base *neg = new Op(-2), *add, *sub, *mult, *div, *pow;
    Base* a = new Sub(num[5], num[0]);
    
    Base* example1 = new Add(num[1], a);
    Base* example2 = new Pow(num[5], num[2]);
    Base* example3 = new Mult(num[2], num[5]);
    Base* example4 = new Div(num[2], num[3]);
    Base* example5 = new Div(example3, example2);

    add   = new Add(neg,    num[3]);   // 3 + (-2) = 1
    sub   = new Sub(num[4], add);      // 4 - 1 = 3
    mult  = new Mult(neg,   sub);      // (-2)  * 3 = -6
    div   = new Div(mult,   num[4]);   // (-6) / 4 = 1.5
    Base* example6  = new Pow(div,    num[4]);   // 1.5 ^ 4 = 5.0625

    std::cout << "Visitor Method Parsing\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "\nExample 1: 1+(5-0) \n";
    std::cout << latex->PrintLaTeX(example1) << "\n";
    std::cout << mathML->PrintMathML(example1);

    std::cout << "\nExample 2: 5^2 \n";
    std::cout << latex->PrintLaTeX(example2) << "\n";
    std::cout << mathML->PrintMathML(example2);
    
    std::cout << "\nExample 3: 2*5 \n";
    std::cout << latex->PrintLaTeX(example3) << "\n";
    std::cout << mathML->PrintMathML(example3);
    
    std::cout << "\nExample 4: 2/3 \n";
    std::cout << latex->PrintLaTeX(example4) << "\n";
    std::cout << mathML->PrintMathML(example4);
    
    std::cout << "\nExample 5: (2*5) / (5^2) \n";
    std::cout << latex->PrintLaTeX(example5) << "\n";
    std::cout << mathML->PrintMathML(example5);

    std::cout << "\nExample 6: (((-2 * (4 - (-2 + 3))) / 4) ^ 4) \n";
    std::cout << latex->PrintLaTeX(example6) << "\n";
    std::cout << mathML->PrintMathML(example6);

    delete a, neg, add, sub, mult, div, pow;
    delete example1, example2, example3, example4, example5;
    for (auto i : num) delete i;
    for (auto i : r) delete i;
    delete mathML, latex;
}
