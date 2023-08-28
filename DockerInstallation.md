# INSTALLING DOCKER AND RUNNING ROS NOETIC ON UBUNTU 18.04
This file explains about installation and using docker in any system especially systems with ubuntu 18.04.
## TABLES OF CONTENT
1. Installing docker on ubuntu 18.04
2. Installing docker on ubuntu 20.04
3. Post Installation steps
## 1.Installing Docker(For Ubuntu 18.04)
For installing docker, open up the terminal by pressing *ctrl+alt+T*. Then enter the following commands,

```
sudo apt-get update
sudo apt-get install docker.io
```

To check that the docker is installed, kindly run the following, commands in the terminal

```
sudo systemctl start docker
sudo systemctl status docker
```
Check if the terminal shows something like *active(running)* then the installation goes well so far.
Then enter *ctrl+C* to stop the running command and enter the following commands
```
sudo systemctl enable docker
```
After completion of the steps, kindly open up the new terminal and run these commands,
```
sudo apt install docker-compose
```
As of now the docker installation will be completed.
We can verify by ourselves, if the docker is working well by running the commands like ```sudo docker ps```, if it doesn't throw any errors then the docker installation for the Ubuntu 18.04 is completed successfully. 
To know more about docker there are several tutorials about it on youtube and this is [link](https://docs.docker.com/get-started/) for docker website documentation.

## 2.Installing Docker(For Ubuntu 20.04)
For Installation go to [website](https://docs.docker.com/engine/install/ubuntu/#install-using-the-convenience-script). And follow the **Install using the Convinent script** procedure.
Kindly make sure that you installed *curl* before running the commands,else install *curl* using the commands,
```
sudo apt update
sudo apt install curl
```
Then run the commands given in the website,![Image of commands](https://github.com/Pradhip-A-K/NeuralNetworksproject/blob/main/image1.png?raw=true)
```
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh ./get-docker.sh
```
This script installs all the required files for the docker.

## 3.Post Installation steps(Common for both version of ubuntu)
Kindly run the following commands in a new terminal, these steps are necessary to avoid permission related issues.
```
sudo groupadd docker
sudo usermod -aG docker $USER
```
And the run the command, if it doesn't throw any errors installation process for docker is completed. You are good to proceed!
```
sudo systemctl is-enabled docker
```
If this shows, it is not enabled then run the following commands.
```
sudo systemctl enable docker.service
sudo systemctl enable containerd.service
```
Recommended to watch the videos, to get idea regarding docker on robotics,
1. [Video_1](https://youtu.be/XcJzOYe3E6M?si=wKQqKF9IUb5QJ8Hj)
2. [Video_2](https://youtu.be/SAMPOK_lazw?si=tuU7Ko0nfLKvrXjH)
