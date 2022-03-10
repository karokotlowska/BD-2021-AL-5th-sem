#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
//#include "lab10pq.h"

char * dbhost = "localhost";
char * dbport = "5432";
char * dbuser = "u9kotlowska";
char * dbpassword = "9kotlowska";
char * dbname = "u9kotlowska";


void doSQL(PGconn *conn, char *command){
  PGresult *result;
  printf("------------------------------\n");
  printf("%s\n", command);
  result = PQexec(conn, command);
  printf("stan polecenia:              %s\n", PQresStatus(PQresultStatus(result)));
  printf("opis stanu:                  %s\n", PQresultErrorMessage(result));
  printf("liczba zmienionych rekordow: %s\n", PQcmdTuples(result));
	
  switch(PQresultStatus(result)) {
    case PGRES_TUPLES_OK:{
      int n = 0, r = 0;
      int nrows   = PQntuples(result);
      int nfields = PQnfields(result);
      printf("liczba zwroconych rekordow = %d\n", nrows);
      printf("liczba zwroconych kolumn   = %d\n", nfields);
      for(r = 0; r < nrows; r++) {
        for(n = 0; n < nfields; n++)
           printf(" %s = %s", PQfname(result, n),PQgetvalue(result,r,n));
        printf("\n");
      }
    }
  }
  PQclear(result);
} 

void usun(PGconn *conn, int id){
  PGresult *result;
  printf("------------------------------\n");
  char komenda[200];
  snprintf(komenda, 200, "DELETE FROM lab04.person WHERE id=%d", id);

  printf("%s\n", komenda);
  result = PQexec(conn, komenda);
  printf("stan polecenia:              %s\n", PQresStatus(PQresultStatus(result)));
  printf("opis stanu:                  %s\n", PQresultErrorMessage(result));
  printf("liczba zmienionych rekordow: %s\n", PQcmdTuples(result));

  switch(PQresultStatus(result)) {
    case PGRES_TUPLES_OK:{
      int n = 0, r = 0;
      int nrows   = PQntuples(result);
      int nfields = PQnfields(result);
      printf("liczba zwroconych rekordow = %d\n", nrows);
      printf("liczba zwroconych kolumn   = %d\n", nfields);
      for(r = 0; r < nrows; r++) {
        for(n = 0; n < nfields; n++)
           printf(" %s = %s", PQfname(result, n),PQgetvalue(result,r,n));
        printf("\n");
      }
    }
  }
  PQclear(result);
} 



int main(){
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


  conn = PQconnectdb(connection_str);
  if (PQstatus(conn) == CONNECTION_BAD) {
     fprintf(stderr, "Connection to %s failed, %s", connection_str, PQerrorMessage(conn));
  } else {
     printf("Connected OK\n");
     doSQL(conn, "CREATE TABLE lab04.person (id INTEGER PRIMARY KEY, fname VARCHAR(60), lname VARCHAR(60));");
     doSQL(conn, "INSERT INTO lab04.person values(10, 'Adam', 'Abacki'),(29,'Bogdan','Babacki'),(31,'Celina', 'Czyz'),(66,'Darek','Dadacki');");
     doSQL(conn, "UPDATE lab04.person SET fname = 'Anna', lname = 'Kowalska' WHERE id=29;");
     doSQL(conn, "SELECT * FROM lab04.person;");
     usun(conn, 66);
     doSQL(conn, "SELECT * FROM lab04.person;");
    // doSQL(conn, "DROP TABLE lab04.person;");
     //doSQL(conn, "INSERT INTO lab04.adres values(111, 'lem@agh.edu.pl')");
  }
  PQfinish(conn);
  return EXIT_SUCCESS;

}
