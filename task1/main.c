#include <stdio.h>
#define VALUE_BITS 32
#include <stdint.h>
#include <math.h>


/*Перевод из little в big endian (нашел где-то на stackoverflow) */
int reverse32(int num) {

  return ((num & 0xff000000) >> 24) |
       ((num & 0x00ff0000) >> 8)  |
       ((num & 0x0000ff00) << 8)  | (num << 24);

}



int main() {

FILE *f;
int32_t A,B;
long long int halfsum ;

f = fopen("input4","rb");
fread(&A, sizeof(int),1,f);
fread(&B, sizeof(int),1,f);
fclose(f);


if (A == B)
	halfsum = A;
else
	halfsum = floor((A + B) / 2.0);


printf("%d %d\n",A,B);
printf("%lld", halfsum);


f = fopen("output","wb");
fwrite(&halfsum, sizeof(int),1,f);
fclose(f);



}
