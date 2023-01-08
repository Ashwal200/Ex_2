#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORD 30
#define LINE 256
#define LINES 250

int get_word(char word[])
{
    int counter = 0;
    // Add char by char to the word.
    for (int i = 0; i < WORD; i++)
    {
        // Break if the char is invalid.
        if(scanf("%c", & word[i])<1){
            break;
        }
        else{
            // If the word end break.
            if (word[i] == '\n' || word[i] == '\t' || word[i] == ' '||word[i]=='\r')
            {
                word[i] = '\0';
                break;
            }
            else
            {
                counter++;
            }
        }
    }
    
   return counter;
}

int get_line(char s[])
{
    int length = 0;
    char ch = ' ';
    //Scan the user input into s[].
    while ((ch != '\n') && (ch != EOF) && length != LINE && (ch != '\r'))
    {
        scanf("%c", &s[length]);
        ch = s[length];
        length++;

    }
    s[length] = '\0';
    return length;
}

//Check if the word is a substring of the line.
int substring(char *line, char *str)
{
    char *ptr = line;
    // Check if the word substring.
    if (strstr(ptr , str) != NULL)
    {
        return 1;
    }     
    else 
    return 0;
}

//Check if one word is similar to the other (only for 0 or 1 changes).
int similar(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if( (len1 -1 > len2) && (len1 < len2) )
    {
        return 0;
    }
    int i = 0, j = 0, different = 0;
    while( different < 2)//The number of different char is smaller then 2.
    {
           
        if( *(str1+i) == *(str2+j)) { i++, j++; } // Check the next char in bout str.
        else { different++, i++; } // check the next char in str1.
        if(j == len2+1 && ( i == len1+1) ) { return 1; } // finish of bout str.
    }
    return 0;
}
//If the word is in the line -> print the line.
void print_lines(char * str){

    char line[LINE] = {0};
    for (int i = 0; i < LINES ; i++)
    {
        get_line(line);
        if (feof(stdin))
        {
            break;
        }

        if (substring(line , str))
        {
            printf("%s" , line);
        }

        
     }
}
// If there is a word that similar to the word to check, print it.
void print_similar_words(char *str)
{
    char line[LINE];
    for (int i = 0; i < LINES; i++)
    {
        get_line(line);
        char *ptr_line;
        if (feof(stdin))
        {
            break;
        }
        else
        {
        // Split the line into a list of words
            ptr_line = strtok(line, " ");

        // Iterate through the list of words
            while (ptr_line != NULL) {
                if (*(ptr_line + (strlen(ptr_line)-1)) == '\n')
                {
                    *(ptr_line + (strlen(ptr_line)-1)) = '\0';
                }
                int flage = similar(ptr_line, str);
                if (flage)
                {
                    printf("%s\n",ptr_line);
                }
                ptr_line = strtok(NULL, " ");
                }
        }
    }
}

int main()
{
  
    //Get the word to check.
    char check[WORD];
    get_word(check);
 
    //Get the user decision (a or b).
    char user_input[LINE];
    get_line(user_input);



    if (user_input[0] == 'a')
    {
        print_lines(check);
    }

    else if (user_input[0] == 'b')
    {
        print_similar_words(check);
    }

    return 0;
}
    
