#include "msp430g2553.h"

// When you  press buton, data which is 0x01 , sends it to slave msp via UART. As long as the data coming from master msp is equal to '2' ,the slave msp's led lights up.
// Author: Orhun Dabak
// function prototypes

void UARTInit(void);

void main(void)
 {
     WDTCTL = WDTPW + WDTHOLD;                              // watchdog timer OFF

     BCSCTL1 = CALBC1_1MHZ;                                 //DCO clock freq settings
     DCOCTL = CALDCO_1MHZ;

     UARTInit();                                            // UART settings are called.

     P1DIR = 0x41;                                          //P1.3 input, P1.0 & P1.6 output
     P1OUT = 0x00;                                          // Clearing output data.

 __bis_SR_register(GIE);                                    //interrupts are active

 while(1){
     if(!(P1IN&BIT3)){
      UCA0TXBUF = 0x01;
      __delay_cycles(100000);                               //2 seconds delay
      }
     else
        if(UCA0RXBUF==2){
         P1OUT =0x40;
         __delay_cycles(100000);}
 }
}

void UARTInit(void)                                          //UART Settings
{
    P1SEL |= (BIT1 + BIT2);                                  //P1.1 = RXD P1.2 = TXD
    P1SEL2 |= (BIT1 + BIT2);                                 //P1.1 = RXD P1.2 = TXD
    UCA0CTL1 = UCSSEL_2;                                     // clock source SMCLK

    UCA0BR0 = 52;                                            //UCOS16 = 1 Baudrate Settings
    UCA0BR1 = 0;
    UCA0MCTL = 0x11;                                         //Modulator settings
    UCA0CTL1 &= ~UCSWRST;                                    // UCSWRT register cleared for USCI operation .

    IE2 |= UCA0RXIE;                                         // RXD interrupt enabled

}
