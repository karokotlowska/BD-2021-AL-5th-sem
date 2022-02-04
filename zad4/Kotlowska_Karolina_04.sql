---zad1
SELECT ku.id_kurs, u.nazwisko AS "nazwisko ucznia", u.imie AS "imie ucznia", opis, wy.nazwisko AS "nazwisko wykladowcy", wy.imie AS "imie wykladowcy" 
FROM lab04.kurs KU 
JOIN lab04.kurs_opis KO ON ku.id_nazwa = ko.id_kurs
LEFT OUTER JOIN lab04.wykl_kurs WK ON wk.id_kurs = ku.id_kurs
RIGHT OUTER JOIN lab04.wykladowca WY ON WY.id_wykladowca = wk.id_wykl
FULL OUTER JOIN lab04.uczest_kurs UK ON uk.id_kurs = ku.id_kurs
FULL OUTER JOIN lab04.uczestnik U ON u.id_uczestnik = uk.id_uczest
WHERE u.id_uczestnik IS NULL
OR uk.id_uczest IS NULL;


---zad2
SELECT opis, MAX(uk.ocena) AS "maksymalna ocena", MIN(uk.ocena) AS "minimalna ocena"
, AVG(uk.ocena) AS "srednia ocena"
FROM lab04.uczest_kurs UK
JOIN lab04.kurs K ON uk.id_kurs=k.id_kurs
JOIN lab04.kurs_opis KO ON k.id_kurs=ko.id_kurs
GROUP BY ko.id_kurs, ko.opis;

---zad3
SELECT wy.imie, wy.nazwisko, wy.email, COUNT(id_uczestnik) AS "liczba osob" 
FROM lab04.wykladowca WY
JOIN lab04.wykl_kurs ON lab04.wykl_kurs.id_wykl=wy.id_wykladowca
JOIN lab04.kurs ON lab04.wykl_kurs.id_kurs=lab04.kurs.id_kurs
JOIN lab04.uczest_kurs ON lab04.uczest_kurs.id_kurs=lab04.kurs.id_kurs
JOIN lab04.uczestnik ON lab04.uczestnik.id_uczestnik=lab04.uczest_kurs.id_uczest
GROUP BY (wy.id_wykladowca);