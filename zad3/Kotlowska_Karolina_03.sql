


CREATE TABLE lab03.wykladowca (
                id_wykladowca INTEGER NOT NULL,
                nazwisko VARCHAR(50),
                imie VARCHAR(50),
                CONSTRAINT wykladowca_pkey PRIMARY KEY (id_wykladowca)
);


CREATE TABLE lab03.uczestnik (
                id_uczestnik INTEGER NOT NULL,
                nazwisko VARCHAR(50),
                imie VARCHAR(50),
                CONSTRAINT uczestnik_pkey PRIMARY KEY (id_uczestnik)
);


CREATE TABLE lab03.kurs_opis (
                id_kurs INTEGER NOT NULL,
                opis VARCHAR(50),
                CONSTRAINT kurs_opis_pkey PRIMARY KEY (id_kurs)
);


CREATE TABLE lab03.kurs (
                id_kurs INTEGER NOT NULL,
                id_grupa INTEGER,
                id_nazwa INTEGER,
                termin VARCHAR NOT NULL,
                CONSTRAINT kurs_pkey PRIMARY KEY (id_kurs)
);


CREATE TABLE lab03.wykl_kurs (
                id_wykl INTEGER NOT NULL,
                id_kurs INTEGER NOT NULL,
                CONSTRAINT wykl_kurs_pkey PRIMARY KEY (id_wykl, id_kurs)
);


CREATE TABLE lab03.uczest_kurs (
                id_uczest INTEGER NOT NULL,
                id_kurs INTEGER NOT NULL,
                CONSTRAINT uczest_kurs_pkey PRIMARY KEY (id_uczest, id_kurs)
);


ALTER TABLE lab03.wykl_kurs ADD CONSTRAINT wykl_kurs_id_wykl_fkey
FOREIGN KEY (id_wykl)
REFERENCES lab03.wykladowca (id_wykladowca)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE lab03.uczest_kurs ADD CONSTRAINT uczest_kurs_id_uczest_fkey
FOREIGN KEY (id_uczest)
REFERENCES lab03.uczestnik (id_uczestnik)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE lab03.kurs ADD CONSTRAINT kurs_id_nazwa_fkey
FOREIGN KEY (id_nazwa)
REFERENCES lab03.kurs_opis (id_kurs)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE lab03.uczest_kurs ADD CONSTRAINT uczest_kurs_id_kurs_fkey
FOREIGN KEY (id_kurs)
REFERENCES lab03.kurs (id_kurs)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE lab03.wykl_kurs ADD CONSTRAINT wykl_kurs_id_kurs_fkey
FOREIGN KEY (id_kurs)
REFERENCES lab03.kurs (id_kurs)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;


