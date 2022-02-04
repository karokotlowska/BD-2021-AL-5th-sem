/* Processed by ecpg (13.4 (Debian 13.4-1.pgdg90+1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "c2.pgc"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab09.h"

/* exec sql begin declare section */
	 
	 
	 

	 
	 
	 

#line 7 "c2.pgc"
 char connection_string [ 128 ] ;
 
#line 8 "c2.pgc"
 char user [ 64 ] ;
 
#line 9 "c2.pgc"
 char password [ 32 ] ;
 
#line 11 "c2.pgc"
 int id ;
 
#line 12 "c2.pgc"
 char newemail [ 150 ] ;
 
#line 13 "c2.pgc"
 char updatequery [ 150 ] ;
/* exec sql end declare section */
#line 14 "c2.pgc"


/* exec sql whenever sqlerror  call crash ( ) ; */
#line 16 "c2.pgc"

/* exec sql whenever not found  break ; */
#line 17 "c2.pgc"

 
static void crash(void)
{

    /* exec sql whenever sqlerror  continue ; */
#line 22 "c2.pgc"

 
    fprintf(
        stderr,
        "database serious error %s:\n%s\n",
        sqlca.sqlstate,
        sqlca.sqlerrm.sqlerrmc
    );
 
    { ECPGtrans(__LINE__, NULL, "rollback");}
#line 31 "c2.pgc"

    { ECPGdisconnect(__LINE__, "CURRENT");}
#line 32 "c2.pgc"

 
    exit(1);
 
    // restore the original handler
    /* exec sql whenever sqlerror  call crash ( ) ; */
#line 37 "c2.pgc"

}

int main(int argc, char* argv[])
{
	
	if(argc >= 2){

	id = atoi(argv[1]);
	strcpy(newemail, argv[2]);

	strcpy(connection_string, p_dbase);
	strcpy(user, p_user);
	strcpy(password, p_pass);


	{ ECPGconnect(__LINE__, 0, connection_string , user , password , "conn", 0); 
#line 53 "c2.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 53 "c2.pgc"


	strcpy(updatequery, "UPDATE lab04.uczestnik SET email = \'");
	strcat(updatequery, newemail);
	strcat(updatequery, "\' WHERE id_uczestnik = ");
	strcat(updatequery, argv[1]);
	printf("\tEXECUTING QUERY:\n");
	printf("%s\n", updatequery);

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_exec_immediate, updatequery, ECPGt_EOIT, ECPGt_EORT);
#line 62 "c2.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 62 "c2.pgc"


    	{ ECPGtrans(__LINE__, NULL, "commit");
#line 64 "c2.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 64 "c2.pgc"


	{ ECPGdisconnect(__LINE__, "ALL");
#line 66 "c2.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 66 "c2.pgc"

	}
	return 0;
}
