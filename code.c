#include <stdio.h>
//#include <wiringPi.h>

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.

#define LED     0  // GPIO 17
#define LED1    1  // GPIO 18
#define LED3    3  // GPIO 22

int main (void)
{
  printf ("Raspberry Pi - Gertboard Blink\n") ;

  int pin = 0;
  int pin1 = 0;
  wiringPiSetup () ;

  pinMode (LED, INPUT) ;
  pinMode (LED1, INPUT) ;
  pinMode (LED3, OUTPUT) ;

  for (;;)
  {
     //  delay (500) ;               // mS

     pin =   digitalRead (LED ) ;     // Off
     pin1 =   digitalRead (LED1 ) ;     // Off

     printf ("Pin - Obstacle OUTPUT: %d  \n", pin) ;
     printf ("Pin - Alchohol OUTPUT: %d  \n", pin1) ;

     if(pin == 1 && pin1 == 0)
     {
        digitalWrite (LED3, 1) ;     // On
        printf ("\n\n <===== SWITCHING ON MOTORCYCLE ====>\n\n") ;
        delay (1000) ;               // mS
     }
     else
     {
        digitalWrite (LED3, 0) ;     // Off
        printf ("\n\n <===== WARNING:::: SWITCHING OFF MOTORCYCLE ====>\n\n") ;
        delay (1500) ;               // mS
     }
     delay (500) ;
  }
  return 0 ;
}
