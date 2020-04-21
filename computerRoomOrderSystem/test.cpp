# include "test.h"
void func()
{
    for (int i = 0; i < 5; i++)
    {
        cout << globalDate[i] << endl;
    
    }
}

int main()
{
    string name;
    for (int i = 0; i < 5; i++)
    {
        cout << globalDate[i] << endl;
    
    }
    func();
    return 0;
}