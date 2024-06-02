#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkForDigit(char *password);



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

    if (passwordLength < 8)
    {
      printf("The password needs to have at least 8 characters.\n");
    }
    else if (checkForDigit(password) == 0)
    {
      printf("The password needs to contain at least one digit.\n");
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