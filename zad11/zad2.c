#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include "lab10pq.h"

void doSQL(PGconn *conn, char *command){
  PGresult *result;
  printf("------------------------------\n");
  printf("%s\n", command);
  result = PQexec(conn, command);
  printf("stan polecenia:              %s\n", PQresStatus(PQresultStatus(result)));
  printf("opis stanu:                  %s\n", PQresultErrorMessage(result));
  printf("liczba zmienionych rekord體: %s\n", PQcmdTuples(result));
	
  switch(PQresultStatus(result)) {
    case PGRES_TUPLES_OK:{
      int n = 0, r = 0;
      int nrows   = PQntuples(result);
      int nfields = PQnfields(result);
      printf("liczba zwr骳onych rekord體 = %d\n", nrows);
      printf("liczba zwr骳onych kolumn   = %d\n", nfields);
      for(r = 0; r < nrows; r++) {
        for(n = 0; n < nfields; n++)
           printf(" %s = %s", PQfname(result, n),PQgetvalue(result,r,n));
        printf("\n");
      }
    }
  }
  PQclear(result);
} 

void usun(PGconn *conn, int id)
{
char command[200];
	char str[20];
	snprintf(str, 20, "%d", id);
	strcpy(command, "delete from lab04.person where id = ");
	strcat(command, str); 
	doSQL(conn, command);  
     
}


void zmienRekord(PGconn *conn, char *name, char *surname, int id){
  char command[200];
	char str[20];
	snprintf(str, 20, "%d", id);
	strcpy(command, "update lab04.person SET fname = '");
  strcat(command,name);
  strcat(command,"' , lname = '");
  strcat(command, surname);
  strcat(command, "' where id = ");
  strcat(command, str);
  

	doSQL(conn, command); 
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
     doSQL(conn, "INSERT INTO lab04.person values(10, ),(29, ),(31, 'Czarek', 'Cabacki'),(66, 'Darek', 'Dabacki')");
     doSQL(conn, "INSERT INTO lab04.person values(10,'Adam', 'Abacki')");
     doSQL(conn, "INSERT INTO lab04.person values(29, 'Bartek', 'Babacki')");
     doSQL(conn, "INSERT INTO lab04.person values(31, 'Czarek', 'Cabacki')");
     doSQL(conn, "INSERT INTO lab04.person values(66, 'Darek', 'Dabacki')");
     
     zmienRekord(conn,"Zbyszek","Zabacki",29);
     usun(conn,66);
     
     doSQL(conn, "SELECT * FROM lab04.person;");     
  
  
  }
  PQfinish(conn);
  return EXIT_SUCCESS;

}
