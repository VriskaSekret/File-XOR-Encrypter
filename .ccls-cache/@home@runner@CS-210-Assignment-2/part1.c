#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
  if (argc != 3) 
  {
    printf("Usage: %s [file name] [password]\n", argv[0]);
  }
  else
  {
    char filename[15];
    strcpy(filename, argv[1]);
    char *password = argv[2];
    int passwordLength = strlen(password);
    char newFileName[20] = "new-";
    strcat(newFileName, filename);
    printf("newFileName = %s\npassword length = %d\n", newFileName, passwordLength);
  }
}