#include <stdio.h>
#include <stdbool.h>

enum printLevel
{
	line = 1, line_NL = 2, NL_line_NL = 3, 
};

char* charArrayInverter(char* charArrayInput);
void consolePrintFunction(const char* output, const int printLevel);
int returnCharArrayLength(const char* dataInput);
char* takeConsoleInput(const char* consoleMessage, const int printLevel);

int main() {
	char* charArray = takeConsoleInput("Enter a string: ", line);
	consolePrintFunction(charArray, NL_line_NL);
	consolePrintFunction(charArrayInverter(charArray), line);
	return 0;
}

char* charArrayInverter(char* workingMemory) {
	int length = returnCharArrayLength(workingMemory);
	int i = { 0 }, j = { length - 1 };
	
	while (i < j) {
		char temp = workingMemory[i];
		workingMemory[i] = workingMemory[j];
		workingMemory[j] = temp;
		i++, j--;
	}
	return workingMemory;
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