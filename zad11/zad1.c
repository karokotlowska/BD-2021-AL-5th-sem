#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include "lab10pq.h"
#include <stdio.h>

void doSQL(PGconn *conn, char *command){
  PGresult *result;
  result = PQexec(conn, command);
	
  switch(PQresultStatus(result)) {
    case PGRES_TUPLES_OK:{
      int n = 0, r = 0;
      int nrows   = PQntuples(result);
      int nfields = PQnfields(result);
      for(r = 0; r < nrows; r++) {
        for(n = 0; n < nfields; n++)
           printf(" %s = %s", PQfname(result, n),PQgetvalue(result,r,n));
        printf("\n");
      }
    }
  }
  PQclear(result);
} 



int main(int argc, char *argv[]){
  PGresult *result;
  PGconn *conn;
  char connection_str[256];

	strcpy(connection_str, "host=");
	strcat(connection_str, dbhost);
	strcat(connection_str, " port=");
	strcat(connection_str, dbport);
	strcat(connection_str, " dbname=");
	strcat(connection_str, dbname);
	strcat(connection_str, " user=");
	strcat(connection_str, dbuser);
	strcat(connection_str, " password=");
	strcat(connection_str, dbpassword);
	
	if(argc != 3){
		printf("Poprawne wywolanie funkcji: ./zad1 poczatkowe id koncowe id\n");	
		return 1;
	}
	int p = atoi(argv[1]);
	int k = atoi(argv[2]);

  conn = PQconnectdb(connection_str);
  if (PQstatus(conn) == CONNECTION_BAD) {
     fprintf(stderr, "Connection to %s failed, %s", connection_str, PQerrorMessage(conn));
  } else {
     printf("Connected OK\n");
  	char command[200];
	char str[20];
	for(int i = p; i <= k; i++){
		snprintf(str, 20, "%d", i);
		strcpy(command, "select * from lab04.uczestnik where id_uczestnik = ");
		strcat(command, str); 
		doSQL(conn, command);  		
 	}
  }
  PQfinish(conn);
  return EXIT_SUCCESS;

}
