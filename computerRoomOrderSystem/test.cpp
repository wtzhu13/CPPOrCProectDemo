#include <iostream>
#include <string>
using namespace std;

void func(string * name)
{
    * name = "tom";
}

int main()
{
    string name = "1";
    func(&name);
    cout << name << endl;
    return 0;
}