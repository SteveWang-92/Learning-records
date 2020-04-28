#!/bin/bash
sudo apt install build-essential libsqlite3-dev libboost-all-dev libssl-dev \
    git python-setuptools castxml
sudo apt install python-dev python-pygraphviz python-kiwi python-gnome2 ipython libcairo2-dev\
    python3-gi libgirepository1.0-dev python-gi python-gi-cairo \
    gir1.2-gtk-3.0 gir1.2-goocanvas-2.0 python-pip
sudo pip install pygraphviz pycairo PyGObject pygccxml
mkdir ndnsim
cd ndnsim
git clone https://github.com/SteveWang-92/ns-3-dev.git ns-3
git clone https://github.com/SteveWang-92/pybindgen.git pybindgen
git clone https://github.com/SteveWang-92/ndnSIM.git ns-3/src/ndnSIM
git clone https://github.com/SteveWang-92/NFD.git ns-3/src/ndnSIM/NFD
git clone https://github.com/SteveWang-92/ndn-cxx.git ns-3/src/ndnSIM/ndn-cxx
git clone https://github.com/SteveWang-92/websocketpp.git ns-3/src/ndnSIM/NFD/websocketpp
cd ns-3
git checkout b0fdc
cd ..
cd ns-3/src/ndnSIM/NFD 
git checkout 49f22b05e1a57b0a8
cd websocketpp
git checkout c6d7e295bf5a0ab9b5f8
cd ../../ndn-cxx
git checkout 4e372702cfd09f7
cd ../../../
./waf configure --enable-example
./waf 
echo ----------
echo finish all
echo if want test please enter ./waf --run ndn-simple

