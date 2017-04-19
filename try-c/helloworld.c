#include <stdio.h>
#include <stdlib.h>

int main()
{
    char username[10],password[10];
    printf("Username :");
    scanf("%s", username);
    printf("Password :");
    scanf("%s", password);
    if (username == "R00t" && password == "T00r")
    {
      printf("Success !");
      system("PAUSE");
    }
         else
    {
      printf("Not quite.\n");
      system("PAUSE");
    }
    return 0;
}
