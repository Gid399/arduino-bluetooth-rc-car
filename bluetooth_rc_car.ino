#include <SoftwareSerial.h> 
// Includes the SoftwareSerial library, which allows the Arduino
// to communicate with the HC-05 Bluetooth module using digital pins
// instead of the Arduino's hardware serial pins.

// HC-05 on pins 10 (RX), 11 (TX) 
SoftwareSerial BTSerial(10, 11); 
// Creates a Bluetooth serial connection.
// Pin 10 = Arduino RX (receives data from HC-05 TX)
// Pin 11 = Arduino TX (sends data to HC-05 RX)


// ================= MOTOR CONTROL PINS =================

// Enable pins control whether the motors are powered and can also
// be used with PWM to control motor speed.
int ENA = 8; 
int ENB = 3; 

// Motor 1 direction control pins
int motor1_forward = 7; 
int motor1_reverse = 6; 

// Motor 2 direction control pins
int motor2_forward = 5; 
int motor2_reverse = 4; 


// ================= BLUETOOTH PACKET =================

#define PACKET_SIZE 8
// Defines the expected size of each Bluetooth data packet.
// In this project, the Arduino waits until it receives 8 bytes.

byte packet[PACKET_SIZE];
// Creates an array that stores the received Bluetooth packet.

int index = 0;
// Keeps track of where the next received byte should be stored
// inside the packet array.


void setup() { 

  // Start communication between Arduino and the computer
  Serial.begin(9600); 

  // Start communication with the HC-05 Bluetooth module.
  BTSerial.begin(9600); 


  // ================= SET MOTOR PINS AS OUTPUTS =================

  pinMode(ENA, OUTPUT); 
  pinMode(ENB, OUTPUT); 

  pinMode(motor1_forward, OUTPUT); 
  pinMode(motor1_reverse, OUTPUT); 

  pinMode(motor2_forward, OUTPUT); 
  pinMode(motor2_reverse, OUTPUT); 


  // Set the motor speed using PWM.
  analogWrite(ENA, 150); 
  analogWrite(ENB, 150); 


  // Make sure both motors are stopped when the Arduino starts.
  stopMotor(); 


  // Display a message in the Serial Monitor to show
  // that the robot is ready to receive commands.
  Serial.println("Ready..."); 
} 


void loop() { 

  // Check whether data has been received from the HC-05.
  while (BTSerial.available()) { 

    // Read one byte of data from the Bluetooth module.
    byte incoming = BTSerial.read(); 

    // Store the received byte in the packet array.
    packet[index++] = incoming; 


    // Check whether a complete 8-byte packet has been received.
    if (index >= PACKET_SIZE) { 

      // Reset the index so that the next packet
      // can be stored from the beginning of the array.
      index = 0; 


      // ================= GET COMMAND =================

      // The control/command byte is located at position 7
      // of the packet, which corresponds to index 6
      byte command = packet[6]; 


      // Print the received command in hexadecimal format
      // to help with debugging.
      Serial.print("Command byte: "); 
      Serial.println(command, HEX); 


      // ================= COMMAND MAPPING =================

      // 0x01 represents the forward command.
      if (command == 0x01) { 
        Serial.println("Forward"); 
        forward(); 
      } 

      // 0x02 represents the backward command.
      else if (command == 0x02) { 
        Serial.println("Backward"); 
        backward(); 
      } 

      // 0x04 represents the left command.
      else if (command == 0x04) { 
        Serial.println("Left"); 
        left(); 
      } 

      // 0x08 represents the right command.
      else if (command == 0x08) { 
        Serial.println("Right"); 
        right(); 
      } 

      // 0x00 represents the stop command.
      else if (command == 0x00) { 
        Serial.println("Stop"); 
        stopMotor(); 
      } 
    } 
  } 
} 


// ==========================================================
//                    MOTOR FUNCTIONS
// ==========================================================


// Move both motors forward.
void forward() { 

  // Motor 1 rotates in the forward direction.
  digitalWrite(motor1_forward, HIGH); 
  digitalWrite(motor1_reverse, LOW); 

  // Motor 2 rotates in the forward direction.
  digitalWrite(motor2_forward, HIGH); 
  digitalWrite(motor2_reverse, LOW); 
} 


// Move both motors backward.
void backward() { 

  // Motor 1 rotates in the reverse direction.
  digitalWrite(motor1_forward, LOW); 
  digitalWrite(motor1_reverse, HIGH); 

  // Motor 2 rotates in the reverse direction.
  digitalWrite(motor2_forward, LOW); 
  digitalWrite(motor2_reverse, HIGH); 
} 


// Turn the robot to the left.
// One motor rotates backward while the other rotates forward.
void left(){ 

  // Motor 1 rotates backward.
  digitalWrite(motor1_forward, LOW); 
  digitalWrite(motor1_reverse, HIGH); 

  // Motor 2 rotates forward.
  digitalWrite(motor2_forward, HIGH); 
  digitalWrite(motor2_reverse, LOW); 
} 


// Turn the robot to the right.
// The motors rotate in opposite directions.
void right(){ 

  // Motor 1 rotates forward.
  digitalWrite(motor1_forward, HIGH); 
  digitalWrite(motor1_reverse, LOW); 

  // Motor 2 rotates backward.
  digitalWrite(motor2_forward, LOW); 
  digitalWrite(motor2_reverse, HIGH); 
} 


// Stop both motors.
void stopMotor() { 

  // Turn off both direction signals for Motor 1.
  digitalWrite(motor1_forward, LOW); 
  digitalWrite(motor1_reverse, LOW); 

  // Turn off both direction signals for Motor 2.
  digitalWrite(motor2_forward, LOW); 
  digitalWrite(motor2_reverse, LOW); 
}