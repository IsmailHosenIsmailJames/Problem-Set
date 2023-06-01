#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Get the text from user
    string text = get_string("Text: ");
    // initially all values ate 0;
    int word = 0;
    int sentence = 0;
    int latter = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        // Cheak if have space. If have count word.
        if (text[i] == ' ')
        {
            word++;
        }

        // Cheak if have any sentence compleation. If have count sentence.
        else if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentence++;
        }

        // Cheak if the char betwwen A and z. If so count latter.
        else if (text[i] >= 'A' && text[i] <= 'z')
        {
            latter++;
        }
    }
    word++;
    // Calculate the readability
    int ans = round(0.0588 * (((float)latter / (float)word) * 100) - 0.296 * (((float)sentence / (float)word) * 100) - 15.8);
    // at last print with the condition that has been discribed
    if (ans < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (ans < 16)
    {
        printf("Grade %d\n", ans);
    }
    else
    {
        printf("Grade 16+\n");
    }
}