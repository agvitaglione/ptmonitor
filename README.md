<p align="center">
  <img src="https://github.com/agvitaglione/ptmonitor/blob/main/img/logo.png" width="500">
</p>
PtMonitor is a GUI-based monitoring applcation running on GNU/Linux system for the collection, elaboration and visualization on screen of vehicle tyre temperature and pressure values. The values are sent through a CAN bus connected to the system whith a USB2CAN module. 
The GUI is developed using GTK3.0 and <a href=https://github.com/bytebrew/slope>slope</a>.

## Installation
Install the required development packages: 
```bash
sudo apt-get install build-essential cmake libgtk-3-dev
```

Install slope toolkit
```bash
cd ~
git clone https://github.com/bytebrew/slope
cd slope
mkdir build
cd build
cmake ..
make
sudo make install
sudo mv /usr/local/lib/libslope.so /lib
```

Install CAN utilities and set USB2CAN module
```bash
sudo apt-get install can-utils
sudo ip link set can0 type can bitrate 250000
sudo ifconfig can0 up
```

Before installing PtMonitor, to not have problems with the possible user accesses for the USB storages visualization, is necessary to edit include/Password.h before compiling, by entering the root password (will be removed from the next versions). Then, the software installation can start:
```bash
cd ~
git clone https://github.com/agvitaglione/ptmonitor
cd ptmonitor
make -j 4
```

PtMonitor must be lunched from the bin directory, otherwise _config.txt_ and _interface_scalable.glade_ won't be found.  

## Configuration file
In _config.txt_ is possible to set:
* IP and PORT of a receiver host that will collect the data with an UDP Socket.
* Number of axis.
* Number of tyres per axys.
* List of _numberOfAxis x numberOfTyrePerAxys_ ID sensors. The sensor IDs must be written in order from left to right, starting from the first axis to the last one. Use NONE if there is no sensor in that position.

Here is an example configuration file:
```
RECEIVER_IP=192.168.1.10
RECEIVER_PORT=7000
NUMBER_OF_AXIS=3
NUMBER_OF_TYRES_PER_AXIS=4
28E311B
28E241E
28E2F1E
28B1826
2900E23
28E0D14
28B3827
2912717
28B1426
28D1832
000003A
NONE
```

## Server UDP
To test a remote host, compile _serverUDP_ using make and run it on the host. It will print sensor data messages on the screen. 
