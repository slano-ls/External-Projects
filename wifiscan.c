#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<termios.h>
#include<unistd.h>

int main(void){
    int r,wifi_off;
    char DEVICE_NAME[15];
    char SSID[15];
    char PASSWORD[15];
    char COMBO[100];

   //wifi_off=system("networksetup -setairportpower en0 off");

   printf("Enter Your Device Name (networksetup -listallhardwarerports) ");
   scanf("%s", DEVICE_NAME);
   getchar();

   printf("Enter Your SSID (WIFI NAME -listpreferredwirelessnetworks (DEVICE_NAME) ) ");
   scanf("%s", SSID);
   getchar();

   int i=0;
   char password_keys;
   char password[30];
   printf("Enter Your SSID Password> ");
       while((password_keys= getch())!=13){
           password[i] = password_keys;
           i++;
           printf("*");
       }
       pwd[i]='\0';
    printf("Your password is %s", password);
    const int trigger = 500; // ms
    const int numDots = 4;
    const char prompt[] = "Loading";

    int i2=0;
    while (i2 < 2) {
        // Return and clear with spaces, then return and print prompt.
        printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
        fflush(stdout);

        // Print numDots number of dots, one every trigger milliseconds.
        for (int i = 0; i < numDots; i++) {
            usleep(trigger * 1000);
            fputc('.', stdout);
            fflush(stdout);
        }
    i2++;
    }

char space = ' ';
printf("\n");
strncat(DEVICE_NAME, &space, 1);
strncat(SSID, &space, 1);
strcat(DEVICE_NAME, SSID);
printf("%s", DEVICE_NAME);

}
