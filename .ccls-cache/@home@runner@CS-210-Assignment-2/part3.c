#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkForDigit(char *password);
int encrypt(char *filename, char *password, char *newFileName);


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
    if (passwordLength < 8)
    {
      printf("The password needs to have at least 8 characters.\n");
    }
    else if (checkForDigit(password) == 0)
    {
      printf("The password needs to contain at least one digit.\n");
    }
    else
    {
        encrypt(filename, password, newFileName);
    }
  }
}



int checkForDigit(char *password)
{
  int i = 0;
  for (i = 0; i < strlen(password); i++)
  {
    if (password[i] >= '0' && password[i] <= '9')
    {
      return 1;
    }
  }
  return 0;
}



int encrypt(char *filename, char *password, char *newFileName)
{
  int blockSize = strlen(password);
  FILE *file, *newFile;
  char block[blockSize];
  int i, numBytes;

  file = fopen(filename, "rb");
  newFile = fopen(newFileName, "wb");

  do 
  {
    numBytes = fread(block, 1, blockSize, file);
    for (i=0; i<numBytes; i++)
    {
      block[i] = block[i] ^ password[i];
    }
    fwrite(block, 1, numBytes, newFile);
  }
  while (numBytes == blockSize);
  fclose(newFile);
  fclose(file);
}