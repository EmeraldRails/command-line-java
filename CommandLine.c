#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CommandLine.h"
#define SIZE 1024
// change above if needed
JNIEXPORT void JNICALL Java_CommandLine_execCommand0(JNIEnv *env, jobject obj, jstring command) {
  FILE *f;
  char line[SIZE];
  const char *cString = (*env)->GetStringUTFChars(env, command, 0);
  printf("Executing command %s\n", cString);
  f = popen(cString, "r");
  if(f == NULL) {
    printf("Failed to execute command %s.", cString);
    exit(1);
  }
  while(fgets(line, sizeof(line), f) != NULL) {
    printf("%s", line);
  }
  pclose(f);
}