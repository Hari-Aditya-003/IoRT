# 🤖 IoRT: Internet of Robotic Things – Voice Controlled Robot

This project showcases a basic implementation of IoRT using an ESP8266-based robot that can be controlled via voice commands from an Android app.

## 📂 Repository Structure

| Folder/File                | Description                                  |
|---------------------------|----------------------------------------------|
| `ONLYMOVEMENT.ino`        | Arduino sketch for robot movement            |
| `Programs/`               | Contains related Arduino programs            |
| `DOCS/`                   | Documentation and project explanation        |
| `IMAGES Steps to build robot/` | Images of hardware assembly           |
| `Voice_Control_Robot_ESP8266.apk` | Android APK for voice control    |
| `Software/drivers-xp/`    | USB drivers (for older systems)              |
| `New Text Document.txt`   | Miscellaneous notes or instructions          |

## 🛠 Features

- Voice-controlled movement using ESP8266
- Compatible with Android via local Wi-Fi
- Motor driver control via L298N
- Easy-to-follow robot building steps

## 📱 How to Use

1. Upload `ONLYMOVEMENT.ino` to your ESP8266.
2. Power your robot and connect it to Wi-Fi.
3. Install `Voice_Control_Robot_ESP8266.apk` on Android.
4. Use the app to send voice commands like:
   - "forward", "backward", "left", "right", "stop"

## 🧰 Tools & Technologies

- ESP8266 (NodeMCU)
- L298N Motor Driver
- Android App (APK provided)
- IR Sensors (optional for line following)
- Arduino IDE

## 🖼 Visuals

Check the `IMAGES Steps to build robot/` folder for photos of the robot assembly.

## 📜 License

Open-source for educational use. Please credit the author if reused or modified.

---

Made with ❤️ by **Hari Aditya**
