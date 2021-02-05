DESCRIBE EMP;

SELECT * FROM emp;

DROP TABLE asignaturas CASCADE CONSTRAINTS ;
DROP TABLE matricula CASCADE CONSTRAINTS;
DROP TABLE clase CASCADE CONSTRAINTS;
DROP TABLE grupos CASCADE CONSTRAINTS;
DROP TABLE profesores CASCADE CONSTRAINTS;
DROP TABLE departamentos CASCADE CONSTRAINTS;
DROP TABLE alumnos CASCADE CONSTRAINTS;
DROP TABLE aulas CASCADE CONSTRAINTS;



CREATE TABLE asignaturas(
cod_asig CHAR(4),
nom_asig VARCHAR2(40) UNIQUE,
creditos NUMBER(4,1),
caracter CHAR(2) CONSTRAINT restr_carac CHECK ( caracter IN ('tr','ob','op','lc')) ,
curso NUMBER CHECK ((curso >= 1) AND (curso <=5)),
PRIMARY KEY (cod_asig)
);




CREATE TABLE aulas(
cod_aula CHAR(4),
capacidad NUMBER CHECK ((capacidad>=0) AND (capacidad<=150)),
PRIMARY KEY (cod_aula)
);





CREATE TABLE alumnos(
DNI CHAR(8),
nom_alum VARCHAR2(35),
fecha_nac DATE,
direccion VARCHAR2(30),
beca VARCHAR2(2),
provincia VARCHAR2(20),
PRIMARY KEY (DNI)
);



CREATE TABLE departamentos(
cod_dep CHAR(4),
nom_dep VARCHAR2(30) UNIQUE,
NRP CHAR(8),
PRIMARY KEY (cod_dep)
);



CREATE TABLE profesores(
NRP CHAR(8),
cod_dep CHAR(4),
nom_prof VARCHAR2(35) NOT NULL,
categoria CHAR(4),
area VARCHAR2(20),
PRIMARY KEY(NRP),
FOREIGN KEY(cod_dep) REFERENCES departamentos(cod_dep)
);

ALTER TABLE departamentos ADD FOREIGN KEY (NRP) REFERENCES profesores(NRP);


CREATE TABLE grupos(
cod_asig CHAR(4),
cod_grup CHAR(4),
tipo CHAR(1) CHECK ( tipo IN ('T','P')),
max_al INT CHECK ((max_al >= 10) AND (max_al <= 150)), 
NRP CHAR(8),
PRIMARY KEY(cod_asig, cod_grup, tipo),
FOREIGN KEY(cod_asig) REFERENCES asignaturas(cod_asig),
FOREIGN KEY(NRP) REFERENCES profesores(NRP)
);


CREATE TABLE clase(
cod_asig CHAR(4),
cod_grup CHAR(4),
tipo CHAR(1),
cod_aula CHAR(4),
dia CHAR(1) CHECK ( dia IN ('L','M','X','J','V')),
hora INT CHECK ((hora >= 1) AND (hora <= 6)), 
PRIMARY KEY (cod_aula, dia, hora),
FOREIGN KEY (cod_asig, cod_grup, tipo) REFERENCES grupos (cod_asig, cod_grup, tipo),
FOREIGN KEY (cod_aula) REFERENCES aulas (cod_aula)
);

CREATE TABLE matricula(
cod_asig CHAR(4),
cod_grup CHAR(4),
tipo CHAR(1),
DNI CHAR(8),
convocatoria NUMBER,
calificacion NUMBER,
PRIMARY KEY (cod_asig,cod_grup,tipo,DNI,convocatoria),
FOREIGN KEY (cod_asig, cod_grup,tipo) REFERENCES grupos (cod_asig, cod_grup, tipo),
FOREIGN KEY (DNI) REFERENCES alumnos (DNI)
);


