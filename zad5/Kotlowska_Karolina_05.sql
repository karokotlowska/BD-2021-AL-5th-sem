---1.Lista uczestników kursu niemieckiego lub angielskiego.
SELECT nazwisko, imie
FROM lab04.uczestnik U
JOIN lab04.uczest_kurs UK ON uk.id_uczest=U.id_uczestnik
JOIN lab04.kurs K USING (id_kurs)
JOIN lab04.kurs_opis KO USING (id_kurs)
WHERE id_kurs<10
UNION
(
SELECT nazwisko, imie
FROM lab04.uczestnik U
JOIN lab04.uczest_kurs UK ON uk.id_uczest=U.id_uczestnik
JOIN lab04.kurs K USING (id_kurs)
JOIN lab04.kurs_opis KO USING (id_kurs)
WHERE id_kurs>5 AND id_kurs<10
INTERSECT
SELECT nazwisko, imie
FROM lab04.uczestnik U
JOIN lab04.uczest_kurs UK ON uk.id_uczest=U.id_uczestnik
JOIN lab04.kurs K USING (id_kurs)
JOIN lab04.kurs_opis KO USING (id_kurs)
WHERE id_kurs<6
)
ORDER BY nazwisko;


---2.Lista uczestników kursu niemieckiego i angielskiego.
SELECT nazwisko, imie
FROM lab04.uczestnik U
JOIN lab04.uczest_kurs UK ON uk.id_uczest=U.id_uczestnik
JOIN lab04.kurs K USING (id_kurs)
JOIN lab04.kurs_opis KO USING (id_kurs)
WHERE id_kurs<6 
INTERSECT
SELECT nazwisko, imie
FROM lab04.uczestnik U
JOIN lab04.uczest_kurs UK ON uk.id_uczest=U.id_uczestnik
JOIN lab04.kurs K USING (id_kurs)
JOIN lab04.kurs_opis KO USING (id_kurs)
WHERE id_kurs>5 AND id_kurs<10;



---3.Lista uczestników kursu niemieckiego z wyłączeniem uczestników angielskiego.
SELECT nazwisko, imie
FROM lab04.uczestnik U
JOIN lab04.uczest_kurs UK ON uk.id_uczest=U.id_uczestnik
JOIN lab04.kurs K USING (id_kurs)
JOIN lab04.kurs_opis KO USING (id_kurs)
WHERE id_kurs>5 AND id_kurs<10
EXCEPT
SELECT nazwisko, imie
FROM lab04.uczestnik U
JOIN lab04.uczest_kurs UK ON uk.id_uczest=U.id_uczestnik
JOIN lab04.kurs K USING (id_kurs)
JOIN lab04.kurs_opis KO USING (id_kurs)
WHERE id_kurs<6
ORDER BY nazwisko;



---4.Listy kursów dla których suma opłat jest większa od zadanej wartości.
SELECT opis, SUM(oplata)
FROM   lab04.uczest_kurs 
JOIN lab04.kurs USING (id_kurs)
JOIN lab04.kurs_opis USING (id_kurs)
GROUP BY kurs.id_kurs, opis HAVING SUM(oplata)>4631.82;


---5.Lista wykładowców o największej ilości studentów na kursach.
SELECT nazwisko, imie, SUM(liczba) 
FROM (SELECT id_kurs, COUNT(*) AS liczba FROM lab04.uczest_kurs GROUP BY id_kurs) OPL
JOIN lab04.kurs USING (id_kurs)
JOIN lab04.wykl_kurs USING (id_kurs)
JOIN lab04.wykladowca ON id_wykladowca=id_wykl
GROUP BY id_wykladowca
ORDER BY SUM(liczba) DESC
FETCH FIRST 1 ROWS ONLY;

---6.Lista studentów o maksymalnej ocenie dla danej organizacji.
SELECT  u.nazwisko, u.imie, o.nazwa
FROM lab04.uczestnik AS u 
INNER JOIN lab04.uczestnik_organizacja AS uo USING(id_uczestnik)
INNER JOIN lab04.uczest_kurs AS uk ON  u.id_uczestnik=uk.id_uczest
INNER JOIN lab04.organizacja AS o USING (id_organizacja)
INNER JOIN (SELECT o.nazwa, MAX(uk.ocena) AS maxgrade 
FROM lab04.organizacja AS O
INNER JOIN lab04.uczestnik_organizacja AS uo USING(id_organizacja)
INNER JOIN lab04.uczestnik AS U USING (id_uczestnik)
INNER JOIN lab04.uczest_kurs AS UK ON  u.id_uczestnik=uk.id_uczest
GROUP BY o.nazwa) AS OO ON  oo.nazwa= o.nazwa 
GROUP BY u.imie, u.nazwisko, o.nazwa, uk.ocena, oo.maxgrade
HAVING uk.ocena = oo.maxgrade
ORDER BY o.nazwa,u.nazwisko;







