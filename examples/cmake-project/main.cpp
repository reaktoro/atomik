#include <iostream>
using namespace std;

#include <Atomik/Formula.hpp>
using namespace Atomik;

int main()
{
    Formula formula("CaCO3");

    cout << "The elemental composition of CaCO3 is:" << endl;
    for(auto symbol : formula.symbols())
        cout << symbol << ": " << formula.coefficient(symbol) << endl;
}
