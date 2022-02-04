import java.sql.*;
public class zad4 {
  public static void main(String[] argv) {
  /*
  System.out.println("Sprawdzenie czy sterownik jest zarejestrowany w menadzerze");
  try {
    Class.forName("org.postgresql.Driver");
  } catch (ClassNotFoundException cnfe) {
    System.out.println("Nie znaleziono sterownika!");
    System.out.println("Wyduk sledzenia bledu i zakonczenie.");
    cnfe.printStackTrace();
    System.exit(1);
  }
  System.out.println("Zarejstrowano sterownik - OK, kolejny krok nawiazanie polaczenia z baza danych.");
  */
  Connection c = null;
  
  try {
    // Wymagane parametry polaczenia z baza danych:
    // Pierwszy - URL do bazy danych:
    //        jdbc:dialekt SQL:serwer(adres + port)/baza w naszym przypadku:
    //        jdbc:postgres://pascal.fis.agh.edu.pl:5432/baza
    // Drugi i trzeci parametr: uzytkownik bazy i haslo do bazy 
     c = DriverManager.getConnection("jdbc:postgresql://pascal.fis.agh.edu.pl:5432/u9kotlowska",
                                    "u9kotlowska", "9kotlowska");
  } catch (SQLException se) {
    System.out.println("Brak polaczenia z baza danych, wydruk logu sledzenia i koniec.");
    se.printStackTrace();
    System.exit(1);
  }
if (c != null) {
    System.out.println("Polaczenie z baza danych OK ! ");
    try { 
      //  Wstawianie rekordow do bazy danych
      //  Wykorzystanie metody executeUpdate()                                             
       PreparedStatement pst = c.prepareStatement( "UPDATE lab04.uczestnik SET email=? WHERE id_uczestnik=?" );
       pst.setInt(2,17);
       pst.setString(1,"email@email.pl") ;

       int rows ;
       rows = pst.executeUpdate();
       System.out.print("Polecenie 1 -  UPDATE - ilosc dodanych rekordow: ") ; 
       System.out.println(rows) ;   

       pst.setInt(2,18);
       pst.setString(1,"wp@wp.pl") ;
       rows = pst.executeUpdate();
       System.out.print("Polecenie 2 -  UPDATE - ilosc dodanych rekordow: ") ;
       System.out.println(rows) ;
       
       pst.close();    
     }
     catch(SQLException e)  {
	     System.out.println("Blad podczas przetwarzania danych:"+e) ;   }	       
 
 }
  else
    System.out.println("Brak polaczenia z baza, dalsza czesc aplikacji nie jest wykonywana.");   }
} 

