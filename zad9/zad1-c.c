/* Processed by ecpg (13.4 (Debian 13.4-1.pgdg90+1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "zad1.pgc"
#include <stdio.h>

char * p_dbase = "u9koperstynski@localhost:5432";	//"tcp:postgresql://localhost:5432/DB1_lab02";
char * p_user = "u9koperstynski";
char * p_pass = "9koperstynski";

/* exec sql begin declare section */
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 

#line 8 "zad1.pgc"
 char dbname [ 1024 ] ;
 
#line 9 "zad1.pgc"
 char connection_string [ 128 ] ;
 
#line 10 "zad1.pgc"
 char user [ 64 ] ;
 
#line 11 "zad1.pgc"
 char password [ 32 ] ;
 
#line 12 "zad1.pgc"
 char username [ 30 ] ;
 
#line 13 "zad1.pgc"
 char catalog [ 100 ] ;
 
#line 14 "zad1.pgc"
 char database [ 100 ] ;
 
#line 15 "zad1.pgc"
 char query [ 100 ] ;
 
#line 16 "zad1.pgc"
 char schema [ 100 ] ;
 
#line 17 "zad1.pgc"
 char schemas [ 100 ] ;
/* exec sql end declare section */
#line 18 "zad1.pgc"


int main()
{

	printf("\nWartosci funkcji informacyjnych typu current_\n\n");

	// initialize SQL variable
	strcpy(connection_string,p_dbase);
	strcpy(user,p_user);
	strcpy(password,p_pass);

	{ ECPGconnect(__LINE__, 0, connection_string , user , password , "conn", 0); }
#line 30 "zad1.pgc"


	// print name of database
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_database ( )", ECPGt_EOIT, 
	ECPGt_char,(dbname),(long)1024,(long)1,(1024)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 33 "zad1.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_user", ECPGt_EOIT, 
	ECPGt_char,(username),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 34 "zad1.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_catalog", ECPGt_EOIT, 
	ECPGt_char,(catalog),(long)100,(long)1,(100)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 35 "zad1.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_query ( )", ECPGt_EOIT, 
	ECPGt_char,(query),(long)100,(long)1,(100)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 36 "zad1.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_schema ( )", ECPGt_EOIT, 
	ECPGt_char,(schema),(long)100,(long)1,(100)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 37 "zad1.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_schemas ( true )", ECPGt_EOIT, 
	ECPGt_char,(schemas),(long)100,(long)1,(100)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 38 "zad1.pgc"


	printf("current database=%s \n", dbname);
	printf("current user=%s \n", username);
	printf("current catalog=%s \n", catalog);
	printf("current query=%s \n", query);
	printf("current schema=%s \n", schema);
	printf("current schemas=%s \n", schemas);

    	
	// close all connection
	{ ECPGdisconnect(__LINE__, "ALL");}
#line 49 "zad1.pgc"

	return 0;
}
