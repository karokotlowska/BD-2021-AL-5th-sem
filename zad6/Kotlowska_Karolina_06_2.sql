--1.Lista z nazwiskami i imionami uczestników z kolumną o wartościach ('duża', 'średnia', 'mała', 'brak'). Wartości tej kolumny zależne od kolumny obecnosc.('duża', 'średnia', 'mała', 'brak'). Wartości tej kolumny zależne od kolumny obecnosc

WITH obCTE AS(
SELECT u.id_uczestnik, nazwisko, imie, COUNT(a.obecnosc) AS ob
FROM lab04.aktywnosc a
JOIN lab04.uczestnik u USING(id_uczestnik)
WHERE obecnosc >=1
GROUP BY u.id_uczestnik, nazwisko, imie
), 
sumCTE AS(SELECT u.id_uczestnik, nazwisko, imie, SUM(a.obecnosc) AS sum
FROM lab04.aktywnosc a
JOIN lab04.uczestnik u USING(id_uczestnik)
WHERE obecnosc >=1
GROUP BY u.id_uczestnik, nazwisko, imie)

SELECT uczestnik.id_uczestnik, lab04.uczestnik.nazwisko, 
        CASE
        WHEN (ob::FLOAT)/(sum::FLOAT)>=0.9 THEN 'duza'
		WHEN  (ob::FLOAT)/(sum::FLOAT)>= 0.5 and  (ob::FLOAT)/(sum::FLOAT) < 0.9 THEN 'srednia'
		WHEN  (ob::FLOAT)/(sum::FLOAT)>= 0.0 and   (ob::FLOAT)/(sum::FLOAT) < 0.5 THEN 'mala'
		ELSE 'brak'
        END AS obecnosc
FROM lab04.uczestnik 
LEFT JOIN obCTE ON uczestnik.id_uczestnik=obCTE.id_uczestnik
LEFT JOIN sumCTE on uczestnik.id_uczestnik=sumCTE.id_uczestnik
ORDER BY 2;


--2. Lista z nazwiskami i imionami wykładowców z kolumną o wartościach ('poniżej limitu', 'limit', 'powyżej limitu' ) Wartości tej kolumny zależne od ilości uczestników na kursach danego wykładowcy.
WITH wyklCTE AS(
SELECT id_wykladowca, nazwisko, imie, id_kurs
FROM lab04.wykladowca
LEFT OUTER JOIN lab04.wykl_kurs ON wykladowca.id_wykladowca=wykl_kurs.id_wykl
LEFT OUTER JOIN lab04.kurs USING(id_kurs)
ORDER BY id_kurs
)
SELECT nazwisko, imie,
  CASE
        WHEN COUNT(*) >=20 THEN 'powyzej limitu'
        WHEN  COUNT(*) >= 10 and  COUNT(*)  < 20 THEN 'limit'
        ELSE 'ponizej limitu'
        END AS l_uczestnikow
FROM lab04.uczest_kurs RIGHT OUTER JOIN wyklCTE ON uczest_kurs.id_kurs=wyklCTE.id_kurs
GROUP BY nazwisko, imie;


--3. Korzystając z CTE pokazać średnią ilość uczestników na kursie. Nie korzystamy z agregatu AVG.
WITH ucz AS(
SELECT id_kurs, COUNT(*) as uczest
FROM lab04.uczest_kurs
GROUP BY id_kurs
ORDER BY id_kurs
)
SELECT SUM(uczest)/COUNT(*) AS srednia
FROM ucz;






   


















