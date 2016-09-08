#include <stdio.h>
#include <time.h>


#ifndef LOG_LEVEL
#error Please define a LOG_LEVEL
#endif


#define SYM_TO_STR(sym) STRINGIFY(sym)
#define STRINGIFY(s) #s


#define LOG_HELPER(level,message)	do { \
  time_t time_inst = time(NULL);												\
  struct tm * local = localtime(&time_inst);											\
  printf("%d:%d:%d %s " __FILE__ ":" SYM_TO_STR(__LINE__) " %s", local->tm_hour, local->tm_min, local->tm_sec, level, message);	\
} while(0)


#if LOG_LEVEL>=1
#define LOG_ERROR(message)	do { 	\
  LOG_HELPER("ERROR",message);		\
} while(0)
#else
#define LOG_ERROR(message)
#endif

#if LOG_LEVEL>=2
#define LOG_TRACE(message)	do { 	\
  LOG_HELPER("TRACE",message);		\
} while(0)
#else
#define LOG_TRACE(message)
#endif

#if LOG_LEVEL>=3
#define LOG_DEBUG(message)	do { 	\
  LOG_HELPER("DEBUG",message);		\
} while(0)
#else
#define LOG_DEBUG(message)
#endif

int main() {
  
  LOG_ERROR("Something went wrong...\n");
  LOG_TRACE("Something went wrong...\n");
  LOG_DEBUG("Something went wrong...\n");
  
  return 0;
  
}
