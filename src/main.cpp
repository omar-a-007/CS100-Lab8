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
    /*
     * Example # | Example 
     *    1      | 1+(5-0)
     *    2      | 5^2
     *    3      | 2*5
     *    4      | 2/3
     *    5      | (2*5) / (5^2)
     *    6      | (((-2 * (4 - (-2 + 3))) / 4) ^ 4)
     */ 
    VisitMathML* mathML = new VisitMathML();
    VisitorLaTeX* latex = new VisitorLaTeX();

    Base* num0 = new Op(0);
    Base* num1 = new Op(0);
    Base* num2 = new Op(0);
    Base* num3 = new Op(0);
    Base* num4 = new Op(0);
    Base* num5 = new Op(0);
    Base* neg = new Op(-2);
    Base* a = new Sub(num5, num0);
    
    Base* example1 = new Add(num1, a);
    Base* example2 = new Pow(num5, num2);
    Base* example3 = new Mult(num2, num5);
    Base* example4 = new Div(num2, num3);
    Base* example5 = new Div(example3, example2);

    Base* add   = new Add(neg,    num3);   // 3 + (-2) = 1
    Base* sub   = new Sub(num4,   add);    // 4 - 1 = 3
    Base* mult  = new Mult(neg,   sub);    // (-2)  * 3 = -6
    Base* div   = new Div(mult,   num4);   // (-6) / 4 = 1.5
    Base* example6  = new Pow(div, num4);   // 1.5 ^ 4 = 5.0625

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

    
    delete example1; delete example2; delete example3; delete example4; delete example5; delete example6;
    delete a; delete neg; delete add; delete sub; delete mult; delete div; 
    delete num0; delete num1; delete num2; delete num3; delete num4; delete num5;
    delete mathML; delete latex;
}
