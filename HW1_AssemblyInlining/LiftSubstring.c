#include<stdio.h>
#include<string.h>

static inline char *sub_str(char *dest, char *src, int s_idx, int edix){

  char a[strlen(src)];
  strncpy(dest,src+s_idx,edix-s_idx);
  return dest;
}

static inline char *asm_sub_str(char * dest, char *src, int s_idx, int edix){

  __asm__ ("cld\n"
           "rep\n"
           "movsb\n"
           "xor %%al,%%al\n"
           "stosb\n"
           :
           :"S"(src + s_idx), "D"(dest), "c"(edix-s_idx)
           );
  return dest;
}

int main(int argc,char **argv) {
  char *d;
  char *d1;
  char *d2;
  char *s=argv[1];
  int len=strlen(s);
  int s_idx=atoi(argv[2]);
  int e_idx=atoi(argv[3]);
  char a[len];
  d=a;
  d1=sub_str(d,s,s_idx,e_idx);
  printf("\nd1:%s",d1);
  d2=asm_sub_str(d,s,s_idx,e_idx);
  printf("\nd2:%s",d2);
  if(strcmp(d1,d2)==0){
    printf("\nBoth are same\n");
  }
  else{
    printf("\nBoth are different\n");
  }
}
