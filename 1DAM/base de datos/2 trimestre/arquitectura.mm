<map version="1.0.1">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1516040017983" ID="ID_683643467" MODIFIED="1516040144738" TEXT="Arquitectura de un SGBD">
<node CREATED="1516040070854" ID="ID_633110398" MODIFIED="1516040208688" POSITION="right" TEXT="Arquitectura en tres niveles: La arquitectura ansi/sparc">
<node CREATED="1516040181897" ID="ID_641378237" MODIFIED="1516040449157" TEXT="nivel externo: vision de usuarios, independencia logica, cada usuario pude tener una base de datos diferente"/>
<node CREATED="1516040258404" ID="ID_372695671" MODIFIED="1516301201523" TEXT="nivel conceptual: vision logica, todos los datos DER"/>
<node CREATED="1516040288006" ID="ID_899793511" MODIFIED="1516040418491" TEXT="nivel interno: vision interna global, es la capa donde establece la forma en que se implantan las estructuras de datos que se organizan los niveles superiores"/>
</node>
<node CREATED="1516040467151" ID="ID_1792699845" MODIFIED="1516301904802" POSITION="left" TEXT="lenguaje de aplicacion: la arquitectura ansi/sparc debe disponer de un lenguaje especifico orientado a los datos">
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node CREATED="1516040546967" ID="ID_1007396799" MODIFIED="1516302359989" TEXT="DDL: para crear parte del lenguaje del sistema gestor de bd que crea el modelo de datos DER">
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node CREATED="1516042273590" ID="ID_911400360" MODIFIED="1516042711279" TEXT="BD debe proporcionar a cada usuario una perpectiva que sea precisa, lo denominamos vista o vision externa. En el nivel externo podemos disponer de un conjunto de vistas externas, cada una de elles puede ser comun a varios usuarios."/>
</node>
<node CREATED="1516040596930" ID="ID_269452616" MODIFIED="1516302365849" TEXT="DML (DBA): para insertar ocurrencias, subconjunto del DSL mediante el que podemos introducir datos en los esquemas, modificarlos, eliminarlos y consultarlos.">
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node CREATED="1516042791035" ID="ID_633464252" MODIFIED="1516302018365" TEXT="proporcionada por el SO sobre el que se ejecuta el SGBD,  debe disponer de su DDL ademas de , DML y el DDL debe permitir estructurar los mecanismos de acceso."/>
</node>
<node CREATED="1516040706870" ID="ID_1079790349" MODIFIED="1516302369459" TEXT="DCL:(DBA) para tocar el modeloexterno copia de seguridad, requisistos, control de datos. permite gestionar los requisitos.">
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node CREATED="1516042715219" ID="ID_853558265" MODIFIED="1516042776598" TEXT="debe ofrecer una unica perpectiva o vision general, la manipulacion de los contenidos almacenados, "/>
</node>
<node CREATED="1516040779993" ID="ID_1524715383" MODIFIED="1516302499130" TEXT="la propuesta de ansi/sparc debe proporcionar un SGBD tiene que tener; DDL, DML, DCL. para nivel externo, conceptual y interno. el lenguaje anfitrion de la aplicacion tiene que poder ser empleado para desarrollar aplicaciones. como c/c++, pascal ,java, etc.">
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
</node>
<node CREATED="1516041574627" ID="ID_1089296211" MODIFIED="1516302536681" TEXT="debilmente acoplados: constituidos por lenguajes en general c++... es dotar a los lenguajes de proposito general para interactuar con el DSL del SGBD"/>
<node CREATED="1516041652881" ID="ID_1531934828" MODIFIED="1516041753538" TEXT="Fuertemente acoplados; constituidos por lenguajes de proposito especifico, se parte del DSL se le incorporan todas las carasteristicas para facilitar el desarrollo de apliaciones de gestion de BD"/>
<node CREATED="1516041773123" ID="ID_907535601" MODIFIED="1516302171570" TEXT="utilizacion de APIs de acceso a BD; interfaz de programacion, el programa esta JUNTO A LA BIBLIOTECA BINARIA PARA EJECUTARSE EN EL SGBD"/>
<node CREATED="1516041891644" ID="ID_654543005" MODIFIED="1516302612814" TEXT="DSL inmerso en el codigo fuente del lenguaje afitrion; ">
<node CREATED="1516302615721" ID="ID_1276081334" MODIFIED="1516302618565" TEXT="codigo fuente hibrido entre su lenguaje afitrion y DSL"/>
</node>
<node CREATED="1516042886662" ID="ID_1075778504" MODIFIED="1516042897369" TEXT="transformacion entre niveles">
<node CREATED="1516042901720" ID="ID_563922354" MODIFIED="1516042939482" TEXT="transformacion conceptual/interna, para garantizar la independecia fisica."/>
<node CREATED="1516042948113" ID="ID_1907348089" MODIFIED="1516302229614" TEXT="transformacion externa/conceptual. la independencia logica quedara la posibilidad de modificarla frente a proximas modificaciones"/>
<node CREATED="1516043011090" ID="ID_1162988938" MODIFIED="1516043080003" TEXT="transformacion externa/externa; se produce cambios en el esquema externo nos ayudara a mantener la idependecia logica. suele estar implementada por el propio SGBD."/>
</node>
</node>
<node CREATED="1516130841092" ID="ID_805403749" MODIFIED="1516130858405" POSITION="right" TEXT="EL ADMINISTRADOR DE BD (DBA)">
<node CREATED="1516130862314" ID="ID_1861505388" MODIFIED="1516301131510" TEXT="elavoracion del esquema conceptual: analisis de las necesidades de informacion de la empresa (DER), implantacion conceptual del DDL  EL SGBD  guarda el lenguaje en codigo fuente. "/>
<node CREATED="1516130966845" ID="ID_1189266333" MODIFIED="1516130996194" TEXT="definir restrciones; evite la introducion de datos incopatibles con las restriciones semanticas."/>
<node CREATED="1516131002034" ID="ID_1927942093" MODIFIED="1516301210685" TEXT="definir politicas de seguridad; puede acceder a creacion, modificacion, eliminacion y consulta de datos"/>
<node CREATED="1516131048999" ID="ID_1500730415" MODIFIED="1516131096440" TEXT="optimizaacion del rendimiento; en la medida de la disponibilidad de los recursos SGBD funcione lo mas eficiente posible."/>
<node CREATED="1516213160205" ID="ID_1413449074" MODIFIED="1516227028230" TEXT="componentes de un SGBD">
<node CREATED="1516213262953" ID="ID_1237923876" MODIFIED="1516301492449" TEXT="optimizacion en la ejecucion ">
<node CREATED="1516301498194" ID="ID_53779139" MODIFIED="1516301501710" TEXT="de la sentencia de datos. el plan dependiendo de la peticion ejecucion acede a los archivos implicados. ejecucion mas eficiente para la peticion dada."/>
</node>
<node CREATED="1516213372910" ID="ID_166321350" MODIFIED="1516301516110" TEXT="integridad:">
<node CREATED="1516301520896" ID="ID_983655803" MODIFIED="1516301523491" TEXT=" se realiza mediante el DSL las reglas de integridad, modulos de programas denominados disparadores, se vinculan a los archivos copceptuales o externos."/>
</node>
<node CREATED="1516227032847" ID="ID_1332067089" MODIFIED="1516301532721" TEXT="gestion de la ocurrencia y de la consistencia; ">
<node CREATED="1516301536379" ID="ID_614686914" MODIFIED="1516301538646" TEXT="el acceso multiusuario requiere arbitrar estrategias que eviten que las modificaciones de un usuario se superpongan a las de otros de tal forma que ninguno perciba la BD. DBA definir el bloqueo de informacion. "/>
</node>
<node CREATED="1516227182357" ID="ID_1343530071" MODIFIED="1516301548909" TEXT="dicionario de datos; ">
<node CREATED="1516301560472" ID="ID_372124903" MODIFIED="1516301562604" TEXT="el SGDB debe disponer de informacion acerca de las definiciones, esquemas, usuarios, y el esquema conceptual. BD es una estructura espedifica que permita almacenar y acceder a la informacion"/>
</node>
<node CREATED="1516227271951" ID="ID_1914157619" MODIFIED="1516301573172" TEXT="herramienta de apoyo a la administracion;">
<node CREATED="1516301577328" ID="ID_224422830" MODIFIED="1516301579316" TEXT=" partes del programa que permiten suministrar la BD"/>
</node>
</node>
</node>
<node CREATED="1516214013822" ID="ID_1289083968" MODIFIED="1516302652725" POSITION="left" TEXT="DBA : definicion administrador de base de datos.  dirige o lleva a cabo todas las actividades relacionadas con el mantenimiento de un entorno de base de datos exitoso. Las responsabilidades incluyen el dise&#xf1;o">
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
</node>
<node CREATED="1515696336845" ID="ID_859311921" MODIFIED="1515697308566" POSITION="right" TEXT="introducion a la base de datos">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
  </body>
