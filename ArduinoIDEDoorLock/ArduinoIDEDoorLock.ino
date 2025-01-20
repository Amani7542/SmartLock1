#include <Keypad.h>
#include <Servo.h>

// Matrix keypad settings
const byte ROW_NUM    = 4; // Number of rows
const byte COLUMN_NUM = 4; // Number of columns

// Key arrangement in the matrix keypad
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; // Row connections
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; // Column connections

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

Servo myservo;  // Define the servo
String correctPassword = "1234";  // Fixed password
String enteredPassword = "";  // Inputted password

void setup() {
  Serial.begin(9600); // Start serial communication
  myservo.attach(10); // Connect the servo to pin 10
  myservo.write(0);   // Move the servo to the initial position
  Serial.println("Enter the password:");
}

void loop() {
  char key = keypad.getKey(); // Get the pressed key

  if (key) { // If a key is pressed
    // Ignore non-numeric keys
    if (key != 'A' && key != 'B' && key != 'C' && key != 'D') {
      // If the password is being entered
      if (enteredPassword.length() < 4) {
        enteredPassword += key; // Add the entered digit to the password
        Serial.print("Entered password: ");
        Serial.println(enteredPassword);  // Display the entered password in serial
      }
  
      // If 4 digits have been entered
      if (enteredPassword.length() == 4) {
        // Check the password
        if (enteredPassword == correctPassword) {
          Serial.println("Correct password");
          myservo.write(90);  // Unlock (move the servo to 90 degrees)
          delay(5000);  // Wait for 5 seconds
          myservo.write(0);  // Return the servo to its position
          Serial.println("Lock closed");
          enteredPassword = ""; // Reset the entered password
          Serial.println("Enter the password:");
        } else {
          Serial.println("Incorrect password");
          enteredPassword = "";  // Reset the entered password
          Serial.println("Enter the password:");
        }
      }
    }
  }
}