insert into lab03.uczestnik ( id_uczestnik, nazwisko, imie ) values 
( 1, 'Flisikowski', 'Jan'),
( 2, 'Olech', 'Andrzej'       ),
( 3, 'Płochocki', 'Piotr'    ),
( 4, 'Stachyra', 'Krzysztof' ),
( 5, 'Sztuka', 'Stanisław'   ),
( 6, 'Sosin', 'Tomasz'       ),
( 7, 'Głowala', 'Paweł'      ),
( 8, 'Straszewski', 'Józef'  ),
( 9, 'Dwojak', 'Marcin'      ),
(10, 'Kotulski', 'Marek'    ),
(11, 'Łaski', 'Michał'       ),
(12, 'Iwanowicz', 'Grzegorz' ),
(13, 'Barnaś', 'Jerzy'       ),
(14, 'Stachera', 'Tadeusz'   ),
(15, 'Gzik', 'Adam'          ),
(16, 'Całus', 'Łukasz'       ),
(17, 'Kołodziejek', 'Zbigniew'),
(18, 'Bukowiecki', 'Ryszard' ),
(19, 'Sielicki', 'Dariusz'   ),
(20, 'Radziszewski', 'Henryk'),
(21, 'Szcześniak', 'Mariusz' ),
(22, 'Nawara', 'Kazimierz'   ),
(23, 'Kęski', 'Wojciech'     ),
(24, 'Rafalski', 'Robert'    ),
(25, 'Hołownia', 'Mateusz'   ),
(26, 'Niedziałek', 'Marian'  ),
(27, 'Matuszczak', 'Rafał'   ),
(28, 'Wolf', 'Jacek'         ),
(29, 'Kolczyński', 'Janusz'  ),
(30, 'Chrobok', 'Mirosław'   )  ;
--
-- wstawienie danych - tabela kurs_opis
insert into lab03.kurs_opis ( id_kurs, opis ) values
( 1, 'JÄ™zyk angielski, stopieĹ„ 1'),
( 2, 'JÄ™zyk angielski, stopieĹ„ 2'),
( 3, 'JÄ™zyk angielski, stopieĹ„ 3'), 
( 4, 'JÄ™zyk angielski, stopieĹ„ 4'),
( 5, 'JÄ™zyk angielski, stopieĹ„ 5'),
( 6, 'JÄ™zyk niemiecki, stopieĹ„ 1'),
( 7, 'JÄ™zyk niemiecki, stopieĹ„ 2'),
( 8, 'JÄ™zyk niemiecki, stopieĹ„ 3'),
( 9, 'JÄ™zyk niemiecki, stopieĹ„ 4'),
(10, 'JÄ™zyk hiszpaĹ„ski, stopieĹ„ 1'),
(11, 'JÄ™zyk hiszpaĹ„ski, stopieĹ„ 2'),
(12, 'JÄ™zyk hiszpaĹ„ski, stopieĹ„ 3') ;
--
-- wstawienie danych - tabela wykladowca
insert into lab03.wykladowca ( id_wykladowca, imie, nazwisko ) values 
( 1, 'Marcin','Szymczak'),
( 2, 'Joanna','Baranowska'),
( 3, 'Maciej','SzczepaĹ„ski'),
( 4, 'CzesĹ‚aw','WrĂłbel'),
( 5, 'GraĹĽyna','GĂłrska'),
( 6, 'Wanda','Krawczyk'),
( 7, 'Renata','UrbaĹ„ska'),
( 8, 'WiesĹ‚awa','Tomaszewska'),
( 9, 'BoĹĽena','Baranowska'),
(10, 'Ewelina','Malinowska'),
(11, 'Anna','Krajewska'),
(12, 'MieczysĹ‚aw','ZajÄ…c'),
(13, 'WiesĹ‚aw','Przybylski'),
(14, 'Dorota','Tomaszewska'),
(15, 'Jerzy','WrĂłblewski') ;
--
-- wstawienie danych - tabela kurs
insert into lab03.kurs ( id_kurs, id_grupa, id_nazwa, termin ) values
( 1, 1, 1, '1.01.2021-31.03.2021'),
( 2, 2, 1, '1.01.2021-31.03.2021'),
( 3, 1, 2, '1.04.2021-30.06.2021'),
( 4, 1, 3, '1.08.2021-10.10.2021'),
( 5, 1, 4, '1.11.2021-23.12.2021'),
( 6, 1, 6, '1.01.2021-31.03.2021'),
( 7, 2, 6, '1.01.2021-31.03.2021'),
( 8, 1, 7, '1.04.2021-30.06.2021'),
( 9, 1, 8, '1.07.2021-31.07.2021'),
(10, 1, 10, '1.02.2021-31.05.2021'),
(11, 1, 11, '1.09.2021-30.11.2021') ; 
--
-- wstawienie danych - tabela wykl_kurs - wykladowcy na kursach
insert into lab03.wykl_kurs ( id_kurs, id_wykl ) values
( 1, 1 ),
( 2, 2 ),
( 3, 1 ),
( 4, 1 ),
( 5, 3 ),
( 6, 4 ),
( 7, 5 ),
( 8, 4 ),
( 9, 4 ),
(10, 11 ),
(11, 11 ) ; 
--
-- wstawienie danych - tabela uczest_kurs - uczestnicy na kursach
insert into lab03.uczest_kurs ( id_kurs, id_uczest ) values
-- kurs 1 - angielski 1 gr 1
( 1, 1 ),
( 1, 3 ),
( 1, 5 ),
( 1, 7 ),
( 1, 8 ),
( 1, 10 ),
( 1, 11 ),
( 1, 12 ),
-- kurs 2 - angielski 1 gr 2
( 2, 2 ),
( 2, 16 ),
( 2, 17 ),
( 2, 18 ),
( 2, 20 ),
-- kurs 3 - angielski 2 gr 1
( 3, 1 ),
( 3, 2 ),
( 3, 3 ),
( 3, 5 ),
( 3, 7 ),
( 3, 17 ),
( 3, 18 ),
( 3, 20 ),
-- kurs 4 - angielski 3 gr 1
( 4, 1 ),
( 4, 2 ),
( 4, 3 ),
( 4, 5 ),
( 4, 21 ),
( 4, 22 ),
( 4, 25 ),
-- kurs 5 - angielski 4 gr 1
( 5, 1 ),
( 5, 2 ),
( 5, 3 ),
( 5, 5 ),
( 5, 21 ),
( 5, 22 ),
-- kurs 6 - niemiecki 1 gr 1
( 6, 8 ),
( 6, 9 ),
( 6, 13 ),
( 6, 15 ),
( 6, 19 ),
( 6, 24 ),
( 6, 27 ),
-- kurs 7 - niemiecki 1 gr 2
( 7, 11 ),
( 7, 17 ),
( 7, 18 ),
( 7, 23 ),
( 7, 25 ),
( 7, 28 ),
( 7, 30 ),
-- kurs 8 - niemiecki 2 gr 1
( 8, 8 ),
( 8, 9 ),
( 8, 13 ),
( 8, 15 ),
( 8, 19 ),
( 8, 24 ),
( 8, 27 ),
-- kurs 9 - niemiecki 3 gr 1
( 9, 8 ),
( 9, 9 ),
( 9, 13 ),
( 9, 24 ),
( 9, 27 ),
-- kurs 10 - hiszpanski 1 gr 1
(10, 6 ),
(10, 16 ),
(10, 18 ),
(10, 22 ),
(10, 24 ),
(10, 29 ),
(10, 30 ),
-- kurs 11 - hiszpanski 2 gr 1
(11, 6 ),
(11, 16 ),
(11, 18 ),
(11, 22 ),
(11, 24 ),
(11, 29 ),
(11, 30 ) ;