</html></richcontent>
<font BOLD="true" ITALIC="true" NAME="SansSerif" SIZE="12"/>
<node CREATED="1515696673988" ID="ID_1731356606" MODIFIED="1515696838091" TEXT="definicion de base de datos">
<node CREATED="1515696744776" ID="ID_751375190" MODIFIED="1516301595823" TEXT="fondo comun de informacion almacenada en una computadora para que cuaquier persona o programa autorizado pueda acceder a ella, independentemente de su procedencia y del uso que le haga."/>
</node>
<node CREATED="1515696734964" ID="ID_1167466474" MODIFIED="1516302823119" TEXT="&#xbf;que es?">
<icon BUILTIN="help"/>
<node CREATED="1515696873493" ID="ID_921299568" MODIFIED="1516301352206" TEXT="una base de datos esta constituida por una instacia de un esquema logico junto con instancias de los datos operativos que dicho esquema organiza"/>
</node>
<node CREATED="1515696959323" HGAP="60" ID="ID_1178754261" MODIFIED="1515697270603" TEXT="SGBD" VSHIFT="-11">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      hola
    </p>
  </body>
</html></richcontent>
<node CREATED="1515697029740" HGAP="122" ID="ID_1714790465" MODIFIED="1515697279574" TEXT="sistema de gestion de base de datos conjunto de elementos software con capacidad para definir, mantener y utilizar la base de datos " VSHIFT="-12"/>
</node>
<node CREATED="1515697330411" ID="ID_739599865" MODIFIED="1515697339503" TEXT="los datos">
<node CREATED="1515697346824" ID="ID_1935265641" MODIFIED="1516302871702" TEXT="representan la actividad de la empresa en el sistema es preciso organizar mediante un esquema logico adecuado, los datos tienen un caracter compartido y deben gestionarse de forma que el usuario solo aced&#xe1; aquellos que le completan"/>
</node>
<node CREATED="1515697467856" ID="ID_106622978" MODIFIED="1515697500723" TEXT="el software">
<node CREATED="1515697503821" ID="ID_1981498803" MODIFIED="1515697594958" TEXT="el SGBD esta contituido por una serie de programas que permiten crear alterar y eliminar BD, los programas de aplicacion articulan sobre la BD las necesidades de informacion del usuario"/>
</node>
<node CREATED="1515697599111" ID="ID_1848104655" MODIFIED="1515697612463" TEXT="el hardware">
<node CREATED="1515697616010" ID="ID_76583752" MODIFIED="1515697730411" TEXT="SGBD sera necesario disponer de una arquitectura mas o menos complejas, podemos disponer de una o varias BD cuya informacion se gestiona a traves del SGBD y cuya informacion se procesa desde una aplicacion servida a un pcs se denominan servidores de aplicaciones."/>
</node>
<node CREATED="1515697738932" ID="ID_830814094" MODIFIED="1515697746049" TEXT="los usuarios">
<node CREATED="1515697749020" ID="ID_920824313" MODIFIED="1516302951892" TEXT="los usuarios que usan una BD para acometer sus actividades de forma directa o a traves de un programa de aplicacion. los usuarios no necesitan tener el conocimiento alguno de que lo esta o esta implantado el sistema"/>
<node CREATED="1515697873980" ID="ID_1836764711" MODIFIED="1515697980108" TEXT="programador de aplicaciones se encarga de desarrollar el programa de aplicacion sobre una BD que proporcionen soporte a las funciones desempe&#xf1;adas la aplicacion que va adesarrollar"/>
<node CREATED="1515697984102" ID="ID_1576619349" MODIFIED="1515698042557" TEXT="el administrador de la base de datos es el encargado de gestionar todos los componentes del SGBD para que la BD para que represente y integre todos los elementos necesarios"/>
</node>
<node CREATED="1515698068931" ID="ID_111262998" MODIFIED="1515698084849" TEXT="independencia de base datos">
<node CREATED="1515698088391" ID="ID_1771306717" MODIFIED="1515698117107" TEXT="el principio de independecia de datos establece">
<node CREATED="1515698121111" ID="ID_1368373734" MODIFIED="1516303030478" TEXT="los datos deben organizarse independientemente de las apliaciones que los vaya a usar y de los ficheros que se vayan almacenar dichos datos"/>
</node>
<node CREATED="1515698187694" ID="ID_1046732672" MODIFIED="1515698196906" TEXT="independiencia fisica">
<node CREATED="1515698200736" ID="ID_1228358390" MODIFIED="1515698231916" TEXT="el almacenamiento fisico de los datos debe ser intependiente del dise&#xf1;o logico de la BD a todos los niveles"/>
</node>
<node CREATED="1515698239907" ID="ID_1072339828" MODIFIED="1515698247552" TEXT="independencia logica">
<node CREATED="1515698249722" ID="ID_153545657" MODIFIED="1516303059216" TEXT="si cambias algo de la BD no se ve repercutido o no lo necesita saberlo el usuario."/>
</node>
</node>
<node CREATED="1515698310068" ID="ID_1616090057" MODIFIED="1516300623102" TEXT="objetivos de un SGBD">
<node CREATED="1515698424524" ID="ID_1402931958" MODIFIED="1516301794407" TEXT="dise&#xf1;o y utulizacion  de fundamentos en un modelo de datos y proporcionar lenguajes que resulten apropiados"/>
<node CREATED="1515698497694" ID="ID_225100810" MODIFIED="1515698538785" TEXT="centralizacion los datos deben gestionarse de forma centralizada e independientemente de las aplicaciones"/>
<node CREATED="1515698541630" ID="ID_608967563" MODIFIED="1515698560185" TEXT="evitar que se repita no es preciso duplicar datos"/>
<node CREATED="1515698562682" ID="ID_963067384" MODIFIED="1516301855541" TEXT="SEGURIDAD; mantener integridad semantica de los datos. la informacion que almacena una BD deberia corresponderse en todo momento con la realidad que representa esto no siempre es posible debedido a tres factores">
<node CREATED="1515698657726" ID="ID_1919771123" MODIFIED="1515698670299" TEXT="seguridad"/>
<node CREATED="1515698676142" ID="ID_1787592402" MODIFIED="1515698690142" TEXT="errores humanos"/>
<node CREATED="1515698694781" ID="ID_326778025" MODIFIED="1515698707118" TEXT="control y recuperacion de fallos"/>
</node>
<node CREATED="1515698724871" ID="ID_1256667714" MODIFIED="1515698755268" TEXT="mantener la seguridad, evitar que los usuarios puedan acceder a informacion no autorizada"/>
</node>
</node>
</node>
</map>
