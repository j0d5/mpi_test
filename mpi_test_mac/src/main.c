/******************************************************
**                                                   **
**  Author: Johannes Steudle                         **
**  File:   main.cpp                                 **
**  Date:   2010.10.14                               **
**                                                   **
******************************************************/

#include <stdio.h>
#include <string.h>
#include "mpi.h"


int main (int argc, char *argv[]) {
  int numtasks; // Number of Tasks
	int rank;
	int resultlen = 100;
	int src;
	int dst;
	int tag = 1;
	int count;
	int rc;

  char  name[resultlen];
	char* outmsg = "Scheint zu funktionieren";
	int   msglength = strlen(outmsg);
	char  inmsg[msglength];

	MPI_Status status;         // status of communication
  // MPI_Request request;       // handle for pending communication

  rc = MPI_Init (&argc, &argv); // Initialize MPI
	if (rc != MPI_SUCCESS) {
		printf ("Error starting MPI. Terminating.\n");
		MPI_Abort(MPI_COMM_WORLD, rc);
	}

  MPI_Comm_rank (MPI_COMM_WORLD, &rank); // get rank
  MPI_Comm_size (MPI_COMM_WORLD, &numtasks); // get number of tasks
	MPI_Get_processor_name (name, &resultlen);

	printf ("Starting MPI...\n");
	printf ("Host name: %s\n", name); 
	printf ("My rank:   %d\n", rank);
	printf ("Number of processes: %d\n", numtasks);

  if (rank == 0) {
		for (dst = 1; dst < numtasks; dst++) {
		  rc = MPI_Send (outmsg, msglength, MPI_CHAR, dst, tag, MPI_COMM_WORLD);
			printf ("Task: %d is sending to %d\n", rank, dst);
		}

	} else {
		src = 0;
			rc = MPI_Recv(inmsg, msglength, MPI_CHAR, src, tag, MPI_COMM_WORLD, &status);
			printf ("Process %d recieved message: %s\n", rank, inmsg);
	}

	rc = MPI_Get_count(&status, MPI_CHAR, &count);
  printf("Task %d: Received %d char(s) from task %d with tag %d \n",
         rank, count, status.MPI_SOURCE, status.MPI_TAG);


  MPI_Finalize();

	return 0;
}
