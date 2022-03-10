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

char * p_dbase = "u9kotlowska@localhost:5432";	//"tcp:postgresql://localhost:5432/DB1_lab02";
char * p_user = "u9kotlowska";
char * p_pass = "9kotlowska";

/* exec sql begin declare section */
	 
	 
	 
	 

	 
	 
   

#line 10 "zad2.pgc"
 char dbname [ 1024 ] ;
 
#line 11 "zad2.pgc"
 char connection_string [ 128 ] ;
 
#line 12 "zad2.pgc"
 char user [ 64 ] ;
 
#line 13 "zad2.pgc"
 char password [ 32 ] ;
 
#line 15 "zad2.pgc"
 int id ;
 
#line 16 "zad2.pgc"
 char insertCmd [ 512 ] ;
 
#line 17 "zad2.pgc"
 char mail [ 50 ] ;
/* exec sql end declare section */
#line 18 "zad2.pgc"




// error handlers
/* exec sql whenever sqlerror  call crash ( ) ; */
#line 23 "zad2.pgc"

/* exec sql whenever not found  break ; */
#line 24 "zad2.pgc"

 
static void crash(void)
{
    // stop recursion
    /* exec sql whenever sqlerror  continue ; */
#line 29 "zad2.pgc"

 
    fprintf(
        stderr,
        "database serious error %s:\n%s\n",
        sqlca.sqlstate,
        sqlca.sqlerrm.sqlerrmc
    );
 
    { ECPGtrans(__LINE__, NULL, "rollback");}
#line 38 "zad2.pgc"

    { ECPGdisconnect(__LINE__, "CURRENT");}
#line 39 "zad2.pgc"

 
    exit(1);
 
    // restore the original handler
    /* exec sql whenever sqlerror  call crash ( ) ; */
#line 44 "zad2.pgc"

}

int main()
{

	// initialize SQL variable
	strcpy(connection_string,p_dbase);
	strcpy(user,p_user);
	strcpy(password,p_pass);

  printf("Podaj id uczestnika:");
  scanf("%d",&id );
  printf("Podales: %d\n",id);
  printf("Podaj mail uczestnika:");
  scanf("%s",&mail );
  printf("Podales: %d\n",id);
	{ ECPGconnect(__LINE__, 0, connection_string , user , password , "conn", 0); 
#line 61 "zad2.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 61 "zad2.pgc"

 
  char komenda[100];
  snprintf(komenda, 100, "UPDATE lab04.uczestnik SET email= '%s' WHERE id_uczestnik=%d",mail, id);
  printf("%s\n",komenda);
	strcpy(insertCmd,komenda);

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_exec_immediate, insertCmd, ECPGt_EOIT, ECPGt_EORT);
#line 68 "zad2.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 68 "zad2.pgc"


{ ECPGtrans(__LINE__, NULL, "commit");
#line 70 "zad2.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 70 "zad2.pgc"

	// close all connection
	{ ECPGdisconnect(__LINE__, "ALL");
#line 72 "zad2.pgc"

if (sqlca.sqlcode < 0) crash ( );}
#line 72 "zad2.pgc"

	return 0;
}
