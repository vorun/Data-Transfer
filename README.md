# Data-Transfer
Communication Between 2 MSP430 Microcontroller Via Bluetooth

-When you press the button at the master msp430, data which is 0x11 gets sent to slave 
msp430 via bluetooth using uart. As long as the data coming from the master msp430 is equal to '2'
slave msp430's led lights up.

-In order to transmit data with bluetooth module you need to configure your bluetooth modules to 
master/slave.

-Slave circuit can be configured to control a device with the master circuit or with any device with bluetooth 
capability.  

-Pin connections and circiut designs can be found at the "MSP430 Bluetooth Comm PCB" folder.

![MSP430top](https://user-images.githubusercontent.com/79105578/221882651-8fc972b1-b527-457a-b709-85b837f102fd.PNG)
![msp430 bottom](https://user-images.githubusercontent.com/79105578/221882936-3a035110-7096-4951-a052-af3485ee1652.PNG)


