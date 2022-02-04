#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
//#include "lab10pq.h"

char * dbhost = "localhost";
char * dbport = "5432";
char * dbuser = "u9miszczak";
char * dbpassword = "9miszczak";
char * dbname = "u9miszczak";


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
      printf("liczba zwroconych rekord體 = %d\n", nrows);
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
	int id_p, id_k;
     printf("Connected OK\n");
printf("Podaj paczatkwe id uczestnika:");
  scanf("%d",&id_p );
  printf("Podales: %d\n",id_p);
  printf("Podaj koncowe uczestnika:");
  scanf("%d",&id_k );
  printf("Podales: %d\n",id_k);
char komenda[200];
  snprintf(komenda, 200, "SELECT id_uczestnik, nazwisko, imie FROM lab04.uczestnik JOIN lab04.uczest_kurs ON id_uczest=id_uczestnik WHERE id_uczestnik> %d AND id_uczestnik<%d GROUP BY id_uczestnik",id_p,id_k);

     doSQL(conn, komenda);
    // doSQL(conn, "INSERT INTO lab04.adres values(111, 'lem@agh.edu.pl')");
  }
  PQfinish(conn);
  return EXIT_SUCCESS;

}
