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

    Base* a = new Sub(num[5], num[0]);
    Base* b = new Add(num[1], a);

    VisitMathML* mathML = new VisitMathML();
    std::cout << mathML->PrintMathML(b);
    
    std::cout << "\n\n";

    // VisitorLaTeX* latex = new VisitorLaTeX();
    // std::cout << latex->PrintMathML(b);

    delete a;
    delete b;
    for (auto i : num) delete i;
    for (auto i : r) delete i;
    delete mathML;
}
