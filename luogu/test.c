#include <stdio.h>
#include <threads.h>
#define BUFFER_SIZE 10
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int counter = 0;

void producer()
{
    while(1)
    {
        while(counter == BUFFER_SIZE);
        buffer[in] = in;
        in = (in + 1) % BUFFER_SIZE;
        counter++;
    }
}
void consumer()
{
    while(1)
    {
        while(counter == 0);
        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        counter--;
    }
}

int main()
{
    return 0;
}