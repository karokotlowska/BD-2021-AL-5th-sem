--1. Utworzyć funkcję,  która dostarcza listę z nazwiskami, imionami i adresem email uczestników dla organizacji. Identyfikator organizacji jest argumentem funkcji.

CREATE OR REPLACE FUNCTION zad1 (identyf INT)
RETURNS TABLE(nazwisko VARCHAR, imie VARCHAR, email VARCHAR)  AS 
$body$
    SELECT nazwisko, imie, email
    FROM lab04.uczestnik ucz
    JOIN lab04.uczestnik_organizacja UO on ucz.id_uczestnik = uo.id_uczestnik
    WHERE uo.id_organizacja = identyf;
$body$
LANGUAGE sql;

SELECT * FROM zad1(1);
SELECT * FROM zad1(2);



--2. Utworzyć funkcję,  która dostarcza ilość studentów dla kursów danego języka. Nazwa języka jest argumentem funkcji.

CREATE OR REPLACE FUNCTION zad2(jezyk VARCHAR) RETURNS  INT AS 
$body$
DECLARE
c INT:=0;
BEGIN
SELECT COUNT(id_uczest) INTO c FROM lab04.uczest_kurs AS uk JOIN lab04.kurs_opis AS ko USING (id_kurs) 
WHERE ko.opis LIKE '%'||jezyk||'%' ;
RETURN c;
END
$body$
LANGUAGE plpgsql;

SELECT * FROM zad2('niemiecki');
SELECT * FROM zad2('angielski');



--3. Utworzyć funkcję,  która dostarcza listę wykładowców prowadzących kursy dla zadanej organizacji. 




