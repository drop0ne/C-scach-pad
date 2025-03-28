#include <stdio.h>
#include <stdbool.h>

enum printLevel { line = 1, line_NL = 2, NL_line_NL = 3 };
enum yayNay { NO = 0, YES = 1 };
enum arraySize_e { ndigitArraySize = 10 };
enum powerSwitchFork { lessthanEqualN = 0, nGraterthanZero = 1 };

char* charArrayInverter(char* charArrayInput);
void consolePrintFunction(const char* output, const int printLevel);
int returnCharArrayLength(const char* dataInput);
char* takeConsoleInput(const char* consoleMessage, const int printLevel);
void countLines();
void countDigits();
void testPower();
int power(int x, int n, int switchFork);
void findLongestLine();
int get_line(char* s, int lim);    // Updated return type to int
void copy(char from[], char to[]);  // Added copy function

int main() {
    char* charArray = takeConsoleInput("Enter a string: ", line);
    consolePrintFunction(charArray, NL_line_NL);
    consolePrintFunction(charArrayInverter(charArray), line);
    return 0;
}

char* charArrayInverter(char* workingMemoryArray) {
    int length = returnCharArrayLength(workingMemoryArray);
    int i = 0, j = length - 1;

    while (i < j) {
        char temp = workingMemoryArray[i];
        workingMemoryArray[i] = workingMemoryArray[j];
        workingMemoryArray[j] = temp;
        i++;
        j--;
    }
    return workingMemoryArray;
}

void consolePrintFunction(const char* printDataString, const int printLevel) {
    switch (printLevel) {
    case line:
        printf("%s", printDataString);
        break;
    case line_NL:
        printf("%s\n", printDataString);
        break;
    case NL_line_NL:
        printf("\n%s\n", printDataString);
        break;
    default:
        printf("\n\nError -- function default\n\n");
        break;
    }
}

int returnCharArrayLength(const char* targetInput) {
    int i = 0;
    while (targetInput[i] != '\0')
        i++;
    return i;
}

char* takeConsoleInput(const char* consoleMessage, const int printLevel) {
    static char input[21];
    consolePrintFunction(consoleMessage, printLevel);
    scanf_s("%20s", input, (unsigned int)sizeof(input));
    return input;
}

void countLines() {
    int character = 0, newLine = 0, newWord = 0, newChar = 0, inword = NO;
    while ((character = getchar()) != EOF) {
        newChar++;
        if (character == '\n')
            newLine++;
        if (character == ' ' || character == '\n' || character == '\t')
            inword = NO;
        else if (inword == NO) {
            inword = YES;
            newWord++;
        }
    }
    printf("%d %d %d\n", newLine, newWord, newChar);
}

void countDigits() {
    int character = 0, nwhite = 0, nother = 0;
    int ndigit[ndigitArraySize] = { 0 };

    while ((character = getchar()) != EOF) {
        if (character >= '0' && character <= '9')
            ndigit[character - '0']++;
        else if (character == ' ' || character == '\n' || character == '\t')
            nwhite++;
        else
            nother++;
    }

    printf("digits =");
    for (int i = 0; i < ndigitArraySize; i++)
        printf(" %d", ndigit[i]);
    printf("\nwhite space = %d, other = %d\n", nwhite, nother);
}

void testPower() {
    for (int i = 0; i < 10; ++i) {
        printf("%d %d %d\n", i, power(2, i, lessthanEqualN), power(-3, i, lessthanEqualN));
    }
}

int power(int x, int n, int switchFork) {
    int power = 1;
    switch (switchFork) {
    case lessthanEqualN:
        for (int i = 1; i <= n; ++i)
            power *= x;
        return power;
    case nGraterthanZero:
        while (n > 0) {
            power *= x;
            n--;
        }
        return power;
    default:
        printf("Error -- function default\n");
        return -1;
    }
}

void findLongestLine() {
#define MAXLINE 1000  /* maximum input line size */
    int len, max = 0;
    char line[MAXLINE];
    char save[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(line, save);
        }
    }
    if (max > 0)  /* there was at least one line */
        printf("%s", save);
}

int get_line(char* s, int lim) {
    int character = { 0 }, i = {0};
    for (i = 0; i < lim - 1 && (character = getchar()) != EOF && character != '\n'; ++i)
        s[i] = character;
    if (character == '\n') {
        s[i] = character;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char from[], char to[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}