INSERT INTO asignaturas VALUES ('BD01','Base de datos',9.5,'tr','1');
INSERT INTO asignaturas VALUES ('BD02','Base de datos2',9.5,'tr','1');
INSERT INTO asignaturas VALUES ('PROG','Programacion',6.0,'ob','1');
INSERT INTO asignaturas VALUES ('LM','Lenguajes de marcas',4.5,'op','1');
INSERT INTO asignaturas VALUES ('ED','Entornos de desarrollo',4.0,'op','1');
INSERT INTO asignaturas VALUES ('ELE','Electronica basica',4.0,'tr','1');
INSERT INTO asignaturas VALUES ('PR2','Progrmacion 2',NULL,'tr','1');


INSERT INTO aulas VALUES ('A001',30);
INSERT INTO aulas VALUES ('A002',90);
INSERT INTO aulas VALUES ('A003',50);
INSERT INTO aulas VALUES ('A004',120);
INSERT INTO aulas VALUES ('A005',130);


INSERT INTO alumnos VALUES ('1234567A','Juanito Perez','01-02-1990','Calle Pan','si','Granada');
INSERT INTO alumnos VALUES ('7654321B','Antonio Rodriguez','03-04-1990','Calle Cisne','no','Granada');
INSERT INTO alumnos VALUES ('1357924A','Ana Sanchez','03-05-1990','Calle Mirlo','si','Almeria');
INSERT INTO alumnos VALUES ('9876543A','Sara Jimenez','11-10-1990','Calle Agua','si','Jaen');
INSERT INTO alumnos VALUES ('1254673A','Javier Aguilera','15-11-1990','Calle Tortola','no','Granada');
INSERT INTO alumnos VALUES ('1254800B','Javier Aguilera','25-11-1990','Calle Gorrion','si','Sevilla');


INSERT INTO departamentos VALUES ('ELEC','Electronica',NULL);
INSERT INTO departamentos VALUES ('CCIA','Ciencias de la computacion',NULL);
INSERT INTO departamentos VALUES ('ECON','Economia',NULL);
INSERT INTO departamentos VALUES ('LSIS','Lenguajes y sistemas',NULL);


INSERT INTO profesores VALUES ('51515151',NULL,'Antonio Martinez','TU','Lengua');
INSERT INTO profesores VALUES ('42424242',NULL,'Luis Perez','AS','Tseñal');
INSERT INTO profesores VALUES ('31313131',NULL,'Maria Sanchez','CU','Comput');
INSERT INTO profesores VALUES ('25252525',NULL,'Pedro Jimenez','CE','Electr');
INSERT INTO profesores VALUES ('25252529','ELEC','Pepe Jimenez','AS','Electr');

UPDATE departamentos SET NRP = '25252525' WHERE cod_dep = 'ELEC';
UPDATE departamentos SET NRP = '31313131' WHERE cod_dep = 'CCIA';
UPDATE departamentos SET NRP = '42424242' WHERE cod_dep = 'ECON';
UPDATE departamentos SET NRP = '51515151' WHERE cod_dep = 'LSIS';

UPDATE profesores SET cod_dep = 'ELEC' WHERE NRP = '25252525';
UPDATE profesores SET cod_dep = 'CCIA' WHERE NRP = '31313131';
UPDATE profesores SET cod_dep = 'ECON' WHERE NRP = '42424242';
UPDATE profesores SET cod_dep = 'LSIS' WHERE NRP = '51515151';

INSERT INTO grupos VALUES ('BD01','A','P',30,'42424242');
INSERT INTO grupos VALUES ('BD02','A','P',30,'31313131');
INSERT INTO grupos VALUES ('PROG','A','T',80,'31313131');
INSERT INTO grupos VALUES ('ELE','B','P',60,'25252525');
INSERT INTO grupos VALUES ('LM','C','P',100,'51515151');
INSERT INTO grupos VALUES ('PR2','A','T',80,'31313131');


