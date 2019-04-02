#include "q3.h"
char base64_table[64] =
{ 'A','B','C','D','E','F','G','H','I','J','K','L','M',
	'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	'a','b','c','d','e','f','g','h','i','j','k','l','m',
	'n','o','p','q','r','s','t','u','v','w','x','y','z',
	'0','1','2','3','4','5','6','7','8','9','+','/' };
/*
you take a 24bit value, parse it into 4 6bit values, and then decode em using table
assume you have a 32bit variable (0x12345678), and just remove the first byte
*/
size_t b64length(size_t  len) {
	printf("%d", len / 6);
	return (len / 6);
}
void b64_encode(void *src, size_t len, void *dst) {
	//returns an unisgned int len
	char b64_eq = 0;
	for (size_t i = 0; i <= len; i++) {
		for (char j = 0; j < 256; j++) {
			printf("%c", ((int)src >> (6 * i)));
			if ((unsigned char)base64_table[j] == (unsigned char)((char)src >> (6 * i))) {
				b64_eq = base64_table[j];
				printf("\nVALUE IS %c\n", b64_eq);
				break;
			}
		}
		(unsigned int)dst += (unsigned int)(b64_eq << (6 * i));
	}
	printf("encoding string in base64\n");
}