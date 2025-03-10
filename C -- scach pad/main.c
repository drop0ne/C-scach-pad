#include <stdio.h>

char* charArrayInverter(char* charArrayInput);
void consolePrintFunction(const char* output);
int returnCharArrayLength(const char* dataInput);
char* takeConsoleInput(const char* consoleMessage);

int main() {
	char* charArray = takeConsoleInput("Enter a string: ");
	consolePrintFunction(charArray);
	consolePrintFunction(charArrayInverter(charArray));
	return 0;
}

char* charArrayInverter(char* workingMemory) {
	int length = returnCharArrayLength(workingMemory);
	int i = { 0 }, j = { length - 1 };
	
	while (i < j) {
		char temp = workingMemory[i];
		workingMemory[j] = temp;
		i++, j--;
	}
	return workingMemory;
}

void consolePrintFunction(const char* outputData) {
	printf("%s\n", outputData);
}

int returnCharArrayLength(const char* targetInput) {
	int i = { 0 };
	while (targetInput[i] != '\0')
		i++;

	return i;
}

char* takeConsoleInput(const char* consoleMessage) {
	static char input[20];
	consolePrintFunction(consoleMessage);
	scanf_s("%19s", input, (unsigned)sizeof(input) / sizeof(input[0]));
	return input;
}