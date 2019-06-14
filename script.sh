#!/bin/bash
echo 'compiling'
g++ main.cpp
echo ''
echo 'executing'
./a.out
echo ''
echo 'running graham_visual'
python3 graham_visual.py
echo ''
echo ''
echo 'Successfull!!!'
echo ''
echo 'Check the current directory to find the gif of visualization'
echo 'You can change the input by changing the number in the main.cpp file on line 11.'