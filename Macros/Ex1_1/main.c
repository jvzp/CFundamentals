#include <stdio.h>

#define	TO_STRING()	STR(__LINE__)
#define STR(s)	STRINGIFY(s)
#define	STRINGIFY(s)	#s

int main() {
  
  printf("%s\n", TO_STRING());
  return 0;
  
}