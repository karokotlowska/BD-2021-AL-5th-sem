--1. Utworzyć funkcję,  która dostarcza listę z nazwiskami, imionami i adresem email uczestników dla organizacji. Identyfikator organizacji jest argumentem funkcji.

CREATE OR REPLACE FUNCTION zad1 (identyf INT)
RETURNS TABLE (nazwisko VARCHAR, imie VARCHAR, email VARCHAR) AS 
$body$
BEGIN
    	RETURN QUERY SELECT ucz.nazwisko, ucz.imie, ucz.email
    	FROM lab04.uczestnik ucz
    	JOIN lab04.uczestnik_organizacja UO on ucz.id_uczestnik = uo.id_uczestnik
    	WHERE uo.id_organizacja = identyf;

	IF NOT FOUND THEN
		RAISE EXCEPTION 'BRAK KURSU O IDENTYFIKATORZE %', identyf;
	END IF;
END;

$body$ LANGUAGE plpgsql;



--2. Utworzyć funkcję,  która dostarcza ilość studentów dla kursów danego języka. Nazwa języka jest argumentem funkcji.

CREATE OR REPLACE FUNCTION zad2(jezyk VARCHAR) 
RETURNS  INT AS 
$body$
	DECLARE
		c INT:=0;
	BEGIN
		SELECT COUNT(id_uczest) INTO c 
		FROM lab04.uczest_kurs AS uk 
		JOIN lab04.kurs_opis AS ko USING (id_kurs) 
		WHERE ko.opis LIKE '%'||jezyk||'%' ;

		IF c=0 THEN
			RAISE EXCEPTION 'BRAK KURSU JEZYKOWEGO: %', jezyk;		
		ELSE
			RETURN c;
		END IF;
	END
$body$
LANGUAGE plpgsql;

SELECT * FROM zad2('niemiecki');
SELECT * FROM zad2('angielski');



--3. Utworzyć funkcję,  która dostarcza listę wykładowców prowadzących kursy dla zadanej organizacji. 

CREATE OR REPLACE FUNCTION zad3(organiz VARCHAR) 
RETURNS  TABLE (nazwisko VARCHAR, imie VARCHAR, strona_www VARCHAR) AS 
$body$
BEGIN
	RETURN QUERY SELECT w.nazwisko, w.imie, o.strona_www
	FROM lab04.wykladowca AS w 
	JOIN lab04.uczestnik_organizacja AS ug USING (id_wykladowca) 
	JOIN lab04.organizacja AS o USING (id_organizacja)
	WHERE o.strona_www =organiz;

	IF NOT FOUND THEN
		RAISE EXCEPTION 'BRAK ORGANIZACJI: %', organiz;
	END IF;
END;
$body$
LANGUAGE plpgsql;

SELECT * FROM zad3('www.uj.edu.pl');
SELECT * FROM zad3('www.agh.edu.pl');



--4. Utworzyć funkcję,  która zwraca napis (string) którego zawartością jest lista. Wiersze listy zawierają  opis kursu, 
--data rozpoczęcia, data zakończenia oddzielone średnikami. Każdy wiersz jest umieszczony w nawiasach () i oddzielony przecinkiem.

CREATE OR REPLACE FUNCTION zad4()
RETURNS VARCHAR AS
$body$
	DECLARE
 	kursDane RECORD;
	t VARCHAR :='';
BEGIN
 	FOR kursDane IN (SELECT opis, data_rozpoczecia , data_zakonczenia FROM lab04.kurs_opis JOIN lab04.kurs ON kurs_opis.id_kurs=kurs.id_nazwa )
	LOOP
		t:=t || '(' || kursDane.opis || '; '|| kursDane.data_rozpoczecia || '; ' || kursDane.data_zakonczenia || '), ';
	END LOOP;

	IF NOT FOUND THEN
		RAISE EXCEPTION 'BRAK DANYCH: %', kursDane;
	ELSE
		RETURN t;
	END IF;


END;
$body$ 
LANGUAGE plpgsql;

SELECT * FROM zad4();






