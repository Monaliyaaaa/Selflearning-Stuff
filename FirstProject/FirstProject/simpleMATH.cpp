#include <iostream>

/*关于运算符
* 自增自减符号运算： 符号在前，先增减，再表达式；符号在后，先表达式，再增减
* 
*/

int main() {
    int a = 1, b;

    b = 2 * ++a / 3;    //a=2,b=1
    b = 2 * a++ / 3;    //a=2,b=0

    std::cout << a << '\n' << b;
    
    return 0;

}