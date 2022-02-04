/* Processed by ecpg (13.4 (Debian 13.4-1.pgdg90+1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "c1.pgc"
#include <stdio.h>
#include "lab09.h"

/* exec sql begin declare section */
         
         
         
         

         
         
         
         
         
         
         

#line 5 "c1.pgc"
 char dbname [ 1024 ] ;
 
#line 6 "c1.pgc"
 char connection_string [ 128 ] ;
 
#line 7 "c1.pgc"
 char user [ 64 ] ;
 
#line 8 "c1.pgc"
 char password [ 32 ] ;
 
#line 10 "c1.pgc"
 char cat [ 64 ] ;
 
#line 11 "c1.pgc"
 char db [ 64 ] ;
 
#line 12 "c1.pgc"
 char qry [ 64 ] ;
 
#line 13 "c1.pgc"
 char sch [ 64 ] ;
 
#line 14 "c1.pgc"
 char usr [ 64 ] ;
 
#line 15 "c1.pgc"
 char time [ 30 ] ;
 
#line 16 "c1.pgc"
 int port ;
/* exec sql end declare section */
#line 17 "c1.pgc"


int main()
{

        strncpy(connection_string,p_dbase, 128);
        strncpy(user,p_user, 64);
        strncpy(password,p_pass , 32);
        
	    { ECPGconnect(__LINE__, 0, connection_string , user , password , "conn", 0); }
#line 26 "c1.pgc"


        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_database ( )", ECPGt_EOIT, 
	ECPGt_char,(db),(long)64,(long)1,(64)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 28 "c1.pgc"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_catalog", ECPGt_EOIT, 
	ECPGt_char,(cat),(long)64,(long)1,(64)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 29 "c1.pgc"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_query ( )", ECPGt_EOIT, 
	ECPGt_char,(qry),(long)64,(long)1,(64)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 30 "c1.pgc"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_user", ECPGt_EOIT, 
	ECPGt_char,(usr),(long)64,(long)1,(64)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 31 "c1.pgc"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_port", ECPGt_EOIT, 
	ECPGt_int,&(port),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 32 "c1.pgc"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select pg_conf_load_time ( )", ECPGt_EOIT, 
	ECPGt_char,(time),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 33 "c1.pgc"

        printf("Current date-time: = %s\n", time);
        printf("Current catalog: = %s \n", cat);
        printf("Current database: = %s \n", db);
        printf("Current query: = %s \n", qry);
        printf("Current user: = %s \n", usr);
        printf("Current port: = %d \n", port); 
        { ECPGdisconnect(__LINE__, "ALL");}
#line 40 "c1.pgc"

        return 0;
}


