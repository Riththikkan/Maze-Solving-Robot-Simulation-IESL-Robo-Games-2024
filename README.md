# E-puck Wall Follower – IESL Robo Games 2024

This project was developed for the **IESL Robo Games 2024**, organized by the **University of Moratuwa**. The objective was to build a Webots-simulated robot capable of solving a maze using intelligent wall-following behavior. Two different implementations were developed:

---

## 🧠 Project Goal

Simulate an **autonomous E-puck robot** that can follow walls and navigate through a maze using either:
- Logic-based control (C)
- Fuzzy logic-based control (Python)



## 🧠 C Version – `wall_follower.c`

Implements simple rule-based wall-following logic using proximity sensors ps5, ps6, ps7, and ps2.

### Features:
- Follows the left wall using threshold logic
- Adjusts wheel speed based on wall proximity
- Implements turning and forward motion behavior

---

## 🧠 Python Version – `wall_follower_fuzzy.py`

Implements fuzzy logic using scikit-fuzzy to determine appropriate motor speeds based on sensor data.

### Features:
- Uses fuzzy logic rules to determine robot speed
- Inputs: ps5 sensor distance
- Output: Speed adjustment for left and right wheels
- Behavior dynamically adapts to wall proximity

---

## 🔧 Technologies Used

- [Webots](https://cyberbotics.com/) simulation software
- C Programming
- Python 3

---

## 📚 Learnings & Outcome

Although the full maze-solving algorithm was not implemented in time for competition submission, this project significantly improved our team's knowledge of:

- Differential drive control
- Sensor-based navigation
- Fuzzy logic systems
- Webots robot programming

---

## 👨‍💻 Team Members
- Riththikkan Sairam
- Kavindu Pabasara

## 📅 Event
**IESL Robo Games 2024** – Simulation Category  
Organized by the **University of Moratuwa**
