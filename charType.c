
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>

#define MAX_STRING_LENGTH 100

int main(int argc, char* argv[])
{
	char* alpha;
	char* digits;
	char* punct;
	char* white;
	FILE* in;
	FILE* out;
	char* line;
	int lineCount = 0;
	char pAlpha[] = "characters";
	char pDigits[] = "characters";
	char pPunct[] = "characters";
	char pWhite[] = "characters";
	
	
	
	
	
	if(argc != 3)
	{
		printf("Usage %s <input file> <output file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	in = fopen(argv[1], "r");
	if(in == NULL)
	{
		printf("Unable to read from file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	out = fopen(argv[2], "w");
	if(out == NULL)
	{
		printf("Unable to write to file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	line = calloc(MAX_STRING_LENGTH + 1, sizeof(char));
	alpha = calloc(MAX_STRING_LENGTH + 1, sizeof(char));
	digits = calloc(MAX_STRING_LENGTH + 1, sizeof(char));
	punct= calloc(MAX_STRING_LENGTH + 1, sizeof(char));
	white = calloc(MAX_STRING_LENGTH + 1, sizeof(char));
	assert( line != NULL && alpha != NULL && digits != NULL && punct != NULL && white != NULL);
	

	
	
	
	while(fgets(line, MAX_STRING_LENGTH, in) != NULL)
	{
		lineCount++;
		extract_chars(line, alpha, digits, punct, white);
		if((int) strlen(alpha) == 1)
		{
			strcpy(pAlpha,"character");
		}
		if((int) strlen(digits) == 1)
		{
			strcpy(pDigits,"character");
		}
		if((int) strlen(punct) == 1)
		{
			strcpy(pPunct,"character");
		} 
		if((int) strlen(white) == 1)
		{
			strcpy(pWhite,"character");
		} 
		fprintf(out,"line %d contains:\r\n%d alphabetic %s: %s\r\n%d numeric %s: %s\r\n%d punctuation %s: %s\r\n%d whitespace %s: %s\r\n\r\n", lineCount, strlen(alpha), pAlpha, alpha, strlen(digits), pDigits, digits, strlen(punct), pPunct, punct, strlen(white), pWhite, white);
	}
	free(line);
	free(alpha);
	free(digits);
	free(punct);
	free(white);
	fclose(in);
	fclose(out);
	return EXIT_SUCCESS;
	
	
}
void extract_chars(char* s, char* a, char* d, char* p, char* w)
{
	int sNum = 0, aNum=0, dNum=0, pNum=0, wNum=0;
	while(s[sNum]!= '\0' && sNum < MAX_STRING_LENGTH)
	{
		if(isalpha((int) s[sNum]))
		{
			a[aNum++] = s[sNum];
			sNum++;
		}
		else if((int) isdigit(s[sNum]))
		{
			d[dNum++] = s[sNum];
			sNum++;	
		}
		else if((int) ispunct(s[sNum]))
		{
			p[pNum++] = s[sNum];
			sNum++;	
		}
		else if((int) isspace(s[sNum]))
		{
			w[wNum++] = s[sNum];
			sNum++;
		}
	}
	a[aNum] = '\0';
	d[dNum] = '\0';
	p[pNum] = '\0';
	w[wNum] = '\0';
		
}
	
		