#include <iostream>
//简单的输入和输出练习

using namespace std;  //这个等于using std::string之类的

int main() {
    //一个项目里面只能有一个main函数（？是函数吗）

    int a, b;
    cin >>a>>b;
    cout <<a<<"+"<<b<<"="<<a+b<<"\n";

    string c;
    cin >> c;
    cout << c.length() << '\n';
    cout << c << '\n';

    return 0;

}