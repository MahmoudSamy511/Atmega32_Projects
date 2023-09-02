# Project2 
## Teammates:
 - [Eman Abd Elhamid](https://github.com/Emanabdelhamid241)
 - [Omar Attia](https://github.com/omarattia23)
## Overview
Automated door system which uses a proximity sensor to detect if someone is coming toward the door with an option to manually disable the automatic action via LCD and a Keypad but this would be a privileged action which requires login with password, Also a user interface is required for monitoring the door state and the door is move via a servo motor.
- If user enter Wrong password the system will prompet to enter the password again.
- When the user login , LCD diplays the options `[1-Look Door, 2-Unlook Door]`.
- System prints all actions on LCD & Serial using [UART].
  
`NOTE:` We Use Two Potentiometer instead of IRs , because we use IRs As an analog sensors.
## Schematic
![Screenshot (15)](https://github.com/MahmoudSamy511/Atmega32_Projects/assets/95527475/5763e8e9-089a-4b5b-a902-fd2e6cf944e3)
## Hardware Video
https://github.com/MahmoudSamy511/Atmega32_Projects/assets/95527475/0bff56f3-0386-4508-beed-64717288f6f8

