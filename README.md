
# 🔐 Digital Safe Lock System

A password based digital security lock system developed using **Arduino UNO and Embedded C**.The system uses a 4×4 matrix keypad for password entry, EEPROM for permanent password storage, a 16×2 LCD for user interaction, a servo motor for lock/unlock operation, and a buzzer for security alerts.

## 📌 Project Overview

Developed a **password-based digital security system** using Arduino Uno for controlled access and electronic locking.

The system integrates a **4×4 matrix keypad, EEPROM, 16×2 LCD, servo motor, and buzzer** to implement password authentication, non-volatile password storage, and physical lock control.

## 🎯 Objective

To design and implement an embedded access-control system that provides:

- Password-based authentication
- Non-volatile password storage
- Electronic locking and unlocking
- User feedback through an LCD
- Security alerts for incorrect passwords

## ⚙️ System Working

1. The user enters a **4-digit password** through the 4×4 matrix keypad.
2. Arduino performs **row-column matrix scanning** to identify the pressed key.
3. The entered password is compared with the password stored in **EEPROM**.
4. If the password is correct, the **servo motor unlocks** the system.
5. If the password is incorrect, the system remains locked and the **buzzer generates an alert**.
6. The **16×2 LCD** displays the current system status.
7. A password-reset mechanism allows the stored password to be updated.

## 🔧 Hardware Components

| Component | Function |
|-----------|----------|
| Arduino Uno | Main controller |
| 4×4 Matrix Keypad | Password input |
| 16×2 LCD | User interface |
| Servo Motor | Locking mechanism |
| Buzzer | Security alert |
| EEPROM | Non-volatile password storage |

## 💻 Technical Implementation

- **Embedded C / Arduino C** for application logic and system control
- **GPIO-based matrix scanning** for keypad interfacing
- **EEPROM read/write operations** for persistent password storage
- **Servo control** for electronic lock actuation
- **LCD interfacing** for real-time user feedback
- Modular programming using **user-defined functions**
- Hardware-software integration and debugging

## 🔑 Key Features

- 🔐 4-digit password authentication
- 💾 Non-volatile password storage using EEPROM
- ⌨️ 4×4 matrix keypad interfacing
- 🔒 Servo-based electronic locking
- 🖥️ LCD-based system status display
- 🔊 Incorrect-password alert
- 🔄 Password reset functionality
- 🚫 Keypad scanning implemented without the Keypad library

## 📊 System Architecture

```text
                 ┌──────────────────┐
                 │   4×4 Keypad     │
                 │  Password Input  │
                 └────────┬─────────┘
                          │
                          ▼
                 ┌──────────────────┐
                 │    Arduino Uno   │
                 │                  │
                 │  Keypad Scanning │
                 │  Authentication  │
                 │  EEPROM Handling │
                 └───────┬──────────┘
                         │
              ┌──────────┼──────────┐
              │          │          │
              ▼          ▼          ▼
        ┌──────────┐ ┌────────┐ ┌─────────┐
        │   LCD    │ │ Servo  │ │ Buzzer  │
        │ Display  │ │  Lock  │ │  Alert  │
        └──────────┘ └────────┘ └─────────┘
