--1. Napisać wyzwalacz walidujący fname i lname w tabeli person, tylko litery, bez spacji i tabulatorów. W lname dopuszczalny znak - (myślnik, pauza).

CREATE OR REPLACE FUNCTION lab04.zad1()
RETURNS TRIGGER 
LANGUAGE plpgsql 
AS $$
DECLARE 
    fname TEXT = NEW.fname;
    lname TEXT = NEW.lname;
BEGIN
    fname = regexp_replace(fname,'[^a-zA-Z]',' ','g');
    lname = regexp_replace(lname,'[^a-zA-Z]',' ','g');
IF (CONCAT(NEW.fname,NEW.lname) NOT LIKE CONCAT(fname,lname)) THEN
    RAISE EXCEPTION 'Niepoprawna wartosc fname/lname';
END IF;
RETURN NEW;
END;
$$;


CREATE TRIGGER person_valid
    AFTER INSERT OR UPDATE ON lab04.person
    FOR EACH ROW EXECUTE PROCEDURE lab04.zad1();    


UPDATE lab04.person SET lname = 'EEE' WHERE fname = 'Ant';
SELECT * FROM lab04.person;
DROP TRIGGER person_valid ON lab04.person;
DROP FUNCTION lab04.zad1() CASCADE;
UPDATE lab04.person SET lname = 'AAA' WHERE fname = 'Ant';





--2. Napisać wyzwalacz normalizujący fname i lname w tabeli person, fname i skladowe lname ( przy podwójnym nazwisku) powinny zaczynać się od dużej litery, reszta małe. Usuwamy spacje.

CREATE OR REPLACE FUNCTION lab04.zad2 () RETURNS TRIGGER AS $$
BEGIN
	IF LENGTH(TRIM(NEW.fname)) = 0 OR LENGTH(TRIM(NEW.lname)) = 0 THEN
        RAISE EXCEPTION 'Brak wartości fname/lname.';
    END IF;
     NEW.fname := upper(substring(NEW.fname from 1 for 1)) || lower(substring(NEW.fname from 2 for length(NEW.fname)));
        NEW.lname := upper(substring(NEW.lname from 1 for 1)) || lower(substring(NEW.lname from 2 for length(NEW.lname)));
  RETURN NEW;
END;
$$ 
LANGUAGE 'plpgsql';

CREATE TRIGGER person_norma
    AFTER INSERT OR UPDATE ON lab04.person
    FOR EACH ROW EXECUTE PROCEDURE lab04.zad2();    
    
INSERT INTO lab04.person (lname, fname, primary_group, secondary_group ) VALUES ( 'Dyd', 'Ant', 'P', 'WY' ); 
UPDATE lab04.person SET lname = 'aaaBC' WHERE fname = 'Ant';
SELECT * FROM lab04.person;
DELETE FROM lab04.person WHERE fname = 'Ant';
DROP TRIGGER person_norma ON lab04.person;
DROP FUNCTION lab04.zad2() CASCADE;    
  
    
    
--3. Napisać wyzwalacz aktualizujący tabelę zawierającą liczbę wszystkich osób w danej grupie. Uwzględnić insert, delete i update.

CREATE TABLE IF NOT EXISTS lab04.grupy(grupa VARCHAR, ilosc_osob INT);
INSERT INTO lab04.grupy(grupa, ilosc_osob) VALUES ('G1', 0),('G2', 0),('G3', 0),('G4', 0);

CREATE OR REPLACE FUNCTION lab04.zad3()
RETURNS TRIGGER 
LANGUAGE plpgsql
AS $$
BEGIN
  DELETE FROM lab04.grupy;
  INSERT INTO lab04.grupy 
  SELECT * FROM(SELECT p.primary_group AS PG, COUNT(p.person_id) FROM lab04.person AS P GROUP BY p.primary_group ) AS FOO;

RETURN NEW;
END;
$$;

DROP TRIGGER IF EXISTS zad3 ON lab04.person;

CREATE TRIGGER zad3 
	BEFORE INSERT OR UPDATE OR DELETE ON lab04.person
	FOR EACH ROW EXECUTE PROCEDURE lab04.zad3();

INSERT INTO lab04.person (lname, fname, primary_group, secondary_group ) VALUES ( 'Test', 'test', 'a', 'b' );  
UPDATE lab04.person SET primary_group = 'G1' WHERE fname = 'And';
DELETE FROM lab04.person WHERE fname = 'And';
SELECT * FROM lab04.grupy;
DROP FUNCTION lab04.zad3() CASCADE;  

    
    

