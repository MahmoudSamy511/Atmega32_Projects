# Project 1 
## Overview
A System ask user to enter a password to Login to dashboard has options to control
DC_Motor[CW or CCW] & Stepper Motor[with a specific angle].

- MCU1[MASTER] For Login and Take User Input.
- MCU2[SLAVE]  For Taking Actions And Rotating Motors.
- If user enter Wrong password the system will prompet to enter the password again.
- when the user login , LCD diplays the options `[1-DC Motor, 2-Stepper Motor, 3-EXIT]`.
- Case **DC Motor** :LCD diplays options for directions `[1-Rotate CW, 2-Rotate CCW]`.
- Case **Stepper Motor**:System will ask user to `Enter the angle` ,then choose direction `[1-Rotate CW, 2-Rotate CCW]`.
- Case **Stop** :All Motors will Stop.
## Schematic
  ![image](https://github.com/MahmoudSamy511/Atmega32_Projects/assets/95527475/7ced554c-6bb1-488a-834d-b7eb3cd8ab6e)