INSERT INTO clase VALUES ('BD01','A','T','A001','L',2);
INSERT INTO clase VALUES ('PROG','A','T','A003','M',3);
INSERT INTO clase VALUES ('ELE','B','P','A002','L',4);
INSERT INTO clase VALUES ('LM','C','P','A001','X',5);



INSERT INTO matricula VALUES ('BD01','A','T','7654321B',1,8);
INSERT INTO matricula VALUES ('PROG','A','T','1234567A',1,9);
INSERT INTO matricula VALUES ('ELE','B','P','1234567A',1,6);
INSERT INTO matricula VALUES ('LM','C','P','9876543A',1,4);
INSERT INTO matricula VALUES ('LM','C','P','9876543A',2,7);
INSERT INTO matricula VALUES ('ELE','B','P','9876543A',2,7);
INSERT INTO matricula VALUES ('LM','C','P','1254673A',2,7);
INSERT INTO matricula VALUES ('BD01','C','P','1254673A',4);


SELECT * FROM asignaturas;
SELECT * FROM aulas;
SELECT * FROM alumnos;
SELECT * FROM departamentos;
SELECT * FROM profesores;
SELECT * FROM grupos;
SELECT * FROM clase;
SELECT * FROM matricula;

/* Ejercicios consultas */
--7.17
SELECT NRP, nom_prof, categoria FROM profesores;


--7.18
SELECT * FROM aulas;

--7.19
SELECT NRP, nom_prof FROM profesores WHERE categoria='AS';

--7.20 Operadores logicos y de comparacion
SELECT NRP, nom_prof FROM profesores WHERE (categoria <>'AS') AND (area='Comput' OR area='Electr');

--7.21 Operador BETWEEN (Solo SQL)
SELECT * FROM aulas WHERE capacidad BETWEEN 30 AND 50;

--7.22 Operador IN (Solo SQL)
--Version Algebra
SELECT DNI, nom_alum FROM alumnos WHERE (beca='si') AND (provincia='Granada' OR provincia='Jaen');
--Version SQL
SELECT DNI, nom_alum FROM alumnos WHERE (beca='si') AND provincia IN ('Granada','Jaen');


--7.23, 7.24, 7.25, 7.26 Operador LIKE (Solo SQL)
--7.23 Version Algebraica de comparacion de caracteres
SELECT DNI,nom_alum FROM alumnos WHERE nom_alum <'Juan'; 

--7.24 (Uso operador LIKE y Comodin %)
SELECT DNI,nom_alum FROM alumnos WHERE nom_alum LIKE 'J%';

--7.25
SELECT DNI,nom_alum FROM alumnos WHERE nom_alum LIKE '%x%';
SELECT DNI,nom_alum FROM alumnos WHERE nom_alum LIKE '%i%';

--7.26
SELECT DNI,nom_alum FROM alumnos WHERE nom_alum LIKE '_a%';

--7.27 Uso de expresiones aritmeticas en columnas proyectadas
SELECT cod_asig, nom_asig, creditos*12.45 FROM asignaturas;

-- Uso de alias de variable
SELECT cod_asig, nom_asig, creditos*12.45 AS precio FROM asignaturas;

--Uso de columna proyectada para composicon de condiciones logicas de selecciones
SELECT cod_asig, nom_asig, creditos*12.45 AS precio FROM asignaturas WHERE precio >50; 
--Error. Solucion. Realizar una subconsulta, pagina 235

--Solucion a lo anterior: subconsultas en el FROM
SELECT * FROM (SELECT cod_asig, nom_asig, creditos*12.45 AS precio FROM asignaturas) resultado 
WHERE resultado.precio > 50;

--7.28
SELECT cod_asig,nom_asig FROM asignaturas where (creditos>=5 AND creditos <=10);

--7.29 Tratamiento de los valores nulos
SELECT * FROM asignaturas WHERE (creditos IS NOT NULL);
SELECT * FROM asignaturas WHERE (creditos IS NULL);

