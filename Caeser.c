#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// for add the key with current char
int next(int value, int key);
// for implement encription to the entire text
string encript(string text, int key);

int main(int argc, string argv[])
{
    // user didn't write currectly
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string key = argv[1];
        // convert the key into int
        int int_key = atoi(key);
        if (int_key == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        // take the plane_text of encript from user
        string plane_text = get_string("plaintext:  ");
        // sent data to the function for encript
        string encripted =  encript(plane_text, int_key);
        // finally print encripted data
        printf("ciphertext: %s\n", encripted);
    }
    return 0;
}

int next(int value, int key)
{
    value += key;
    // if overflow
    value %= 26;
    return value;
}

string encript(string text, int key)
{
    // itrate though the text and encript one by one
    int i = 0;
    while (text[i] != '\0')
    {
        // handle smaller latters
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = next(text[i] - 'a', key) + 'a';
        }
        // handle capital latters
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = next(text[i] - 'A', key) + 'A';
        }
        i++;
    }
    // return the encripted text.
    return text;
}