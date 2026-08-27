# Arduino Bluetooth RC Car

## Overview

This project is an Arduino-based Bluetooth-controlled RC car. The car can be controlled wirelessly using a Bluetooth-enabled device. Commands sent from the controlling device are received by an HC-05 Bluetooth module and processed by the Arduino to control the movement of two DC motors.

The project was built to gain practical experience in microcontroller programming, wireless communication, motor control, and integrating electronic and mechanical components into a working robotic system.

## Features

* Wireless control using Bluetooth
* Forward and reverse movement
* Left and right turning
* Motor control using an L293D motor driver
* Four DC motors for movement
* Arduino-based control system

## Components Used

* Arduino
* HC-05 Bluetooth module
* L293D motor driver
* 4 × DC motors
* Robot chassis
* Wheels
* Battery/power supply
* Jumper wires

## How It Works

The robot uses an HC-05 Bluetooth module to receive movement commands from a Bluetooth-enabled device.

The overall communication process is:

**Phone → HC-05 → Arduino → Motor Driver → DC Motors**

The HC-05 communicates with the Arduino using serial communication. The Arduino receives the commands and determines which motors should rotate and in which direction.

The Arduino then sends control signals to the L293D motor driver. The motor driver provides the necessary control for the two DC motors, allowing the robot to move forward, reverse, turn left, turn right, or stop.

## Bluetooth Communication

The HC-05 is connected to the Arduino using `SoftwareSerial`. In the program, Arduino pins 10 and 11 are used for Bluetooth communication.

The Bluetooth module acts as the wireless communication interface between the controlling device and the Arduino. It does not directly control the motors. Instead, it passes the commands to the Arduino, which interprets them and controls the motor driver.

## Motor Control

The L293D motor driver is used to control the direction and movement of the two DC motors.

The Arduino uses separate control pins for each motor:

* Motor 1 forward: Pin 7
* Motor 1 reverse: Pin 6
* Motor 2 forward: Pin 5
* Motor 2 reverse: Pin 4
* Motor 1 enable: Pin 8
* Motor 2 enable: Pin 3

The Arduino changes the state of these pins according to the Bluetooth command received.

## Project Demonstration

A photograph of the completed RC car is included in this repository.

A demonstration video can also be provided to show the robot operating under Bluetooth control.

## What I Learned

Through this project, I gained practical experience in:

* Arduino programming using C/C++
* Serial communication
* Bluetooth communication using the HC-05
* Controlling DC motors
* Using a motor driver
* Interfacing different electronic components
* Debugging hardware and software problems
* Integrating mechanical, electrical, and software components into a working robotic system

## Challenges

One of the main challenges of the project was integrating the different components and ensuring that the Bluetooth commands were correctly translated into motor movements.

Testing and troubleshooting were required to identify wiring and programming issues and to ensure that the motors responded correctly to the commands received from the Bluetooth module.

## Future Improvements

Possible improvements to the project include:

* Adding ultrasonic sensors for obstacle detection
* Implementing speed control using PWM
* Improving the chassis design
* Using an esp32 to test the in-built bluetooth and wifi

## Conclusion

This project provided practical experience in developing a small robotic system by combining programming, wireless communication, electronics, and mechanical components. It also provided a foundation for developing more advanced robotics projects in the future.
