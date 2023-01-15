#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;
int main()
{
    for(int i=0;i<100;i++)
    {
        printf("%d\n", i);
        
        sleep(1);
        system("clear");
    }
    
    return 0;
}