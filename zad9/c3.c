/* Processed by ecpg (13.4 (Debian 13.4-1.pgdg90+1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "c3.pgc"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab09.h"

/* exec sql begin declare section */
	 
	 
	 

	 
	 
	 
	 
	 

#line 7 "c3.pgc"
 char connection_string [ 128 ] ;
 
#line 8 "c3.pgc"
 char user [ 64 ] ;
 
#line 9 "c3.pgc"
 char password [ 32 ] ;
 
#line 11 "c3.pgc"
 char course [ 100 ] ;
 
#line 12 "c3.pgc"
 char imie [ 50 ] ;
 
#line 13 "c3.pgc"
 char nazwisko [ 50 ] ;
 
#line 14 "c3.pgc"
 char coursedesc [ 100 ] ;
 
#line 15 "c3.pgc"
 char query [ 300 ] ;
/* exec sql end declare section */
#line 16 "c3.pgc"


/* exec sql whenever sqlerror  call crash ( ) ; */
#line 18 "c3.pgc"

/* exec sql whenever not found  break ; */
#line 19 "c3.pgc"

 
static void crash(void)
{

    /* exec sql whenever sqlerror  continue ; */
#line 24 "c3.pgc"

 
    fprintf(
        stderr,
        "database serious error %s:\n%s\n",
        sqlca.sqlstate,
        sqlca.sqlerrm.sqlerrmc
    );
 
    { ECPGtrans(__LINE__, NULL, "rollback");}
#line 33 "c3.pgc"

    { ECPGdisconnect(__LINE__, "CURRENT");}
#line 34 "c3.pgc"

 
    exit(1);
 
    // restore the original handler
    /* exec sql whenever sqlerror  call crash ( ) ; */
#line 39 "c3.pgc"

}

int main(int argc, char* argv[])
{
	
	if(argc >= 1){

	strcpy(course, argv[1]);

	strcpy(connection_string, p_dbase);
	strcpy(user, p_user);
	strcpy(password, p_pass);

	strcpy(query, "SELECT nazwisko, imie, opis FROM lab04.uczestnik, lab04.uczest_kurs, lab04.kurs_opis WHERE id_uczestnik = id_uczest AND uczest_kurs.id_kurs = kurs_opis.id_kurs AND opis LIKE '%");
	strcat(query, course);
	strcat(query, "%' ORDER BY nazwisko, imie, opis;");
	printf("%s\n", query);
	{ ECPGconnect(__LINE__, 0, connection_string , user , password , "conn", 0); 
#line 57 "c3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 57 "c3.pgc"


	{ ECPGprepare(__LINE__, NULL, 0, "statement", query);
#line 59 "c3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 59 "c3.pgc"


    /* declare C1 cursor for $1 */
#line 61 "c3.pgc"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare C1 cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "statement", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 63 "c3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 63 "c3.pgc"

 
	for(;;)
	{
	        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch next from C1", ECPGt_EOIT, 
	ECPGt_char,(nazwisko),(long)50,(long)1,(50)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(imie),(long)50,(long)1,(50)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(coursedesc),(long)100,(long)1,(100)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 67 "c3.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;
#line 67 "c3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 67 "c3.pgc"

 		printf("%-15s\t%-15s\t|\t%s\n", nazwisko, imie, coursedesc);
	}
 
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close C1", ECPGt_EOIT, ECPGt_EORT);
#line 71 "c3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 71 "c3.pgc"


	{ ECPGdisconnect(__LINE__, "ALL");
#line 73 "c3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 73 "c3.pgc"

	}
	return 0;
}
