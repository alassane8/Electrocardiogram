# SF6 Save and consult user's data
Secondary function SF6 allows storing various heart rate measurements in memory and retrieving them at any time

## Technical Requirements
### TR6.1 The memory used for recordings must be non-volatile, allowing data retrieval in case of power interruption and restart.

### TR6.2 The memory used must be the internal EEPROM memory of the Arduino's ATMega328P microcontroller.

### TR6.3 Each recording must be triggered using a push button and is the average of 10 consecutive measurements.

### TR6.4 Each recording must include a BPM measurement, date, and time.

### TR6.5 A menu, controllable with a potentiometer and one or more push buttons, should allow viewing and deleting measurements.

### TR6.6 The system must allow its user to have an interface in both French and English.