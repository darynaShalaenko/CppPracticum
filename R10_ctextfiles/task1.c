#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* file;
	char buffer[128];
	file = fopen("data.txt", "r");
	fgets(buffer, 127, file);
	printf("%s", buffer);

	fclose(file);
	
	FILE* out;
	out = fopen("out.dat", "w");
	for (int i = 0; i < 128; i++)
	{
		fwrite(&(buffer[i]), sizeof(char), 1, out);
	}

	fclose(out);

	char text[128];
	FILE* inFile;
	int k;
	inFile = fopen("out.dat", "r");

	k = fread(text, sizeof(char), 127, inFile);

	FILE* result;
	out = fopen("result.txt", "w");

	for (int i = 0; i < 128; i++) {
		fputs(text[i], result);
	}
}