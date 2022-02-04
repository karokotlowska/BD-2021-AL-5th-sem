import java.sql.*;
public class zad6 {
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
    
       Statement stmt = c.createStatement();
       stmt.execute("CREATE OR REPLACE FUNCTION lab04.get_table() RETURNS TABLE (id INT, nazwisko VARCHAR, imie VARCHAR)  AS $body$ SELECT id_uczestnik, imie, nazwisko FROM lab04.uczestnik ORDER BY id_uczestnik ; $body$ language sql;");
       stmt.close();
       //c.setAutoCommit(false) ;
       CallableStatement cst = c.prepareCall( "{ call lab04.get_table() }" );
       cst.execute() ;
       ResultSet rs = cst.executeQuery();
       int i=0;
       while (rs.next())  {
            i++;
            String imie    = rs.getString(2) ;
            String nazwisko    = rs.getString(3) ;
            System.out.print("Pytanie "+i+" - wynik:  ");
            System.out.println(nazwisko + " " + imie) ;   }
       rs.close(); 
          
       cst.close();    
     }
     catch(SQLException e)  {
	     System.out.println("Blad podczas przetwarzania danych:"+e) ;   }	     
 
 }
  else
    System.out.println("Brak polaczenia z baza, dalsza czesc aplikacji nie jest wykonywana.");   }
} 

