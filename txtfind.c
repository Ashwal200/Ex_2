#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORD 30
#define LINE 256
#define LINES 250

int get_word(char word[])
{
    for (int i = 0; i < WORD; i++)
    {
        word[i] = (char) 0;
    }

    int counter = 0;
    for (int i = 0; i < WORD; i++)
    {
        if(scanf("%c", & word[i])<1){
            break;
        }
        else{
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
    char ch = ' ';// " "
    while ((ch != '\n') && (ch != EOF) && length != LINE && (ch != '\r'))
    {
        scanf("%c" , &s[length]);
        ch = s[length];
        length++;

    }
    s[length] = '\0';
    return length;
}

int substring(char *line, char *str)
{
    char *ptr = line;

    if (strstr(ptr , str) != NULL)
    {
        return 1;
    }     
    else 
    return 0;
}

int similar(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if( (len1 -1 > len2) && (len1 < len2) )
    {
        return 0;
    }
    int i = 0, j = 0, different = 0;
    while( different < 2)//the number of different char is small then 2.
    {
        //    aevia         avi
        if( *(str1+i) == *(str2+j)) { i++, j++; } // check the next char in bout str.
        else { different++, i++; } // check the next char in str1.
        if(j == len2+1 && ( i == len1+1) ) { return 1; } // finish of bout str.
    }
    return 0;
}

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
  

    char check[WORD];
    get_word(check);
 
    char user_input[WORD];
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
    