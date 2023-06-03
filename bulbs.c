#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
void print_bulb(int bit);
void bin_maker(int dec);

int main(void)
{
    // TODO
    string text = get_string("Message: ");
    int i = 0;

    // itreate though the char in text
    while (text[i] != '\0')
    {
        int dec = text[i];

        //print bin
        bin_maker(dec);
        i++;
    }
}

// make bin representation
void bin_maker(int dec)
{
    int bin[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int index = 0;

    // this is the way to make decimal to bin
    while (dec != 0)
    {
        if (dec % 2 == 0)
        {
        }
        else
        {
            bin[index] = 1;
        }
        dec = dec / 2;
        index++;
    }

    // bin should work in reversed
    for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
    {
        print_bulb(bin[j]);
    }
    printf("\n");
}

// print each bit
void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
