<?xml version="1.0" encoding="UTF-8"?>
<?xml-stylesheet type="text/xsl" href="cdcatalog.xsl"?>
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
				<xsl:for-each select="catalog/cd">
					<xsl:sort select="price">
							<tr>
								<td> <xsl:value-of select="title"/></td>
								<td> <xsl:value-of select="artista"/></td>
								<td> <xsl:value-of select="price"/> </td>
							</tr>
						</xsl:sort>
					</xsl:if>
				</xsl:for-each>
			</table>
		</body>
	</html>
</xsl:template>