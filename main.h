#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

char *CopyStr(char *String, int start, int end);
int WordNumber(char *String, char delimi);
void FreeWord(char **Words, int WordCount);
char **StrTok(char *String, char delimi);
int PrintEnv(char **Environment);
int StringCmp(char *Sting1, char *String2);
char *ShearchStr(char *String, char c);
int StringLen(char *String);
void FreeResources(char **line, char ***tokens);
void Error(char *bin, char *cmd, char *message, int line);
void execute(char **tokens, char **environment, char *bin);
char *ReadLine(char *prompt);
char *StrRev(char *String);
int NumberLen(int numb);
ssize_t ABS(ssize_t numd);
char *_itoa(ssize_t integer, char *base);

#endif
