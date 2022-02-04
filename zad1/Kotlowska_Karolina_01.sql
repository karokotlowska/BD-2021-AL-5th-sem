
CREATE TABLE public.Wykladowca (
                id_wykladowca INTEGER NOT NULL,
                nazwisko VARCHAR NOT NULL,
                imie VARCHAR NOT NULL,
                CONSTRAINT wykladowca_id PRIMARY KEY (id_wykladowca)
);


CREATE TABLE public.Kurs_opis (
                id_kurs INTEGER NOT NULL,
                opis_varchar INTEGER NOT NULL,
                CONSTRAINT kurs_opis_id PRIMARY KEY (id_kurs)
);


CREATE TABLE public.Kurs (
                id_kurs INTEGER NOT NULL,
                id_grupa INTEGER NOT NULL,
                id_kurs_nazwa INTEGER NOT NULL,
                CONSTRAINT kurs_id PRIMARY KEY (id_kurs, id_grupa)
);


CREATE TABLE public.wykl_kurs (
                id_wykladowca INTEGER NOT NULL,
                id_grupa INTEGER NOT NULL,
                id_kurs INTEGER NOT NULL
);


CREATE TABLE public.Uczestnik (
                id_uczestnik INTEGER NOT NULL,
                imie VARCHAR NOT NULL,
                nazwisko VARCHAR NOT NULL,
                CONSTRAINT uczestnik_id PRIMARY KEY (id_uczestnik)
);


CREATE TABLE public.uczest_kurs (
                id_kurs INTEGER NOT NULL,
                id_grupa INTEGER NOT NULL,
                id_uczestnik INTEGER NOT NULL
);


ALTER TABLE public.wykl_kurs ADD CONSTRAINT wykladowca_wykl_kurs_fk
FOREIGN KEY (id_wykladowca)
REFERENCES public.Wykladowca (id_wykladowca)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.Kurs ADD CONSTRAINT kurs_opis_kurs_fk
FOREIGN KEY (id_kurs)
REFERENCES public.Kurs_opis (id_kurs)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.wykl_kurs ADD CONSTRAINT kurs_wykl_kurs_fk
FOREIGN KEY (id_kurs, id_grupa)
REFERENCES public.Kurs (id_kurs, id_grupa)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.uczest_kurs ADD CONSTRAINT kurs_uczest_kurs_fk
FOREIGN KEY (id_kurs, id_grupa)
REFERENCES public.Kurs (id_kurs, id_grupa)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.uczest_kurs ADD CONSTRAINT uczestnik_uczest_kurs_fk
FOREIGN KEY (id_uczestnik)
REFERENCES public.Uczestnik (id_uczestnik)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;
