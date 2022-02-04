/* Processed by ecpg (13.4 (Debian 13.4-1.pgdg90+1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "zad2.pgc"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab09.h"


/* exec sql begin declare section */
	 
	 
	 
	 

	 
   
	 

#line 8 "zad2.pgc"
 char dbname [ 1024 ] ;
 
#line 9 "zad2.pgc"
 char connection_string [ 128 ] ;
 
#line 10 "zad2.pgc"
 char user [ 64 ] ;
 
#line 11 "zad2.pgc"
 char password [ 32 ] ;
 
#line 13 "zad2.pgc"
 int id ;
 
#line 14 "zad2.pgc"
 char nemail [ 100 ] ;
 
#line 15 "zad2.pgc"
 char upd [ 512 ] ;
/* exec sql end declare section */
#line 16 "zad2.pgc"




// error handlers
/* exec sql whenever sqlerror  call crash ( ) ; */
#line 21 "zad2.pgc"

/* exec sql whenever not found  break ; */
#line 22 "zad2.pgc"

 
static void crash(void)
{
    // stop recursion
    /* exec sql whenever sqlerror  continue ; */
#line 27 "zad2.pgc"

 
    fprintf(
        stderr,
        "database serious error %s:\n%s\n",
        sqlca.sqlstate,
        sqlca.sqlerrm.sqlerrmc
    );
 
    { ECPGtrans(__LINE__, NULL, "rollback");}
#line 36 "zad2.pgc"

    { ECPGdisconnect(__LINE__, "CURRENT");}
#line 37 "zad2.pgc"

 
    exit(1);
 
    // restore the original handler
    /* exec sql whenever sqlerror  call crash ( ) ; */
#line 42 "zad2.pgc"

}

int main(int argc, char* argv[])
{
	
  id = atoi(argv[1]);
  strcpy(nemail, argv[2]);
	// initialize SQL variable
	strcpy(connection_string,p_dbase);
	strcpy(user,p_user);
	strcpy(password,p_pass);


	{ ECPGconnect(__LINE__, 0, connection_string , user , password , "conn", 0); 
#line 56 "zad2.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 56 "zad2.pgc"


	strcpy(upd,"UPDATE lab04.uczestnik SET email=\'");
  strcat(upd,nemail);
  strcat(upd,"\' WHERE id_uczestnik=");
  strcat(upd,argv[1]);
  printf("\n Zmiana emaila uczestnika o id: %d na maila: %s",id,nemail);
  printf("\n \n KOMENDA SQL:\n");
  printf("\n %s\n\n",upd);

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_exec_immediate, upd, ECPGt_EOIT, ECPGt_EORT);
#line 66 "zad2.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 66 "zad2.pgc"


    	{ ECPGtrans(__LINE__, NULL, "commit");
#line 68 "zad2.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 68 "zad2.pgc"

	// close all connection
	{ ECPGdisconnect(__LINE__, "ALL");
#line 70 "zad2.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 70 "zad2.pgc"

	return 0;
}
