#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>

#define ERROR -100
#define BUFFER_SIZE 100*10
#define NO_KEYWORD_FOUND -1
#define KEYWORD_ONE_FOUND_FIRST 1
#define KEYWORD_TWO_FOUND_FIRST 2

typedef struct fileparser
{
    FILE * file_pointer;
    char* buffer;
}FileParser;

FileParser* createParser(char* file_name);
int searchFileForKeywords(FileParser* parser);
void cleanupParser(FileParser* parser);

int parseFile(char* file_name)
{
    int return_value;
    FileParser * parser = createParser(file_name);
    return_value = searchFileForKeywords(parser);
    cleanupParser(parser);
    return return_value;
}

int searchFileForKeywords(FileParser* parser)
{
    if(parser == NULL)
    {
        return ERROR;
    }
    while(fgets(parser->buffer, BUFFER_SIZE, parser->file_pointer)!=NULL)
    {
        if(strcmp("KEYWORD_ONE\n", parser->buffer)==0)
        {
            return KEYWORD_ONE_FOUND_FIRST;
        }
        if(strcmp("KEYWORD_TWO\n", parser->buffer)==0)
        {
            return KEYWORD_TWO_FOUND_FIRST;
        }
    }
    return NO_KEYWORD_FOUND;
}

FileParser* createParser(char* file_name)
{
    assert(file_name!=NULL && "Недопустимое имя файла");
    FileParser* parser = malloc(sizeof(FileParser));
    if(parser)
    {
        parser->file_pointer=fopen(file_name, "r");
        parser->buffer = malloc(BUFFER_SIZE);
        if(!parser->file_pointer || !parser->buffer)
        {
            cleanupParser(parser);
            return NULL;
        }
    }
    return parser;
}

void cleanupParser(FileParser* parser)
{
    if(parser)
    {
        if(parser->buffer)
        {
            free(parser->buffer);
        }
        if(parser->file_pointer)
        {
            fclose(parser->file_pointer);
        }
        free(parser);
    }
}

int main(int argc, char* argv[])
{
    if(argv[1]!=NULL) printf("%d\n", parseFile(argv[1]));
    else printf("Нужно имя файла\n");

    return 0;
}