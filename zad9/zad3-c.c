/* Processed by ecpg (13.4 (Debian 13.4-1.pgdg90+1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "zad3.pgc"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * p_dbase = "u9koperstynski@localhost:5432";	//"tcp:postgresql://localhost:5432/DB1_lab02";
char * p_user = "u9koperstynski";
char * p_pass = "9koperstynski";

/* exec sql begin declare section */
	 
	 
	 
	 
	
	 
	 
	 	
	 

#line 10 "zad3.pgc"
 char dbname [ 1024 ] ;
 
#line 11 "zad3.pgc"
 char connection_string [ 128 ] ;
 
#line 12 "zad3.pgc"
 char user [ 64 ] ;
 
#line 13 "zad3.pgc"
 char password [ 32 ] ;
 
#line 15 "zad3.pgc"
 char surname [ 100 ] ;
 
#line 16 "zad3.pgc"
 char name [ 100 ] ;
 
#line 17 "zad3.pgc"
 char opis_kursu [ 100 ] ;
 
#line 18 "zad3.pgc"
 int id ;
/* exec sql end declare section */
#line 19 "zad3.pgc"



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

int main()
{
	printf("\nProgram pgc wypisujący na konsoli listę uczestników zadanego kursu\n\n");
	
	//printf("Podaj id kursu:");

	// initialize SQL variable
	strcpy(connection_string,p_dbase);
	strcpy(user,p_user);
	strcpy(password,p_pass);
	
	/* declare cur_uczestnik cursor for select opis , imie , nazwisko from lab04 . uczestnik join lab04 . uczest_kurs on id_uczestnik = id_uczest join lab04 . kurs using ( id_kurs ) join lab04 . kurs_opis on kurs . id_nazwa = kurs_opis . id_kurs order by opis , nazwisko , imie */
#line 58 "zad3.pgc"



	{ ECPGconnect(__LINE__, 0, connection_string , user , password , "conn", 0); 
#line 61 "zad3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 61 "zad3.pgc"

		
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cur_uczestnik cursor for select opis , imie , nazwisko from lab04 . uczestnik join lab04 . uczest_kurs on id_uczestnik = id_uczest join lab04 . kurs using ( id_kurs ) join lab04 . kurs_opis on kurs . id_nazwa = kurs_opis . id_kurs order by opis , nazwisko , imie", ECPGt_EOIT, ECPGt_EORT);
#line 63 "zad3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 63 "zad3.pgc"

	
	for(;;){
        	// fetch next record
	    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch next from cur_uczestnik", ECPGt_EOIT, 
	ECPGt_char,(opis_kursu),(long)100,(long)1,(100)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(name),(long)100,(long)1,(100)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(surname),(long)100,(long)1,(100)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 67 "zad3.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;
#line 67 "zad3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 67 "zad3.pgc"

		printf("%s\t", opis_kursu);
 		printf("%s %s\n", name, surname);
	}
	
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cur_uczestnik", ECPGt_EOIT, ECPGt_EORT);
#line 72 "zad3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 72 "zad3.pgc"


	{ ECPGdisconnect(__LINE__, "ALL");
#line 74 "zad3.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 74 "zad3.pgc"


return 0;
}