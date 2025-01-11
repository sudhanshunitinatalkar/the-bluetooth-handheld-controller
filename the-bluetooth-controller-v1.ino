#include <Arduino.h>
#include <BleGamepad.h>

BleGamepad bleGamepad;

#define LEFT_JOYSTICK_VRX 34
#define LEFT_JOYSTICK_VRY 35

#define RIGHT_JOYSTICK_VRX 39
#define RIGHT_JOYSTICK_VRY 36

#define BUTTON_1_PIN 32
#define BUTTON_2_PIN 26
#define BUTTON_3_PIN 27
#define BUTTON_4_PIN 14
#define BUTTON_5_PIN 4
#define BUTTON_6_PIN 33 
#define BUTTON_7_PIN 16
#define BUTTON_8_PIN 25
#define LEFT_BUTTON 17
#define UP_BUTTON 5
#define DOWN_BUTTON 18
#define RIGHT_BUTTON 19


void setup() {
    Serial.begin(115200);
    Serial.println("Starting BLE work!");
    bleGamepad.begin();

    // Configure button pins with pull-up resistors
    pinMode(BUTTON_1_PIN, INPUT_PULLUP);
    pinMode(BUTTON_2_PIN, INPUT_PULLUP);
    pinMode(BUTTON_3_PIN, INPUT_PULLUP);
    pinMode(BUTTON_4_PIN, INPUT_PULLUP);
    pinMode(BUTTON_5_PIN, INPUT_PULLUP);
    pinMode(BUTTON_6_PIN, INPUT_PULLUP);
    pinMode(BUTTON_7_PIN, INPUT_PULLUP);
    pinMode(BUTTON_8_PIN, INPUT_PULLUP);
    // Configure GPIO pins as input with pull-up resistors
    pinMode(LEFT_BUTTON, INPUT_PULLUP);
    pinMode(UP_BUTTON, INPUT_PULLUP);
    pinMode(DOWN_BUTTON, INPUT_PULLUP);
    pinMode(RIGHT_BUTTON, INPUT_PULLUP);

}

void loop() {
    if (bleGamepad.isConnected()) {
        // Read left joystick values
        int leftX = analogRead(LEFT_JOYSTICK_VRX); // Read X-axis
        int leftY = analogRead(LEFT_JOYSTICK_VRY); // Read Y-axis

        // Read right joystick values
        int rightX = analogRead(RIGHT_JOYSTICK_VRX); // Read X-axis
        int rightY = analogRead(RIGHT_JOYSTICK_VRY); // Read Y-axis

        // Map analog values to joystick range (0 to 32767)
        int leftX_mapped = map(leftX, 0, 4095, 0, 32767);
        int leftY_mapped = map(leftY, 0, 4095, 0, 32767);
        int rightX_mapped = map(rightX, 0, 4095, 0, 32767);
        int rightY_mapped = map(rightY, 0, 4095, 0, 32767);
        
        // android
        // bleGamepad.setAxes(leftX_mapped, leftY_mapped, rightX_mapped, rightY_mapped);
        // pc
        bleGamepad.setAxes(leftX_mapped, leftY_mapped, rightX_mapped, 0, rightY_mapped);



        // Declare and initialize button states
        bool leftPressed = digitalRead(LEFT_BUTTON) == LOW;
        bool upPressed = digitalRead(UP_BUTTON) == LOW;
        bool downPressed = digitalRead(DOWN_BUTTON) == LOW;
        bool rightPressed = digitalRead(RIGHT_BUTTON) == LOW;

        // Handle button presses
        if (digitalRead(BUTTON_1_PIN) == LOW) {
            bleGamepad.press(BUTTON_1);
        } else {
            bleGamepad.release(BUTTON_1);
        }

        if (digitalRead(BUTTON_2_PIN) == LOW) {
            bleGamepad.press(BUTTON_2);
        } else {
            bleGamepad.release(BUTTON_2);
        }

        if (digitalRead(BUTTON_3_PIN) == LOW) {
            bleGamepad.press(BUTTON_3);
        } else {
            bleGamepad.release(BUTTON_3);
        }

        if (digitalRead(BUTTON_4_PIN) == LOW) {
            bleGamepad.press(BUTTON_4);
        } else {
            bleGamepad.release(BUTTON_4);
        }

        if (digitalRead(BUTTON_5_PIN) == LOW) {
            bleGamepad.press(BUTTON_5);
        } else {
            bleGamepad.release(BUTTON_5);
        }

        if (digitalRead(BUTTON_6_PIN) == LOW) {
            bleGamepad.press(BUTTON_6);
        } else {
            bleGamepad.release(BUTTON_6);
        }

        if (digitalRead(BUTTON_7_PIN) == LOW) {
            bleGamepad.press(BUTTON_7);
        } else {
            bleGamepad.release(BUTTON_7);
        }

        if (digitalRead(BUTTON_8_PIN) == LOW) {
            bleGamepad.press(BUTTON_8);
        } else {
            bleGamepad.release(BUTTON_8);
        }


        // Determine DPAD state based on button inputs
        if (upPressed && leftPressed)
        {
            bleGamepad.setHat1(HAT_UP_LEFT);
        }
        else if (upPressed && rightPressed)
        {
            bleGamepad.setHat1(HAT_UP_RIGHT);
        }
        else if (downPressed && leftPressed)
        {
            bleGamepad.setHat1(HAT_DOWN_LEFT);
        }
        else if (downPressed && rightPressed)
        {
            bleGamepad.setHat1(HAT_DOWN_RIGHT);
        }
        else if (upPressed)
        {
            bleGamepad.setHat1(HAT_UP);
        }
        else if (downPressed)
        {
            bleGamepad.setHat1(HAT_DOWN);
        }
        else if (leftPressed)
        {
            bleGamepad.setHat1(HAT_LEFT);
        }
        else if (rightPressed)
        {
            bleGamepad.setHat1(HAT_RIGHT);
        }
        else
        {
            bleGamepad.setHat1(HAT_CENTERED);
        }

        bleGamepad.sendReport(); // Send the gamepad report
        delay(10); // Reduce noise and prevent spamming
    }
}


