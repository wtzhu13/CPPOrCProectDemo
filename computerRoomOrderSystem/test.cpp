# include "test.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
 
using namespace std;
 
int main(int argc, const char *argv[]){
    string pwd = "123456";//这是用来验证用户输入的密码，即正确的密码。
    char upwd[20];//用来存储用户输入的每一个字符。
    string username;
    cout << "请输入用户名: ";
    cin >> username;
    cout << "请输入密码：";
    int i = 0;
    char c;
    const char *ptr = upwd; //ptr指向upwd，这是为了将字符数组转换为string类型，方便验证输入是否正确
    int k = 0;
    while(((c=getchar())!=EOF) && i<20){
        if(c=='\n'){ //用户一共会输入2次回车，第一次是用户名之后，第二次是密码之后.只判断第2次的回车.
          ++k;
          cout << '\b';//这行代码是我调试半天后加上去的，用户输入用户名后有个回车也读进来了，把回车符删掉。
          if(k>1){
              string uupw(ptr);
              if(uupw == pwd){
                  cout << "系统登录成功!"<<endl;
              } else {
                  cout << "用户名密码错误，系统退出。"<<endl;
              }
              break;
          }
        } else {
            //坑吃半天，就为了下面这4行代码，将用户的输入保存在upwd中，输入一个删掉一个,其中'\b'是回退符.
            upwd[i] = c;
            cout << '\b';
            cout << '*';
            i++;
        }
      }
      return 0;
}