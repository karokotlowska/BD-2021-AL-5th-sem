/* Processed by ecpg (13.4 (Debian 13.4-1.pgdg90+1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "zad3.pgc"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab09.h"

/* exec sql begin declare section */

	 
	 
	 
	 
	 
	 
	 
	 
 

#line 8 "zad3.pgc"
 char connection_string [ 128 ] ;
 
#line 9 "zad3.pgc"
 char user [ 64 ] ;
 
#line 10 "zad3.pgc"
 char password [ 32 ] ;
 
#line 11 "zad3.pgc"
 char coursename [ 50 ] ;
 
#line 12 "zad3.pgc"
 char imie [ 50 ] ;
 
#line 13 "zad3.pgc"
 char nazwisko [ 50 ] ;
 
#line 14 "zad3.pgc"
 char result [ 100 ] ;
 
#line 15 "zad3.pgc"
 char sql [ 300 ] ;
/* exec sql end declare section */
#line 17 "zad3.pgc"




// error handlers
/* exec sql whenever sqlerror  call crash ( ) ; */
#line 22 "zad3.pgc"

/* exec sql whenever not found  break ; */
#line 23 "zad3.pgc"

 
static void crash(void)
{
    // stop recursion
    /* exec sql whenever sqlerror  continue ; */
#line 28 "zad3.pgc"

 
    fprintf(
        stderr,
        "database serious error %s:\n%s\n",
        sqlca.sqlstate,
        sqlca.sqlerrm.sqlerrmc
    );
 
    { ECPGtrans(__LINE__, NULL, "rollback");}
#line 37 "zad3.pgc"

    { ECPGdisconnect(__LINE__, "CURRENT");}
#line 38 "zad3.pgc"

 
    exit(1);
 
    // restore the original handler
    /* exec sql whenever sqlerror  call crash ( ) ; */
#line 43 "zad3.pgc"

}

int main(int argc, char* argv[])
{
	strcpy(coursename, argv[1]);
	

	// initialize SQL variable
	strcpy(connection_string,p_dbase);
	strcpy(user,p_user);
	strcpy(password,p_pass);


  strcpy(sql, "SELECT nazwisko, imie, opis FROM lab04.uczestnik AS u JOIN lab04.uczest_kurs AS uk ON u.id_uczestnik = uk.id_uczest JOIN  lab04.kurs_opis AS ko USING (id_kurs) WHERE ko.opis LIKE '%");
	strcat(sql, coursename);
	strcat(sql, "%' ORDER BY nazwisko, imie, opis;");
	
  printf("\n \nKOMENDA SQL:\n");
  printf("%s\n\n\n", sql);

	{ ECPGconnect(__LINE__, 0, connection_string , user , password , "conn", 0); 
#line 64 "zad3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 64 "zad3.pgc"


	{ ECPGprepare(__LINE__, NULL, 0, "statement", sql);
#line 66 "zad3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 66 "zad3.pgc"

    
    /* declare RET cursor for $1 */
#line 68 "zad3.pgc"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare RET cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "statement", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 70 "zad3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 70 "zad3.pgc"

 
	for(;;)
	{
	        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch next from RET", ECPGt_EOIT, 
	ECPGt_char,(nazwisko),(long)50,(long)1,(50)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(imie),(long)50,(long)1,(50)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(result),(long)100,(long)1,(100)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 74 "zad3.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;
#line 74 "zad3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 74 "zad3.pgc"

 		printf("%-15s\t%-15s\t|\t%s\n", nazwisko, imie, result);
	}
 
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close RET", ECPGt_EOIT, ECPGt_EORT);
#line 78 "zad3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 78 "zad3.pgc"


	{ ECPGdisconnect(__LINE__, "ALL");
#line 80 "zad3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 80 "zad3.pgc"

	
	return 0;
}