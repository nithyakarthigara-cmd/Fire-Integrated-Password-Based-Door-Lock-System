# Fire-Integrated-Password-Based-Door-Lock-System
Project Overview

This project implements a secure door locking system that operates on a password-based mechanism while also providing an integrated fire emergency response. The system is designed using an Arduino Uno as the controller and incorporates a 4x4 keypad for user input, a servo motor for the physical locking and unlocking of the door, an I2C-based LCD to provide visual feedback, a buzzer for alert notifications, and a fire sensor to detect emergencies.

Under normal operation, the user is required to enter a pre-set password using the keypad. The system verifies the input, and if the password is correct, the servo motor rotates to unlock the door. The LCD provides feedback during this process by masking the entered characters and displaying messages such as "Access Granted" or "Access Denied." The door remains unlocked for a short duration before automatically locking again to maintain security.

In the event of a fire, the system automatically prioritizes safety over security. When the fire sensor detects a flame or abnormal heat, the buzzer is activated to alert nearby occupants, the LCD displays a "FIRE EMERGENCY" message, and the servo motor immediately unlocks the door to facilitate safe evacuation. After a specified delay, the door relocks automatically. This integration ensures that the system is not only a secure access control mechanism but also a safety system that responds effectively during emergencies.
Hardware and Circuit Overview

The core components of this system include an Arduino Uno, a 4x4 matrix keypad for password entry, an IR flame sensor for fire detection, an I2C LCD for system messages, a servo motor for the locking mechanism, and a buzzer for audio alerts. The servo is responsible for physically locking and unlocking the door, the LCD guides the user with prompts and emergency notifications, and the buzzer acts as an audible alarm during fire conditions. The circuit is straightforward to assemble, with the fire sensor and keypad providing input signals to the Arduino, and the servo, LCD, and buzzer serving as output components.
Software Functionality

The Arduino code initializes all peripherals and then continuously monitors for two conditions: user password entry and fire detection. For password entry, the code accepts user input from the keypad, masks the input on the LCD, and compares it with the stored password. A correct password triggers the unlocking sequence and a timed relock. For fire detection, the system continuously reads the fire sensor, and upon detecting a flame, it overrides any other state, sounds the buzzer, displays an emergency message, and unlocks the door automatically.
Usage

To operate the system, the user powers on the circuit and is prompted to enter the password via the keypad. Pressing the confirmation key (such as #) verifies the input. A correct password results in the door unlocking and then relocking after a delay, while an incorrect password will display a denial message without unlocking the door. During a fire emergency, no user input is needed; the system automatically sounds the alarm and unlocks the door for safety.
