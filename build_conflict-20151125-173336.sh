rm -r build
mkdir build
cd build
cmake ..
make clean
make
cd ..
time argos3 -c experiments/DSA.xml
