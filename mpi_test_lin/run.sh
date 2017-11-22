#!/bin/bash
mpirun -np $1 -hostfile mpi_hosts ./mpiTest

