#include <QCoreApplication>
#include"template.h"
#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //普通union类型
    union Token{
        char cval;
        int ival;
        double dval;
    };
    Token first_token = {'a'};
    Token last_token;
    Token *pt =new Token;

    last_token.cval = 'z';
    pt->ival = 42;
   //匿名union
    union{
      char cval_1;
      int ival_1;
      double dval;
    };
    cval_1 = 'c';
    ival_1 = 42;

//使用模板,实例化
    cout << compare(1, 0) << endl;
    vector<int> vec1{1,2,3}, vec2{4,5,6};
    cout<<compare(vec1,vec2)<<endl;
    Blob<int> ia;
    Blob<int> ia2 = {0, 1, 2, 3, 4};
    Blob<string>articles = {"q", "an" "the"};
    Blob<int> squares = {0, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (size_t i=0; i!=squares.size(); ++i)
        squares[i] = i*i;
    return a.exec();
}
