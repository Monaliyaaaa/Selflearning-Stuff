#include <iostream>
#include <stdlib.h>
//简单的输入和输出练习

/*compile方法是先点三角箭头进行compile&run生成exe，再进行运行
  有点麻烦，下次需要先终止终端再重新compile
  emm不想下visual studio，就这样吧
*/
using std::string;
using std::cout;
using std::cin;

int main(){
    /*int a, b;
    cin >>a>>b;
    cout <<a<<"+"<<b<<"="<<a-b<<"\n";
    */

    string c;
    cin >>c;
    cout <<c.length()<<'\n';
    cout << c <<'\n';

    system("pause");
    return 0;
    
}