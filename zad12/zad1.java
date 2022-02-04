import java.sql.*;
public class zad1 {
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
      //  Wykonanie zapytania SELECT do bazy danych
      //  Wykorzystane elementy: prepareStatement(), executeQuery()
       PreparedStatement pst = c.prepareStatement("SELECT kurs.id_nazwa, imie, nazwisko, opis FROM lab04.uczestnik JOIN lab04.uczest_kurs ON uczestnik.id_uczestnik=uczest_kurs.id_uczest JOIN lab04.kurs ON uczest_kurs.id_kurs=kurs.id_kurs JOIN lab04.kurs_opis ON kurs.id_nazwa=kurs_opis.id_kurs ORDER BY kurs_opis.id_kurs, nazwisko, imie", ResultSet.TYPE_SCROLL_SENSITIVE,ResultSet.CONCUR_UPDATABLE);
       ResultSet rs = pst.executeQuery();
       while (rs.next())  {
            //String id   = rs.getString(1) ;
            String imie    = rs.getString(2) ;
            String nazwisko    = rs.getString(3) ;
        String opis    = rs.getString(4) ;
            System.out.print("Zwrocone kolumny  ");
            System.out.println(imie+" "+nazwisko+" "+opis) ;   }
       rs.close();
       pst.close();    }
     catch(SQLException e)  {
	     System.out.println("Blad podczas przetwarzania danych:"+e) ;   }	     
 
 }
  else
    System.out.println("Brak polaczenia z baza, dalsza czesc aplikacji nie jest wykonywana.");   }
} 

