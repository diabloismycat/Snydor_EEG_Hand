# Snydor EEG Hand 

Hi~ I am Adora, this is a real-time EEG-controlled tendon-driven robotic hand system.

This project builds a complete Brain-Computer Interface (BCI) pipeline using EEG signals, signal processing algorithms, and embedded robotic control.

Our final goal is to decode motor intention from EEG signals and control a tendon-driven robotic hand in real time.

---

## System Architecture

```text
OpenBCI EEG
     |
     v
EEG Acquisition
     |
     v
EEG Buffer (Sliding Window)
     |
     v
Signal Processing
     |
     +--> Bandpass Filter
     |
     +--> ICA Artifact Removal
     |
     v
Feature Extraction
     |
     v
Classifier
     |
     v
Arduino
     |
     v
Tendon-driven Robotic Hand
```

---

## Current Progress

### Core Framework

- [x] Modular C++ project structure
- [x] CMake build system
- [x] CSV EEG data reader
- [x] Real-time EEG sliding buffer
- [x] Eigen matrix conversion
- [x] ICA processing interface

### Signal Processing

- [ ] Bandpass filtering
- [ ] ICA implementation
- [ ] Feature extraction

### Machine Learning

- [ ] Motor imagery classifier
- [ ] LDA model
- [ ] Real-time prediction

### Hardware

- [ ] OpenBCI streaming
- [ ] Arduino / ESP32 communication
- [ ] Tendon-driven robotic hand control


---

## Software Architecture

```text
src/

CSVReader
    |
    v
EEGBuffer
    |
    v
MatrixConverter
    |
    v
ICA
    |
    v
FeatureExtractor
    |
    v
Classifier
```

Each module follows a single responsibility design principle.


---

## Build

### Requirements

- C++17
- CMake
- Eigen


### Compile

```bash
mkdir build
cd build

cmake ..

make
```


### Run

```bash
./Snydor_EEG_Hand
```


---

## Hardware Plan

Target hardware:

- 8-channel EEG
- Arduino 
- Tendon-driven robotic hand
- Servo motor actuation


---

## Development Roadmap

### v0.1

Current:

- Data pipeline
- CMake structure
- Matrix interface


### v0.2

Next:

- ICA integration
- EEG filtering


### v0.3

- Feature extraction
- Motor imagery classification


### v1.0

- Real-time EEG robotic hand control


---

## Author

Developed by DAJ (Adora and Sunny).

Project: Snydor EEG Hand
