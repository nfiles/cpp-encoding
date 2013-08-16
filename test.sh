#!/bin/sh

echo Rebuilding...
make rebuild
echo
echo Running...
./bin/encoding.exe
