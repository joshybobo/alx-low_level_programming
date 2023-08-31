#include <stdio.h>


unsigned int binary_to_unit(const char *b) {
	unsigned int result = 0;


	if (b==NULL) {
		return 0; 

	}

	while (*b) {
		char current = *b;
		if (current !='0' && current !='1') {
			return 0;
		}
		result = result * 2 + (current - '0');
		b++;
	}
	return result;
}

int main() {
const char *binary_str1 = "1101";
const char *binary_str2 = "10102";
const char *binary_str3 = NULL;



unsigned int result1 = binary_to_unit(binary_str1);
unsigned int result2 = binary_to_unit(binary_str2);
unsigned int result3 = binary_to_unit(binary_str3);



printf("Result 1: %u\n", result1);
printf("Result 2: %u\n", result2);
printf("Result 3: %u\n", result3);


return 0;




}
