#include <stdio.h>
#include <string.h>

#define MAXLINE 250
#define LINE 256
#define WORD 30

//get a pointer to string and check if the srtring end with '\n' or '\t'
int CheckEnd(char *str)
{
    int j = strlen(str)-1;
    if (str[j] == '\t' || str[j] == '\n')
    {
        return 1;
    }
    return 0;
}

//get two pointers to string and chek if the str 'word' is represnt of 'comper' with one strike 
int Similar (char *Compare, char *Word){
    int lenWord = strlen(Word), lenComp = strlen(Compare);
    int i = 0; //Pointer for string Compare
    int j = 0;; //Pointer for string Word
    int temp = 0; //Count the chars are different, need to be one
    if(CheckEnd(Compare))
    {
        lenComp--;
    }
    if(lenComp < lenWord)
    {
        return 0;
    }
    else if (lenWord == lenComp)
    {
        if(strcmp(Compare, Word) == 0)
        {
            return 1;
        }
    }
    else if(lenComp > lenWord+1)
    {
        return 0;
    }

    for(int j = 0; j < lenComp && i < lenWord; j++){

        if(Compare[j] == Word[i])
        {
            i++;
        }
        else 
        {
            temp++;
        } 

    }
    if(temp > 1)
    { 
        return 0;
    }
    return 1;    
}

//get pointer to string 'line' and divide into words and fill 'WordArr'
int SplitWordsIntoArray(char *line, char **WordArr)
{
    int i = 0;
    char *redix = strtok(line, " ");
    while (redix != NULL)
    {
        WordArr[i++] = redix;
        redix = strtok(NULL, " ");
    }
    return i;
}


//get two pointers to string and chek if the str 'small' is substring of 'small'.
int CheckSub(char* big, char* small)
{
    if(strstr(big, small) != NULL)
    {
        return 1;
    }
    return 0;
}

//get line and print it if the string 'Word' appear in the line
void CaseA(char line[], char *Word)
{
    if (CheckSub(line, Word) == 1)
    {
        printf("%s", line);
    }
}

//get arr char and the num of words in the arr and if the str 'Word' and a word from arr are 'Similar' it will print it
void CaseB(char **WordArray, char *Word, int CounterWord)
{
    for (int i = 0; i < CounterWord; i++)
    {
        //Check if the word is substring of the keyword with one strikes
        if(Similar(WordArray[i], Word) == 1)
        {
            printf("%s", WordArray[i]);
            if(CheckEnd(WordArray[i]) == 0)
            {
                printf("\n");
            }
        }
    }
    
}

int main(){
    char *WordArray[10] = {0};
    char letter[WORD];
    char Word[WORD];
    int  counter = 1;
    char temp[LINE];
    char line[LINE];
    int CountWord;
    char* choosB = "b\n";
    char* choosA = "a\n";

    //get one line from txt and chek it
    while(fgets(temp, LINE , stdin) != NULL)
    {   
        //implimenting the line we get to string
        strcpy(line, temp); 
        //divide into words and fill 'WordArray'
        CountWord = SplitWordsIntoArray(temp, WordArray); 

        //in the first iteration get the word and the user chois
        if(counter == 1)
        { 
            strcpy(Word , WordArray[0]);
            strcpy(letter, WordArray[1]);
        }
        //exscut user chois a
        if(strcmp(letter, choosA) == 0 && counter > 2)
        {
            CaseA(line, Word);
        }
        //exscut user chois b
        if(strcmp(letter, choosB) == 0 && counter > 2)
        {
            CaseB(WordArray, Word, CountWord);
        }

        //check max line
        if(counter== MAXLINE)
        {
            break;
        }

        bzero(temp, sizeof(temp));
        counter++;
        
    }    
    return 0;
}