/* Processed by ecpg (13.4 (Debian 13.4-1.pgdg90+1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "zad1.pgc"
#include <stdio.h>
#include "lab09.h"
//dane do logowania znajduja sie w bilbiotece w celach bezpieczenstwa 
//program dziala poprawnie 
/* exec sql begin declare section */
     
     
     
     
     
     

#line 6 "zad1.pgc"
 char dbname [ 1024 ] ;
 
#line 7 "zad1.pgc"
 char db [ 100 ] ;
 
#line 8 "zad1.pgc"
 char usr [ 100 ] ;
 
#line 9 "zad1.pgc"
 char pas [ 100 ] ;
 
#line 10 "zad1.pgc"
 char us [ 100 ] ;
 
#line 11 "zad1.pgc"
 int port ;
/* exec sql end declare section */
#line 12 "zad1.pgc"


int main()
{
	
    strcpy(db,p_dbase);
    strcpy(usr,p_user);
    strcpy(pas,p_pass);
    { ECPGconnect(__LINE__, 0, db , usr , pas , "conn", 0); }
#line 20 "zad1.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_database ( )", ECPGt_EOIT, 
	ECPGt_char,(dbname),(long)1024,(long)1,(1024)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 22 "zad1.pgc"

    printf("current database = %s \n", dbname);
    
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_user", ECPGt_EOIT, 
	ECPGt_char,(us),(long)100,(long)1,(100)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 25 "zad1.pgc"

    printf("current user = %s\n",us);

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select inet_server_port ( )", ECPGt_EOIT, 
	ECPGt_int,&(port),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 28 "zad1.pgc"

    printf("current port = %d\n",port); 	

    { ECPGdisconnect(__LINE__, "ALL");}
#line 31 "zad1.pgc"

    return 0;
}
