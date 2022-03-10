/* Processed by ecpg (13.4 (Debian 13.4-1.pgdg90+1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "zad1.pgc"
#include <stdio.h>

char * p_dbase = "u9kotlowska@localhost:5432";	//"tcp:postgresql://localhost:5432/DB1_lab02";
char * p_user = "u9kotlowska";
char * p_pass = "9kotlowska";

/* exec sql begin declare section */
	 
	 
	 
	 
   
   
	 
	 
	 



#line 8 "zad1.pgc"
 char dbname [ 50 ] ;
 
#line 9 "zad1.pgc"
 char connection_string [ 50 ] ;
 
#line 10 "zad1.pgc"
 char user [ 50 ] ;
 
#line 11 "zad1.pgc"
 char password [ 50 ] ;
 
#line 12 "zad1.pgc"
 char username [ 30 ] ;
 
#line 13 "zad1.pgc"
 char dbcatalog [ 100 ] ;
 
#line 14 "zad1.pgc"
 char dbquery [ 100 ] ;
 
#line 15 "zad1.pgc"
 char dbschema [ 100 ] ;
 
#line 16 "zad1.pgc"
 char dbschemas [ 100 ] ;
/* exec sql end declare section */
#line 19 "zad1.pgc"


int main()
{
	
	strcpy(connection_string,p_dbase);
	strcpy(user,p_user);
	strcpy(password,p_pass);

	{ ECPGconnect(__LINE__, 0, connection_string , user , password , "conn", 0); }
#line 28 "zad1.pgc"


	// print name of database
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_database ( )", ECPGt_EOIT, 
	ECPGt_char,(dbname),(long)50,(long)1,(50)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 31 "zad1.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_user", ECPGt_EOIT, 
	ECPGt_char,(username),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 32 "zad1.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_datcatalog ( )", ECPGt_EOIT, 
	ECPGt_char,(dbcatalog),(long)100,(long)1,(100)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 33 "zad1.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_query ( )", ECPGt_EOIT, 
	ECPGt_char,(dbquery),(long)100,(long)1,(100)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 34 "zad1.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_schema ( )", ECPGt_EOIT, 
	ECPGt_char,(dbschema),(long)100,(long)1,(100)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 35 "zad1.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_schemas ( )", ECPGt_EOIT, 
	ECPGt_char,(dbschemas),(long)100,(long)1,(100)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 36 "zad1.pgc"
	
	
  printf("current database=%s \n", dbname);
  printf("current catalog=%s \n", dbcatalog);
	printf("current query=%s \n", dbquery);
	printf("current schema=%s \n", dbschema);
	printf("current schemas=%s \n", dbschemas);
  printf("current user=%s \n", username);
	

	// close all connection
	{ ECPGdisconnect(__LINE__, "ALL");}
#line 47 "zad1.pgc"

	return 0;
}
