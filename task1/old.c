
#include <stdio.h>






// Не забудь изменить названия открываемых файлов!!!!


int reverse32(int num) {

 return ((num & 0xff000000) >> 24) |
       ((num & 0x00ff0000) >> 8)  |
       ((num & 0x0000ff00) << 8)  | (num << 24);
}



int main() {


FILE *file_ptr;
file_ptr = fopen("input1","rb");

int A = fread(&A, sizeof(int), 1, file_ptr);
int B = fread(&B, sizeof(int), 1, file_ptr);

fclose(file_ptr);


long long half_sum = (reverse32(A) + reverse32(B)) / 2;

printf("%d",half_sum);

file_ptr = fopen("output","wb");

fwrite(&half_sum, sizeof(int ), 1, file_ptr);
fclose(file_ptr);

}
