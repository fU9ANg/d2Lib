
/*
 *  Written 2011 by fU9ANg
 *  bb.newlife@gmail.com
 */
/* Windows BMP(Bitmap) file definitions for OpenGL */

typedef struct {                    /** BMP file header structure **/

    unsigned short  bfType;         /* ASCII 2-byte "BM" bitmap identifier */
    unsigned int    bfSize;         /* Total length of bitmap file in bytes */
    unsigned short  bfReserved1;    /* Reserved1 */
    unsigned short  bfReserved2;    /* Reserved2 */
    unsigned int    bfOffBits;      /* Offset to start of actual pixel data */

}   d2_bmpfile_header_t;

/*
 * Constants for the bitmap identifier
 */
#define     BITMAP_TYPE 0x4d42      /* "MB", LSB first */

typedef struct {                    /** BMP file info header structure **/

    unsigned int    biSize;         /* Size of info header */
    int             biWidth;        /* Width of bitmap in piexls */
    int             biHeight;       /* Height of bitmap in piexls */
    unsigned short  biPlanes;       /* Number of color planes, Usually 0x01 */
    unsigned short  biBitCount;     /* Number of bits per pixel, Sets color mode.
                                       Two byte integer, LSB first.
                                            1  -  2 lookup colors(Monochrome)
                                            4  -  16 lookup colors
                                            8  -  256 lookup colors
                                           16  -  65,536 lookup colors
                                           24  -  16,777,216 RGB colors
                                           32  -  16,777,216 RGB colors + alpha
                                    */
    unsigned int    biCompression;  /* Type of compressed to use, LSB first
                                            0  -  None (no compressed)
                                            1  -  8-bits run length encoded
                                            2  -  4-bits run length encoded
                                            3  -  Bitfields (RGB bitmap with RGB masks)
                                    */
    unsigned int    biSizeImage;    /* Total length of actual pixel data */
    int             biXPelsPerMeter;/* Width resolution in pixels per meter */
    int             biYPelsPerMeter;/* Height resolution in pixels per meter */
    unsigned int    biClrUsed;      /* Number of colors actually used */
    unsigned int    biClrImportant; /* Number of important colors */

}   d2_bmpinfo_header_t;

/*
 * Constants for the biCompression field of info header
 */
#define     BI_RGB          0
#define     BI_RLE8         1
#define     BI_RLE4         2
#define     BI_BITFIELDS    3

typedef struct {                    /** Colormap entry structure **/

    unsigned char   rgbBlue;        /* Blue value */
    unsigned char   rgbGreen;       /* Green value */
    unsigned char   rgbRed;         /* Red value */
    unsigned char   rgbReserved;    /* Reserved */

}   d2_rgb_t;

typedef struct {                    /** Bitmap information structure **/

    d2_bmpinfo_header_t bmiHeader;  /* Bitmap info header */
    d2_rgb_t            bmiClrTbl[256]; /* Bitmap colormap table */
}   d2_bmpinfo_t;

/*
 * Prototypes
 */
extern unsigned char *
d2_bmp_load (const char *filename, d2_bmp_info_t **info);
extern int
d2_bmp_save (const char *filename, d2_bmp_info_t  *info,
             unsigned char *bits);


/* Windows BMP(Bitmap) file functions for OpenGL */

/*
=====================
d2_bmp_load
=====================
*/
unsigned char *
d2_bmp_load (const char     *filename,
             d2_bmp_info_t  **info)
{
    FILE                *fp;
    unsigned char       *bits;
    int                 bitSize;
    int                 infoSize;
    d2_bmpfile_header_t header;

    if ((fp = fopen (filename, "rb")) == NULL)
        return (NULL);

    if (fread (&header, sizeof (d2_bmpfile_header_t), 1, fp) < 1) {
        fclose (fp);
        return (NULL);
    }

    if (header.bfType != BITMAP_TYPE) {
        fclose (fp);
        return (NULL);
    }

    infoSize = header.bfOffBits - sizeof (d2_bmpfile_header_t);
    if ((*info = (d2_bmpinfo_header_t *) malloc (infoSize)) == NULL) {
        fclose (fp);
        return (NULL);
    }

    if (fread (*info, 1, infoSize, fp) < infoSize) {
        free (*info);
        fclose (fp);
        *info = NULL;
        return (NULL);
    }

    d
}
/*
=====================
d2_bmp_save
=====================
*/
int
d2_bmp_save (const char     *filename,
             d2_bmp_info_t  **info,
             unsigned char  *bits)
{
    //
}
