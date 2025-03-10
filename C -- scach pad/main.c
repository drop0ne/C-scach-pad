#include <stdio.h>
#include <stdbool.h>

char* charArrayInverter(char* charArrayInput);
void consolePrintFunction(const char* output, bool precedingSpace);
int returnCharArrayLength(const char* dataInput);
char* takeConsoleInput(const char* consoleMessage);

int main() {
	char* charArray = takeConsoleInput("Enter a string: ");
	consolePrintFunction(charArray, true);
	consolePrintFunction(charArrayInverter(charArray), false);
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

void consolePrintFunction(const char* outputData, bool precedingSpace) {
	if (!true)
	{
	printf("%s\n", outputData);
	}
	else
	{
		printf("\n%s\n", outputData);
	}
}

int returnCharArrayLength(const char* targetInput) {
	int i = { 0 };
	while (targetInput[i] != '\0')
		i++;

	return i;
}

char* takeConsoleInput(const char* consoleMessage) {
	static char input[21];
	consolePrintFunction(consoleMessage, false);
    scanf_s("%20s", input, (unsigned int)(sizeof(input) / sizeof(input[0])));
	return input;
}