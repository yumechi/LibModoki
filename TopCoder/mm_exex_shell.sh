#!/bin/zsh
# FOR C++ compile and execute java Tester
# Author: yumechi
set -ue
SOURCENAME='Template'

g++-8 -DDEBUG -Wall -std=c++11 ${SOURCENAME}.cpp -o ${SOURCENAME}
cd tester
for i in `seq 1 3`;  do echo ''; done
echo 'success compile!'
echo '-----------------------------------------'
java -jar Tester.jar -exec "../${SOURCENAME}"
cd ..
