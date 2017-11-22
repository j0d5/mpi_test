#!/bin/bash
mpd &
mpiexec -n 2 ./mpiTest
