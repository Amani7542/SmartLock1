# Door Lock System

## Project Description
The Servo Door Lock System is a secure and efficient solution for controlling door access using a servo motor and a keypad. It is powered by an Arduino Uno and can operate on a portable power source. The system allows users to unlock the door by entering a predefined 4-digit password. If the password is correct, the servo motor rotates to release the bolt lock mechanism, allowing access. The system automatically re-locks after 5 seconds.

---

## Features
- **Password-based Door Locking**: Users enter a 4-digit password to unlock the door.
- **Servo Motor Control**: Controls the bolt lock mechanism using a servo motor connected with steel wire.
- **Automatic Re-locking**: Re-locks the door after 5 seconds of unlocking.
- **Portable Power**: Operates using a 9v batteries for flexibility and portability.

---

## Requirements
### Hardware
- **Arduino Uno**: Microcontroller for managing the system.
- **Matrix Keypad (4x4)**: Input device for entering the password.
- **Servo Motor**: Controls the bolt lock mechanism.
- **Steel Wire**: Connects the servo motor to the bolt lock.
- **Power Bank**: Provides power to the system.
- **Connecting Wires and Breadboard**: For wiring and prototyping.
### Software
- **Arduino IDE**: For writing and uploading the code to the microcontroller.
---


## Code Overview
The system operates based on the following logic:
1. The user enters a 4-digit password via the keypad.
2. The system checks the entered password against the predefined password (`1234`).
3. If the password is correct:
   - The servo motor rotates 90° to unlock the bolt lock mechanism.
   - The servo motor returns to its original position after 5 seconds.
4. If the password is incorrect:
   - An error message is displayed on the Serial Monitor.
   - The door remains locked.

---

## How to Run the System
1. **Setup the hardware**:
   - Connect the keypad, servo motor, and Arduino as per the wiring diagram.
   - Attach the servo motor to the bolt lock mechanism using steel wire.
   - Power the system using a 9v batteries.
2. **Upload the code**:
   - Install the required libraries: `Keypad.h` and `Servo.h`.
   - Upload the Arduino sketch to the Arduino Uno using the Arduino IDE.
3. **Test the system**:
   - Enter the predefined password (`1234`) to unlock the door.
   - Observe the servo motor releasing the bolt lock.
   - Wait for the system to re-lock automatically after 5 seconds.



