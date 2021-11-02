#!/bin/bash

# adding files 
echo Aleksandr > lofsdisk/file1
echo Evdokimov > lofsdisk/file2

# creating directories needed
sudo mkdir -p lofsdisk/bin
sudo mkdir -p lofsdisk/lib64
sudo mkdir -p lofsdisk/lib/x86_64-linux-gnu
sudo mkdir -p lofsdisk/usr/lib
sudo mkdir -p lofsdisk/usr/lib64

# copying the content of bash/cat/echo/ls
sudo cp /bin/bash lofsdisk/bin
sudo cp /bin/cat lofsdisk/bin
sudo cp /bin/echo lofsdisk/bin
sudo cp /bin/ls lofsdisk/bin
sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64

# add dependencies for bash/cat/echo/ls
sudo ldd /bin/bash | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}
sudo ldd /bin/ls | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}
sudo ldd /bin/cat | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}
sudo ldd /bin/echo | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}

gcc ex2.c -o ex2.out
sudo cp ex2.out lofsdisk
sudo chroot lofsdisk /ex2.out > ex2.txt
./ex2.out >> ex2.txt
