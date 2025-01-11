# ESP32 BLE Gamepad

Welcome to the ESP32 BLE Gamepad project! This versatile gamepad is designed for gaming, drone control, and RC vehicle operation. It also doubles as a portable power bank, thanks to its two 2600mAh 18650 batteries. Built using the Arduino IDE and the ESP32 BLE Gamepad library, this project features HW-504 joysticks, a durable PVC pipe frame, and advanced power management with a voltage booster and TP4056 Type-C charger.

## Features
- **Dual Joystick Control**: Two HW-504 joysticks for precise control.
- **Multiple Buttons**: 8 buttons for various functions.
- **DPAD Support**: Directional pad for navigation.
- **Power Bank Functionality**: Two 2600mAh 18650 batteries to keep your devices charged on the go.
- **Advanced Power Management**: Voltage booster and TP4056 Type-C charger for efficient power management.

## Hardware Requirements
- ESP32 WROOM 32
- HW-504 Joysticks
- 8 Push Buttons
- Two 2600mAh 18650 Batteries
- Voltage Booster
- TP4056 Type-C Charger
- PVC Pipe Frame

## Software Requirements
- Arduino IDE
- ESP32 BLE Gamepad Library

## Installation and Setup

1. **Clone the Repository**
   ```bash
   git clone https://github.com/yourusername/esp32-ble-gamepad.git
   ```

2. **Open the Project in Arduino IDE**
   - Open the `esp32-ble-gamepad.ino` file in the Arduino IDE.

3. **Install Required Libraries**
   - Install the `BleGamepad` library from the Arduino Library Manager.

4. **Configure the Pins**
   - Ensure the pins are connected as per the following configuration or you can define your own configuration of the pins:
     ```cpp
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
     ```

5. **Platform Configuration**
   - For **Android**:
     ```cpp
     bleGamepad.setAxes(leftX_mapped, leftY_mapped, rightX_mapped, rightY_mapped);
     ```
   - For **PC**:
     ```cpp
     bleGamepad.setAxes(leftX_mapped, leftY_mapped, rightX_mapped, 0, rightY_mapped);
     ```
   - Comment and uncomment the respective lines in the code based on the platform you are targeting.
   - Please do not uncommment both lines only choose one.

6. **Upload the Code**
   - Connect your ESP32 to your computer.
   - Select the appropriate board and port in the Arduino IDE.
   - Upload the code to the ESP32.

## Usage

1. **Pairing the Gamepad**
   - Power on the ESP32 BLE Gamepad.
   - Pair the gamepad with your Android device or PC via Bluetooth.

2. **Using the Gamepad**
   - Once paired, the gamepad can be used to control games, drones, or RC vehicles.
   - The gamepad also functions as a power bank to charge your devices on the go.

## Known Issues
- **Windows Pairing Bug**: Currently, there is a bug on Windows that requires re-pairing the gamepad each session. However, it performs flawlessly once connected.

## Contributing
Feel free to fork the repository and submit pull requests. For major changes, please open an issue first to discuss what you would like to change.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments
- [ESP32 BLE Gamepad Library](https://github.com/lemmingDev/ESP32-BLE-Gamepad)
- Arduino Community

## Contact
For any questions or feedback, please open an issue on GitHub or contact the project maintainer.

Happy gaming and tinkering! 🎮🚁🏎️

#ESP32 #Arduino #Bluetooth #Gamepad #DIY #IoT #Drone #RCCars #Gaming #PowerBank #EmbeddedSystems
