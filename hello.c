#include <stdio.h>
// this is a header library. It will use for get input from the user.
#include <cs50.h>

int main(void)
{
    // get string is a function for get input form the user as a string.
    // Then We will store them into a variable called name.
    string name = get_string("What's your name? ");
    // finally we will print.
    printf("Hello, %s\n", name);
}