#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int reverse32(int num) {

return ((num & 0xff000000) >> 24) |
       ((num & 0x00ff0000) >> 8)  |
       ((num & 0x0000ff00) << 8)  | (num << 24);

}


void parseFieldName(FILE* inpfile, FILE* outfile) {
	char* fieldName;	
	fieldName = malloc(100);
	char Ch = 0xFF;
	while (Ch != '\0') 
		{
			fread(&Ch,1, 1, inpfile);
			   
			strncat(fieldName,&Ch,1);
		}

	fprintf(outfile," \"%s\" : ",fieldName);
	free(fieldName);

}


int main() {

	FILE *inpfileptr;
	FILE *outfileptr;
	char *fieldName;
	



	inpfileptr = fopen("testinp.bin","rb");
	outfileptr = fopen("output.json","w");
	fwrite("{\n", sizeof('{'), 1, outfileptr);
	int32_t fileSize;
	fread(&fileSize, sizeof(int32_t), 1, inpfileptr);

	char T = 0xFF;
	while ( (int)T != 0 )
	{
		fread(&T, 1, 1, inpfileptr);
		
		if ((int)T == 2) continue;	

		if ((int)T == 1) 
		{
		        double doubleValue = 0.0;	
			parseFieldName(inpfileptr, outfileptr);	
			fread(&doubleValue, sizeof(double), 1, inpfileptr);
					
			

			//fwrite(&doubleValue, sizeof(double), 1, outfileptr);
			fprintf(outfileptr, " %.2lf", doubleValue);
		}
		
		if ((int)T == 16)
		{
		
			int32_t int32Value = 0;
			parseFieldName(inpfileptr, outfileptr);
			fread(&int32Value, sizeof(int32_t), 1, inpfileptr);
			fprintf(outfileptr, "%d", int32Value);
		}


		if ((int)T == 18)
		{
		
			int64_t int64Value = 0;
			parseFieldName(inpfileptr, outfileptr);
			fread(&int64Value, sizeof(int64_t), 1, inpfileptr);
			fprintf(outfileptr, "%lld", int64Value);
		}
			
		fprintf(outfileptr, "%c\n", ',');	
	
	}




fclose(inpfileptr);
fclose(outfileptr);

}
