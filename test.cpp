#include "myset.h"
#include <iostream>
using namespace std;

int main(void)
{
    MySet<int> harder;

    for(int i=0;i<100;i++)
    {
        harder.add(i);

     }

    for(int i=40;i<80;i++)
    {
        harder.remove(i);
    }
    cout<<endl;
    cout<<harder.size()<<endl;
    for(int i=0;i<100;i++){
        if(harder.contains(i))
            cout<<i<<" ";
}

    return 0;
}

