#include<msp430g2553.h>
// if the incoming data is equal to 0x01 , led will be  on , else it will be off.
// Author: Orhun Dabak

// function prototypes

void UARTInit(void);
void a(unsigned char c);
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;                     // Watchdog timer OFF
    BCSCTL1 = CALBC1_1MHZ;                        // DCO clock freq settings
    DCOCTL = CALDCO_1MHZ;

UARTInit();                                       // UART settings are called.

    P1DIR = 0x41;                                 // P1.3 input, P1.0 & P1.6 output
    P1OUT = 0x00;                                 // Clearing output data.

    __bis_SR_register(GIE);                       // Interrupts are active

while(1){

         if( UCA0RXBUF == 0x01)
         {
         P1OUT = 0x01;

         __delay_cycles(100000);
         }                                       // 2 seconds delay

         UCA0TXBUF = 2;
       }
}

void UARTInit(void)
  {                                              //UART SETTİNGS

    P1SEL |= (BIT1 + BIT2);                      // P1.1 = RXD P1.2 = TXD
    P1SEL2 |= (BIT1 + BIT2);                     // P1.1 = RXD P1.2 = TXD
    UCA0CTL1 = UCSSEL_2;                         // Clock source SMCLK

    UCA0BR0 = 52;                                // UCOS16 = 1 Baudrate settings
    UCA0BR1 = 0;

    UCA0MCTL = 0x11;                             // Modulator settings
    UCA0CTL1 &= ~UCSWRST;                        //  UCSWRT register cleared for USCI operation .
    IE2 |= UCA0RXIE;                             // RXD interrupt enabled
  }
}
