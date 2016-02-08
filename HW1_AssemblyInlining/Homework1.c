#include<string.h>

#include<stdio.h>

static inline char *asm_sub_str(char * dest, char *src, int s_idx, int edix){
int len=edix-s_idx;
__asm__ ("cld\n"
"rep\n"
"movsb\n"
"xor %%al,%%al\n"
"stosb\n"
:
:"S"(src + s_idx), "D"(dest), "c"(len)
);
return dest;
}
static inline char *sub_str(char *dest, char *src, int s_idx, int edix){
int len=edix-s_idx;
strncpy(dest,src+s_idx,len);
return dest;
}
int main(int argc,char **argv) {
char *c,*assembly,*d,*s=argv[1];
int e_idx=atoi(argv[3]);
int s_idx=atoi(argv[2]);
char temp[strlen(s)];
d=temp;
c=sub_str(d,s,s_idx,e_idx);
assembly=asm_sub_str(d,s,s_idx,e_idx);
if(strcmp(c,assembly)==0){
printf("\n Result: Same\n");
}
else{
printf("\n Result: Different\n");
}
  printf("\nC Output: %s",c);
  printf("\nAssembly Output:%s",assembly);

}
