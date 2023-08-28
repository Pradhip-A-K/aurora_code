#  ROSSERIAL AND ARDUINO IDE INSTALLATION
## TABLE OF CONTENTS
1. Arduino IDE installation steps
2. Rosserial installation steps
### ARDUINO IDE INSTALLATION STEPS
1. Click the [LINK](https://www.arduino.cc/en/software) and download the Arduino IDE 1.8.x (Legacy IDE) zip file which will be in the file format ".tar.xz".
2. Follow the installation procedure given in the [LINK](https://docs.arduino.cc/software/ide-v1/tutorials/Linux) after downloading.
3. To check if the IDE is installed kindly dont try to click the Arduino IDE icon, it might not work for some systems. Hence open using the command line.
4. Use "Ctrl+alt+T" to open up the terminal and enter the command '''arduino''' in the terminal.
5. If the Arduino IDE opens up then the Arduino IDE installation is complete.

*NOTE: Since we have tested only using Arduino IDE 1.8.x, we suggest that if you are going to install the latest version you may face some issues and above steps might not work, **We are also strongly suggesting that extract the zip file in the home directory for easier installation process.***

### ROSSERIAL INSTALLATION STEPS
Click the [link](http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup) and Follow the steps. I am just adding few suggestions before installing,
1. Follow the recommended step in 2.1.1 i.e., Installing Binaries on ROS workstation.
2. Instead of step 2.2 use the following commands,by opening up in a new terminal.

```
cd Arduino/libraries
rosrun rosserial_arduino make_libraries.py .
```
*NOTE: IF you installed the Arduino IDE in home directory this step will be straight forward, just run the following commands*

3. Then follow the step 3 as given in the link.
4. To test the installation kindly follow the *HelloWorld example* as given in the [link](http://wiki.ros.org/rosserial_arduino/Tutorials/Hello%20World) by connecting and uploading the code in the Arduino UNO.

*NOTE:Kindly note down the port number with which ArduinoUNO is connected. Port Number can be seen at the bottom right of the Arduino IDE or Tools->Port and it will be in the format **/dev/tty/ACM0** or similar depending upon the device and kindly replace the port number with your's at step 1.5.*
