/* Processed by ecpg (13.4 (Debian 13.4-1.pgdg90+1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "zad3.pgc"
#include <stdio.h>

char * p_dbase = "u9miszczak@localhost:5432";	//"tcp:postgresql://localhost:5432/DB1_lab02";
char * p_user = "u9miszczak";
char * p_pass = "9miszczak";

/* exec sql begin declare section */
	 
	 
	 
	 

	 
	 
	 

#line 8 "zad3.pgc"
 char dbname [ 1024 ] ;
 
#line 9 "zad3.pgc"
 char connection_string [ 128 ] ;
 
#line 10 "zad3.pgc"
 char user [ 64 ] ;
 
#line 11 "zad3.pgc"
 char password [ 32 ] ;
 
#line 13 "zad3.pgc"
 char opis [ 100 ] ;
 
#line 14 "zad3.pgc"
 char fname [ 64 ] ;
 
#line 15 "zad3.pgc"
 char lname [ 64 ] ;
/* exec sql end declare section */
#line 16 "zad3.pgc"


/* exec sql whenever not found  break ; */
#line 18 "zad3.pgc"


int main()
{

	// initialize SQL variable
	strcpy(connection_string,p_dbase);
	strcpy(user,p_user);
	strcpy(password,p_pass);

	/* declare cur_uczestnik cursor for select opis , imie , nazwisko from lab04 . uczestnik join lab04 . uczest_kurs on id_uczestnik = id_uczest join lab04 . kurs using ( id_kurs ) join lab04 . kurs_opis on kurs_opis . id_kurs = kurs . id_nazwa order by opis , nazwisko */
#line 29 "zad3.pgc"



	{ ECPGconnect(__LINE__, 0, connection_string , user , password , "conn", 0); }
#line 32 "zad3.pgc"


	// open a cursor
    	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cur_uczestnik cursor for select opis , imie , nazwisko from lab04 . uczestnik join lab04 . uczest_kurs on id_uczestnik = id_uczest join lab04 . kurs using ( id_kurs ) join lab04 . kurs_opis on kurs_opis . id_kurs = kurs . id_nazwa order by opis , nazwisko", ECPGt_EOIT, ECPGt_EORT);}
#line 35 "zad3.pgc"

 
    	// loop up to end of data
 char tmp[100]="aaa";
	for(;;)
	{
        	// fetch next record
	        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch next from cur_uczestnik", ECPGt_EOIT, 
	ECPGt_char,(opis),(long)100,(long)1,(100)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(lname),(long)64,(long)1,(64)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(fname),(long)64,(long)1,(64)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 42 "zad3.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;}
#line 42 "zad3.pgc"

         if(strcmp(tmp,opis))
         {
           printf("\n   %s\n",opis);
           strcpy(tmp,opis);
         }
         printf("%s %s\n",fname,lname);
	}
 
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cur_uczestnik", ECPGt_EOIT, ECPGt_EORT);}
#line 51 "zad3.pgc"


	
    	
	// close all connection
	{ ECPGdisconnect(__LINE__, "ALL");}
#line 56 "zad3.pgc"

	return 0;
}