--7.30 Eliminación de valores duplicados de una columna
SELECT provincia FROM alumnos;
SELECT DISTINCT provincia FROM alumnos;

--7.31 Ordenacion de los resultados
SELECT nom_alum FROM alumnos WHERE beca='si' ORDER BY nom_alum;
-- Orden descendiente
SELECT nom_alum FROM alumnos WHERE beca='si' ORDER BY nom_alum DESC;

--7.32 Ordenacion de los resultados de multiples atributos
SELECT provincia, nom_alum FROM alumnos ORDER BY provincia DESC, nom_alum ASC;

--CONSULTAS SOBRE VARIAS TABLAS
--Ejemplo producto cartesiano: profesores x departamentos
SELECT * FROM profesores, departamentos;

--7.33 
SELECT profesores.cod_dep, nom_prof FROM profesores, departamentos WHERE departamentos.NRP=profesores.NRP;

--7.34
SELECT profesores.NRP, profesores.nom_prof, departamentos.nom_dep FROM profesores,departamentos WHERE profesores.cod_dep=departamentos.cod_dep;


--6.15
SELECT profesores.NRP, profesores.nom_prof, departamentos.nom_dep FROM profesores,departamentos WHERE profesores.cod_dep=departamentos.cod_dep;

--6.16
SELECT alumnos.DNI,nom_alum,matricula.cod_asig FROM alumnos, matricula WHERE (alumnos.DNI=matricula.DNI) AND beca='si' AND cod_asig='ELE';


--6.17
SELECT grupos.NRP, nom_prof FROM profesores,grupos WHERE (profesores.NRP=grupos.NRP) AND (cod_asig='ELE');


--6.18
SELECT cod_asig FROM matricula,alumnos WHERE (alumnos.DNI=matricula.DNI) AND (nom_alum='Juanito Perez');


--6.19
SELECT nom_prof FROM profesores,departamentos WHERE (profesores.cod_dep=departamentos.cod_dep) AND (categoria='TU' OR categoria='CU') AND (nom_dep='Lenguajes y sistemas');

--6.20
SELECT nom_asig FROM matricula,alumnos,asignaturas WHERE (alumnos.DNI=matricula.DNI) AND (matricula.cod_asig=asignaturas.cod_asig) AND (alumnos.nom_alum='Juanito Perez');

--6.21
SELECT nom_prof FROM grupos,profesores,asignaturas WHERE (profesores.NRP=grupos.NRP) AND (grupos.cod_asig=asignaturas.cod_asig) AND (grupos.tipo='P') AND (asignaturas.nom_asig='Base de datos');

--6.22
SELECT alumnos.DNI,nom_alum,nom_asig FROM matricula,alumnos,asignaturas WHERE (alumnos.DNI=matricula.DNI) AND (matricula.cod_asig=asignaturas.cod_asig) AND (alumnos.provincia='Granada') AND (asignaturas.curso='1');


--6.21 Correcion Jaime
SELECT profesores.NRP, profesores.nom_prof FROM profesores,grupos,asignaturas WHERE (grupos.tipo='P') AND (grupos.NRP=profesores.NRP) AND (grupos.cod_asig=asignaturas.cod_asig) AND nom_asig LIKE '%Base de datos%';


--7.36 Ejemplos basicos de subconsultas
--Ejemplo basico de subconsulta en el WHERE
SELECT provincia FROM alumnos WHERE nom_alum='Javier Aguilera';
SELECT DNI,nom_alum FROM alumnos WHERE provincia=(SELECT provincia FROM alumnos WHERE nom_alum='Javier Aguilera');

--7.37 
SELECT p1.NRP FROM profesores p1 WHERE categoria= 
(SELECT categoria FROM profesores p2, departamentos WHERE p2.NRP = departamentos.director AND departamentos.cod_dep=p1.cod_dep);



























