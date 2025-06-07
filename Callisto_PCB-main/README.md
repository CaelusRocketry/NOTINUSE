# Callisto_PCB


### Code Description
- `Caelus PCB`: backups of CaelusPCB repo.
- `Comms` (Arduino/Teensy based)
  - `Comms/fakeDataLB/fakeDataLB.ino` generates "fake" 16 switch readings and sends it over UART/Serial communications (LB to GPCB). It also translates each of the switch states into a 4 letter hex string. 
  - `Comms/fakeDataLB/toGPCB.ino` takes the 4 digit hex number send from the UART communications from LB and parses it into 16 integers, which could be 16 valves to swtich.

(there are 16 switches to serve as buffer in the case we wish to expand the number of valves we wish to toggle, although we may not use that many.)

- `Rocket PCB`: KiCad diagrams of the PCB to be placed in the Rocket.

- `twowaycomm` (Raspberry Pi based): testing of wireless two way communications between two Raspberry Pis.
  - `twowaycomm/main0.py` is code to be run on the **sender** Raspberry Pi.
    - **HOWEVER** we may run this on a windows computer for testing, in which case `twowaycomm/main0-ON WIN.py` should be used.
  - `twowaycomm/main1.py` is code to be run on the **receiver** Raspberry Pi, which will send an "acknowledgement" message to the sender raspberry pi.
  - `twowaycomm/main.py` is the combination of `twowaycomm/main0.py` and `twowaycomm/main1.py` into a single file.

The sender Rapsberry Pi represents the Ground Station, and the receiver Raspberry Pi represents the Test Stand or GPCB.
