DESCRIBE EMP;

SELECT * FROM emp;

create TABLE asignaturas(
cod_asig CHAR(4),
nom_asig VARCHAR2(30),
creditos NUMBER(4,1),
caracter CHAR(2),
curso NAMBER,
PRIMARY KEY(cod_asig)
);
create TABLE alumnos(
DNI CHAR(8),
nombre VARCHAR2(32),
fecha DATE,
direcion VARCHAR2(32),
beca CHAR CHECK(caracter in ('si', 'no')),
PRIMARY KEY(DNI)
);
create TABLE profesores(
NRP CHAR(4),
cod_dep CHAR(8),
nom_prof CHAR(32) NOT NULL,
categoria VARCHAR2(2),
area VARCHAR2(2),
cod_dep CHAR(4),
PRIMARY KEY(NRP, cod_dep),
FOREIGN KEY(cod_dep)
);
create TABLE departamentos(
cod_dep CHAR(8),
nom_dep CHAR(4),
NRP_DIRECTOR CHAR(4),
PRIMARY KEY(cod_dep),
FOREING KEY(NRP_DIRECTOR)
REFERENCES profesores (NRP)
);
create TABLE aulas(
cod_aula CHAR(4),
capacidad NUMBER(3),
PRIMARY KEY(cod_aula)
);
create TABLE grupos(
cod_asig CHAR(8),
tipo CHAR(1) CHECK (TIPO IN ('T', 'P')),
NRP CHAR(4),
max_al INT CHECK (max_al BETWEEN 10 AND 150),
PRIMARY KEY (cod_asig, cod_grup, tipo),
FOREING KEY cod_asig REFENCES asignaturas(cod_asig),
FOREING KEY NRP REFERENCES profesores(NRP)
);
create TABLE matriculas(
cod_asig CHAR(4),
cod_grup CHAR(4),
tipo CHAR(1),
DNI CHAR(8) REFERENCES alumnos(DNI),
convocatoria NUMBER,
calificacion NUMBER,
PRIMARY KEY (cod_asig, cod_grup, tipo, DNI, convocatoria),
FOREING KEY (cod_asig, cod_grup, tipo)
REFERENCES grupos(cod_asig, cod_grup, tipo)
);
create TABLE clase(
tipo CHAR(4),
cod_asig CHAR(4),
cod_grup CHAR(4),
cod_aula CHAR(4),
dia DATE,
hora DATE,
PRIMARY KEY (cod_aula, dia, hora),
FOREING KEY (cod_aula, tipo, cod_asig, cod_grup)
REFERENCES grupos (cod_asig, cod_grup, tipo) aula (cod_aula)
);



