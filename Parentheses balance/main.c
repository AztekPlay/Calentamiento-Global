#include <stdio.h>


//Declarations
int checkBrackets(char* str);

int charIndex(char ch);


//Main
int main() {

	char str[256];
	if (scanf("%s", str) != 1) {

		return 1;
	}

	printf("%i\n", checkBrackets(str));

	return 0;
}


//Definitions
int checkBrackets(char* str) {

	int result = 1;

	int i = 0;
	int chInd;
	int lastOpen = 0;

	while (1) {
		chInd = charIndex(str[i]);

		if (chInd > 0) {
			if (chInd == 10) {
				for (lastOpen; lastOpen >= 0; lastOpen--) 
					if (charIndex(str[lastOpen]) != 0) result = 0;

				break;
			}
			else 
				lastOpen = i;
		}
		else if (chInd < 0) {
			str[i] = 'a';
			
			int isCorrect = 1;

			for (lastOpen; lastOpen >= 0; lastOpen--) {
				if (charIndex(str[lastOpen]) == -chInd) {
					str[lastOpen] = 'a';
					lastOpen--;
					break;
				}
				else if ((charIndex(str[lastOpen]) != 0) || (lastOpen == 0)) {
					isCorrect = 0;
					break;
				}
			}

			if (!isCorrect) {
				result = 0;
				break;
			}
		}

		i++;
	}

	return result;
}

int charIndex(char ch) {

	int result = 0;

	switch (ch) {
	case '(':
		result = 1;
		break;

	case '[':
		result = 2;
		break;

	case '{':
		result = 3;
		break;

	case '<':
		result = 4;
		break;

	case ')':
		result = -1;
		break;

	case ']':
		result = -2;
		break;

	case '}':
		result = -3;
		break;

	case '>':
		result = -4;
		break;

	case '\0':
		result = 10;
		break;
	}

	return result;
}