ALTER TABLE lab03.kurs ADD COLUMN data_rozpoczecia DATE DEFAULT '2008-11-11' NOT NULL;
ALTER TABLE lab03.kurs ADD COLUMN data_zakonczenia DATE DEFAULT '2008-11-11' NOT NULL;

UPDATE lab03.kurs SET data_rozpoczecia = to_date(left(termin,9),'DD-MM-YYYY');
UPDATE lab03.kurs SET data_zakonczenia = to_date(right(termin,10),'DD-MM-YYYY');

ALTER TABLE lab03.kurs DROP COLUMN termin;



ALTER TABLE lab03.uczestnik ADD COLUMN "kod_pocztowy" VARCHAR(6) DEFAULT '00-000' NOT NULL;
ALTER TABLE lab03.uczestnik ADD COLUMN "adres" VARCHAR(50) DEFAULT 'no adress' NOT NULL;
ALTER TABLE lab03.uczestnik ADD COLUMN "miejscowosc" VARCHAR(50) DEFAULT 'no city' NOT NULL;

CREATE TABLE lab03.address (
                "kod_pocztowy" VARCHAR(6) DEFAULT '00-000' NOT NULL,
                "adres" VARCHAR(80) DEFAULT 'null street 0' NOT NULL,
                "miejscowosc" VARCHAR(80) DEFAULT 'null island' NOT NULL
);

ALTER TABLE lab03.address ADD COLUMN "id_uczestnik" INTEGER NOT NULL;

ALTER TABLE lab03.address ADD CONSTRAINT "uczestnik_address_fk"
FOREIGN KEY ("id_uczestnik")
REFERENCES lab03.uczestnik ("id_uczestnik")
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

INSERT INTO lab03.address (id_uczestnik, kod_pocztowy, adres, miejscowosc) VALUES
(1, '23-555', 'Mazowiecka 3', 'Warszawa'),
(2, '23-555', 'Mazowiecka 35', 'Kraków'),
(3, '23-555', 'Mazowiecka 32', 'Warszawa'),
(4, '23-555', 'Krakowska 1', 'Kraków'),
(5, '44-888', 'Wroclawska 84', 'Warszawa'),
(6, '14-888', 'Wroclawska 85', 'Kraków'),
(7, '24-888', 'Wroclawska 87', 'Warszawa'),
(8, '24-888', 'Wroclawska 87', 'Warszawa'),
(9, '12-333', 'Wroclawska 89', 'Warszawa'),
(10, '22-333', 'Wroclawska 80', 'Kraków'),
(11, '22-333', 'Poznanska 12', 'Warszawa'),
(12, '22-333', 'Zakopianska 1', 'Kraków'),
(13, '22-333', 'Zakopianska 54', 'Warszawa'),
(14, '22-333', 'Zakopianska 34', 'Kraków'),
(15, '11-333', 'Zakopianska 2', 'Warszawa'),
(16, '11-333', 'Zakopianska 78', 'Kraków'),
(17, '11-333', 'Zakopianska 72', 'Warszawa'),
(18, '11-333', 'Wroclawska 8', 'Kraków'),
(19, '55-666', 'Wroclawska 122', 'Kraków'),
(20, '55-666', 'Wroclawska 67', 'Warszawa'),
(21, '55-666', 'Wroclawska 87', 'Kraków'),
(22, '44-888', 'Wroclawska 34', 'Kraków'),
(23, '55-666', 'Wroclawska 66', 'Kraków'),
(24, '55-666', 'Wroclawska 9', 'Kraków'),
(25, '55-666', 'Krakowska 1', 'Warszawa'),
(26, '55-666', 'Krakowska 12', 'Kraków'),
(27, '35-664', 'Krakowska 11', 'Kraków'),
(28, '44-399', 'Krakowska 19', 'Warszawa'),
(29, '44-399', 'Krakowska 33', 'Kraków'),
(30, '44-399', 'Krakowska 23', 'Warszawa');

UPDATE lab03.uczestnik SET (kod_pocztowy, adres, miejscowosc) = (address.kod_pocztowy, address.adres, address.miejscowosc) FROM lab03.address WHERE uczestnik.id_uczestnik = address.id_uczestnik;

DROP TABLE lab03.address;

SELECT Uczestnik.nazwisko, Uczestnik.imie, Uczestnik.adres, Uczestnik.kod_pocztowy, Uczestnik.miejscowosc, Kurs_opis.opis, Kurs.id_kurs, Kurs.id_grupa
FROM lab03.Kurs, lab03.uczest_kurs, lab03.Uczestnik, lab03.Kurs_opis
WHERE Kurs.id_kurs = uczest_kurs.id_kurs and  

      Uczestnik.id_uczestnik = uczest_kurs.id_uczest and

      Kurs.id_kurs = Kurs_opis.id_kurs ;
