
#include <iostream>

#include "Shape.h"

using namespace std;
int main()
{
    pointLSQ p(10, 10, 10, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8);
    ShapeLSQ S(2,  p);
    cout << S.Square(2) << "  " << S.Volume(2) << endl;
    S.shift(3, 6, 7);
}

