# Hack-Remote
A cool remote that lets you control RF signals with a CC1101 module. 
It has been specifically designed with customibilty in the code and ease of use in mind.
<img width="503" height="773" alt="image" src="https://github.com/user-attachments/assets/defdaa70-c80b-4401-92a7-f151211e9ef3" />


 ---
 How this works is when you plug it into a power source to turn it on, you open up to a menu of different Mhz frequencies. At this menu you can scroll through different Mhz frequencies and click the rotary encoder switch to send out you're desired signal. I also added a signal called 676767 (Really funny I know). When you choose this signal it sends out the same message on 50 randomly chosen Mhz frequencies on at a time in quick succession to "test" RF signal receivers. I have made the code simple and easy to understand so that someone can go in and add there own desired Mhz frequencies and messages.
 
 ---
 I decided to make this, as I am constantly surrounded by RF receivers and transmitors. So why not build a simple device that is kinda like a flipper zero, and can manipulate/work with these RF signals. (Also flipper zeros are super expensive so if you want to make one but for like only RF here you go!)
 
 ---
 # Build Instructions:
Assembling the Hack Remote is very simple, all you need is a soldering iron, solder, 3d printed parts, PCB board, and all the parts in the BOM. First get the PCB board and place the compoments all facing up, and solder them onto their designated spots one by one. Next you want to flash the code onto the board, you do this by opening arduino IDE opening the code selecting the Xiao MG24, and installing the Adafruit BusIO, AdafruitGFX Library, AdafruitSSD1306, RotaryEncoder, and SmartRC-CC1101-Driver-Lib Libraries. Then connnect you're board to the computer, and click upload on ArduinoIDE. After this get the Hack Remote bottom 3d printed part and put the assembled board onto it so that the Xiao usb-c end can be seen sticking out the power hole. Then screw the board on using 2 screws to make sure it stays in place. Finally put the Hack Remote Top on top of the bottom piece and use the rest of the screws to screw it in place. After all this work you should finally have a assembled Hack Remote ready to be used.

 ---
 # CAD MODEL:
 <img width="1920" height="958" alt="image" src="https://github.com/user-attachments/assets/c2b629c9-ceea-41a5-b80b-16754942d8d3" />
<img width="1920" height="959" alt="image" src="https://github.com/user-attachments/assets/50d776ad-ff83-4233-83b4-31bdf4035849" />
These models were fully designed, and assembled in onshape.
https://cad.onshape.com/documents/6f64acb43278fcf02d95f203/w/43ea7b20cd107b410569e89b/e/a30772a52d9b3aa84b86adaa?renderMode=0&uiState=69fd384367af19aa08245193

---
# PCB:
<img width="1175" height="792" alt="image" src="https://github.com/user-attachments/assets/5f588cbd-cf4f-4d20-b22e-e1d4462f9f3b" />
<img width="1334" height="767" alt="image" src="https://github.com/user-attachments/assets/691f7f50-19c8-405b-973b-0ec1a3f54eb6" />
<img width="1467" height="866" alt="image" src="https://github.com/user-attachments/assets/44254067-51f2-46ef-963b-9dbe1c93073f" />
These were fully made on KiCad

---
