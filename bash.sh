#!/bin/sh

cd ~ 
mkdir local
mkdir ~/repos
cd ~/repos
git clone https://github.com/mirror/ncurses.git
cd ncurses
./configure --prefix ~/local --enable-widec --with-pthread
make -j
make -j install


cd ~

make game

./game
