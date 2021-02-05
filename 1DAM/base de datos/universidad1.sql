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
nom_asig VARCHAR2(30) UNIQUE,
creditos NUMBER(4,1),
caracter CHAR(2) CONSTRAINT restr_carac CHECK ( caracter IN ('tr','ob','op','lc')) ,
curso NUMBER CHECK ((curso >= 1) AND (curso <=5)),
PRIMARY KEY (cod_asig)
);

INSERT INTO asignaturas VALUES ('BD01','Base de datos',9.5,'tr','1');
INSERT INTO asignaturas VALUES ('PRO1','Programacion1',6.0,'ob','1');
INSERT INTO asignaturas VALUES ('PRO2','Programacion2',6.0,'jm','2');
SELECT * FROM asignaturas;


CREATE TABLE aulas(
cod_aula CHAR(4),
capacidad NUMBER CHECK ((capacidad>=0) AND (capacidad<=150)),
PRIMARY KEY (cod_aula)
);
INSERT INTO aulas VALUES ('1dam',19);
INSERT INTO aulas VALUES ('2dam',139);
INSERT INTO aulas VALUES ('1inf',149);
SELECT * FROM aulas;

CREATE TABLE alumnos(
DNI CHAR(8),
nom_alum VARCHAR2(35),
fecha_nac DATE,
direccion VARCHAR2(30),
beca VARCHAR2(2),
provincia VARCHAR2(20),
PRIMARY KEY (DNI)
);
INSERT INTO alumnos VALUES ('7654326r','antonio holi',22/11/1997,'grana','si','granada');
INSERT INTO alumnos VALUES ('7654325a','loli palma',21/01/1991,'gabia','no','granada');
INSERT INTO alumnos VALUES ('7654114q','pedro oripo',02/11/1987,'huetor','si','granada');
SELECT * FROM alumnos;
CREATE TABLE departamentos(
cod_dep CHAR(4),
nom_dep VARCHAR2(20) UNIQUE,
NRP CHAR(8),
PRIMARY KEY (cod_dep)
);
INSERT INTO departamentos VALUES ('3210','informatica', '7654321r');
INSERT INTO departamentos VALUES ('1234','formacion', '1234567p');
INSERT INTO departamentos VALUES ('1254','religion','7654111q');
SELECT * FROM departamentos;


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

DESCRIBE profesores;
DESCRIBE departamentos;

INSERT INTO profesores VALUES ('7654321r','3210','antonio albarran','chap','granada');
INSERT INTO profesores VALUES ('7654322a','1111','jaime bustos','alsi','granada');
INSERT INTO profesores VALUES ('7654111q','1254','luis isco','roma','granada');
SELECT * FROM profesores;

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
INSERT INTO grupos VALUES ('BD01','1231','T',10,'7654321r');
INSERT INTO grupos VALUES ('PRO1','9876','T',100,'2333421t');
INSERT INTO grupos VALUES ('PRO2','9999','P',98,'7654111q');
SELECT * FROM grupos;

CREATE TABLE clase(
cod_asig CHAR(4),
cod_grup CHAR(4),
tipo CHAR(1),
cod_aula CHAR(4),
dia DATE,
hora TIMESTAMP,
PRIMARY KEY (cod_aula, dia, hora),
FOREIGN KEY (cod_asig, cod_grup, tipo) REFERENCES grupos (cod_asig, cod_grup, tipo),
FOREIGN KEY (cod_aula) REFERENCES aulas (cod_aula)
);
INSERT INTO grupos VALUES ('BD01','1231','T','1222',22/11/2018);
INSERT INTO grupos VALUES ('PRO1','9876','T','0001',23/02/2018);
INSERT INTO grupos VALUES ('PRO2','9999','P','1111',01/09/2017);
SELECT * FROM grupos;

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