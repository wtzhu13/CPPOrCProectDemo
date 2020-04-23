# include "test.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
 
using namespace std;

void func(int (*a)[3])
{

}
 
int main(int argc, const char *argv[])
{
    int a[2][3] = {1, 2, 3, 4, 5, 6};
    func(a);

    return 0;
}