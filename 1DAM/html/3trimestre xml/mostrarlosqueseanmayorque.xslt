<?xml version="1.0" encoding="UTF-8"?>
<?xml-stylesheet type="text/xsl" href="cdcatalog.xsl"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
	<html>
		<body>
			<table>
				<tr>
					<th> titulo </th>
					<th> artista </th>
					<th> precio </th>
				</tr>
				<xsl:choose>
					<!-- when es if -->
					<!-- muestra de color azul los que sean precio mayor de 15 -->
					<xsl:when test= "price &gt; 15" >
						<td bgcolor= "blue"></td>
					</xsl:when>
					<!-- else -->
					<!-- si no se cumple esa condicion muestralo en rojo-->
					<xsl:otherwise>
						<td bgcolor= "red"> </td>
				</xsl:choose>
			</table>
		</body>
	</html>
</xsl:template>