#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


//Declarations
unsigned char* my_strstr(const unsigned char* haystack, const unsigned char* needle);

void fillStopTable(size_t* stopTable, const unsigned char* needle, size_t nlen);

int itsatesttime();


//Main
int main() {

	unsigned char* haystack = malloc(2000*sizeof(char));
	unsigned char* needle = malloc(100*sizeof(char));

	if (haystack != NULL && needle != NULL) {

		if (gets_s(haystack, 2000*sizeof(char)) == NULL || 
			gets_s(needle, 100*sizeof(char)) == NULL) return 1;

		unsigned char* enteranceInd = my_strstr(haystack, needle);

		if (enteranceInd != NULL) {
			printf("%c\n", *enteranceInd);
			printf("%ti\n", enteranceInd - haystack);
		}
		else printf("No enterance\n");
	}

	// printf("\n%i\n", itsatesttime());
	

	return 0;
}


//Definitions
unsigned char* my_strstr(const unsigned char* haystack, const unsigned char* needle) {

	if (haystack == NULL || needle == NULL) return NULL;

	size_t hlen = strlen(haystack);
	size_t nlen = strlen(needle);

	if (nlen > hlen || nlen == 0) return NULL;

	size_t stopTable[UCHAR_MAX+1];
	fillStopTable(stopTable, needle, nlen);

	for (size_t hInd=0; hInd <= hlen-nlen; ) {

		size_t nInd;

		for (nInd = nlen - 1; needle[nInd] == haystack[hInd+nInd]; nInd--)
			if (nInd == 0) {
				return (haystack + hInd);
			}

		hInd += nInd - stopTable[haystack[nInd+hInd]] + 1;
	}

	return NULL;
}

void fillStopTable(size_t* stopTable, const unsigned char* needle, size_t nlen) {

	for (size_t i=0; i<UCHAR_MAX+1; i++) stopTable[i] = 0;

	for (size_t i=0; i < nlen; i++) stopTable[needle[i]] = i+1;
}

int itsatesttime() {

	int result = 0;

	const unsigned char* str1 = "\"Night Rider\" is a song written by Doc Pomus and Mort Shuman and originally recorded by Elvis Presley for his album Pot Luck with Elvis.";
	const unsigned char* str2 = "The 2011 NCAA Division I baseball season, play of college baseball in the United States organized by the National Collegiate Athletic Association(NCAA) at the Division I level, began on February 18, 2011.";
	const unsigned char* str3 = "FoxyTunes was a browser extension allowing control of media players from the web browser window. The company that developed FoxyTunes was bought by Yahoo! in 2008, and FoxyTunes was closed in 2013.";

	if ((my_strstr(str1, (const unsigned char*) "Pomus") == str1+39) &&
		(my_strstr(str1, (const unsigned char*) "ded b") == str1+81) &&
		(my_strstr(str2, (const unsigned char*) "2011") == str2+4) &&
		(my_strstr(str2, (const unsigned char*) "(NCAA)") == str2+145) &&
		(my_strstr(str3, (const unsigned char*) "!") == str3+153) &&
		(my_strstr(str3, (const unsigned char*) ".") == str3+95)) result = 1;

	return result;
}