#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <wiringPi.h>          
#include <stdio.h>
#include <wiringPiI2C.h> 

#include <string.h> /* for strncpy */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <lcd.h>               
 
//USE WIRINGPI PIN NUMBERS
#define LCD_RS  25               //Register select pin
#define LCD_E   24               //Enable Pin
#define LCD_D4  23               //Data pin 4
#define LCD_D5  22               //Data pin 5
#define LCD_D6  21               //Data pin 6
#define LCD_D7  14               //Data pin 7
 
void function(int lcd){
    int fd;
    struct ifreq ifr;

    fd = socket(AF_INET, SOCK_DGRAM, 0);

    /* I want to get an IPv4 IP address */
    ifr.ifr_addr.sa_family = AF_INET;

    /* I want IP address attached to "eth0" */
    strncpy(ifr.ifr_name, "wlan0", IFNAMSIZ-1);

    ioctl(fd, SIOCGIFADDR, &ifr);

    close(fd);

    /* display result */
    lcdPuts(lcd, inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
    printf("%s\n", inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
}

int main(){

    int lcd;               
    wiringPiSetup();        
    pinMode (0, OUTPUT);
    lcd = lcdInit (2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);
    int newData = 0;
    char temp[3];
    int fd = wiringPiI2CSetup(0x4a);          

    while (1){
        lcdClear(lcd);
        lcdPosition(lcd, 0, 0);
        function(lcd);
        lcdPosition(lcd, 0, 1);
        newData = wiringPiI2CRead(fd);
        sprintf(temp, "%d ", newData);
        printf("%s \n", temp);

        /* If temperature is below 20, turn on LED */        
        if (newData < 20){
            digitalWrite(0, HIGH);
        }	
        else{
            digitalWrite(0, LOW);
        }

        lcdPuts(lcd, temp);
        delay (2000);
    }

}
