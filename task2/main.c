#include<stdio.h>
int needRev = 0;
 
unsigned int reverse(unsigned int num)
{
   return ((num & 0xff000000) >> 24) |
       ((num & 0x00ff0000) >> 8)  |
       ((num & 0x0000ff00) << 8)  | (num << 24);

}
 
int main(int argc, const char * argv[])
{
    FILE * in = fopen("input.bin","rt");
    unsigned int N;
    fread(&N,4,1,in);
    if (N > 10000) { needRev = 1; N = reverse(N); }
    unsigned int sum = 0;
    for(int i = 0; i < N; ++i)
    {
        unsigned int m;
        fread(&m,4,1,in);
        if (needRev) m = reverse(m);
        sum += m;
    }
 
    FILE * out = fopen("output.bin","wt");
 
    if (needRev) sum = reverse(sum);
 
    fwrite(&sum,4,1,out);
 
    fclose(in);
    fclose(out);
}
