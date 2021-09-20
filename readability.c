#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void)
{
    //Input from the user
    string s = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int sentences = 0;
    
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //Check any uppercase or lowercase alphabetic characters
        if (isalpha(s[i]))
        {
            letters++;
        }
        //Check any spaces between the words
        if (isspace(s[i]))
        {
            words++;
        }
        //Check if any sequence of characters that ends with a . or a ! or a ?
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }
    //Calculating L and S
    float L = (letters / (float)words) * 100;
    float S = (sentences / (float)words) * 100;

    //Calculating index using a function (round) and the Coleman-Liau formula  
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index >= 16)
    {
        printf("Grade 16+");
    }
    else 
    {
        printf("Grade %i", index);
    }
    printf("\n");
}