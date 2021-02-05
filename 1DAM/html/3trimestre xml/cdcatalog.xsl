<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html>
  <body>
  <h2>My CD Collection</h2>
  <ul border="1">
      <li>Artist</li>
      <li>Title</li>
    <xsl:for-each select="catalog/cd">
    <tr>
      <td><xsl:value-of select="title"/></td>
      <td><xsl:value-of select="artist"/></td>
    </tr>
    </xsl:for-each>
  </ul>
<xsl:sort select="artist"/> <!-- ordenar por artista -->
   <xsl:choose>   
      <xsl:when select="date"> 
      <tr>
        <td><xsl:value-of select="title"/></td>
        <td><xsl:value-of select="artist"/></td>
      </tr>
  <xsl:choose> <!--condicion -->
      <xsl:when> <!--cuando sea --> 
    </xsl:when>
  </xsl:choose>

  <xsl:template>
    <xsl:apply-templates select=title/> <!-- va a usar una plantilla --> <!-- usando el titulo --> 

  </xsl:template>
  </body>
  </html>
</xsl:template>

</xsl:stylesheet>