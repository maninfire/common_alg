#include "stdio.h"
#include "string.h"

char *hash1="\x81\x01\x10\x69\x83\xf7\x6a\x82\x31\xd4\x11\xdf\x6a\x6b\xb0\x0b\xea\x64\xe0\x2e\x9d\xe5\x97\x0a\x4a\x7e\xde\xb0\x8a\xeb\x1a\x24";


unsigned char big_num[100] = {0};

unsigned char * _atoi( char* str){
     int len = 0;
     char tmp_0 = '0';
     char tmp_a = 'a';
     len = strlen(str);

int num_len = (len%2 + len/2);

     printf("len %d num_len %d \n", len, num_len);
     for( int i = 0; i < len; i++){
        if( tmp_a > str[i] && str[i]>=tmp_0){
            printf("i %d str i %c num pos %d num %02x  \n", i, str[i],  99-num_len+1+(i+1)/2, str[i]-tmp_0);
            if(i==0 || i%2 == 0){
                big_num[99-num_len+1+(i+1)/2] += (str[i]-tmp_0);
                printf("big num pos val %02x \n", big_num[99-num_len+1+(i+1)/2]);
            }else{
                big_num[99-num_len+1+(i+1)/2] += (str[i]-tmp_0)<<4;
                printf("big num pos val %02x \n", big_num[99-num_len+1+(i+1)/2]);

            }
        }else if(str[i]>=tmp_a){
            printf("i %d str i %c  num pos %d num %02x\n", i, str[i], 99-num_len+1+(i+1)/2, str[i]-tmp_a+0xa);
            if(i ==0 || i%2 == 0){

                 big_num[99-num_len+1+(i+1)/2] += (str[i]-tmp_a+0xa);
                printf("big num pos val %02x \n", big_num[99-num_len+1+(i+1)/2]);

            }
            else{
                big_num[99-num_len+1+(i+1)/2] += (str[i]-tmp_a+0xa)<<4;
                printf("big num pos val %02x \n", big_num[99-num_len+1+(i+1)/2]);
            }
        }
     }
}

int show_num(){
  int rc = 0;
  for(int i = 0; i < 100; i++){
     printf("%02x", big_num[i]);
  }
  printf("\n");
  return rc;
}

int main(){
    int rc = 0;
    char * str = "a345fde87eda8374628721fabceabd23645611273";
    printf(" str %s \n", str);
    _atoi(str);
    show_num();
    return rc;
}

