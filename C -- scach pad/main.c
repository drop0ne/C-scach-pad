#include <stdio.h>
#include <stdbool.h>

enum printLevel{line = 1, line_NL = 2, NL_line_NL = 3};
enum yayNay{NO = 0, YES = 1};

char* charArrayInverter(char* charArrayInput);
void consolePrintFunction(const char* output, const int printLevel);
int returnCharArrayLength(const char* dataInput);
char* takeConsoleInput(const char* consoleMessage, const int printLevel);
void countLines();

int main() {
	char* charArray = takeConsoleInput("Enter a string: ", line);
	consolePrintFunction(charArray, NL_line_NL);
	consolePrintFunction(charArrayInverter(charArray), line);
	return 0;
}

char* charArrayInverter(char* workingMemoryArray) {
	int length = returnCharArrayLength(workingMemoryArray); // stdio.h  strlen(workingMemoryArray);  it is recommended to use standard library algorithms.  I made my own function for practice.
	int i = { 0 }, j = { length - 1 };
	
	while (i < j) {
		char temp = workingMemoryArray[i];
		workingMemoryArray[i] = workingMemoryArray[j];
		workingMemoryArray[j] = temp;
		i++, j--;
	}
	return workingMemoryArray;
}

void consolePrintFunction(const char* printDataString, const int printLevel) {
	switch (printLevel)
	{
	case 1: { printf("%s", printDataString); break; }
	case 2: { printf("%s\n", printDataString); break; }
	case 3: { printf("\n%s\n", printDataString); break; }
	default: { printf("\n\nError -- function default\n\n"); break; }
	}
}

int returnCharArrayLength(const char* targetInput) {
	int i = { 0 };
	while (targetInput[i] != '\0')
		i++;

	return i;
}

char* takeConsoleInput(const char* consoleMessage, const int printLevel) {
	static char input[21];
	consolePrintFunction(consoleMessage, printLevel);
    scanf_s("%20s", input, (unsigned int)(sizeof(input) / sizeof(input[0])));
	return input;
}

void countLines() {
	/* count lines, words, chars in input */
	int c, nl, nw, nc, inword;
	nl = nw = nc = 0;
	inword = NO;

	while ((c = getchar()) != EOF)
	{
		++nc;
		if ((c == '\n')) { ++nl; }
		if (c == ' ' || c == '\n' || c == '\t') { inword = NO; }
		else if (inword == NO) { inword = YES; ++nw; }
	}
	printf("%d %d %d\n", nl, nw, nc);
}