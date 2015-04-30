/** PGMio.c 
*
* Author: Du Huynh, August 2003
*
* written for Visualisation 413, Labsheet 2
* School of Computer Science and Software Engineering
* The Universiy of Western Australia
*
* This file contains the following functions:
*	createImage
*	readPGM 
*	writePGM 
*/
#include "pgm.h"

/** Allocates memory for an image (2D array of unsigned char).
*
* Arguments:
* nr: number of rows
* nc: number of columns
*/
unsigned char **createImage(int nr, int nc) {
	unsigned char **im;
	register int i;

	im = (unsigned char **)malloc(sizeof(unsigned char *)*nr);
	if (im == NULL)
		return NULL;
	for (i=0; i < nr; i++) {
		im[i] = (unsigned char *)malloc(sizeof(unsigned char)*nc);
		if (im[i] == NULL)
			return NULL;
	}
	return im;
}

/* ------------------------------------------------------ */

/** Read a pgm image from disk.  Function outputs the 2D array
* of unsigned char read if the read operation succeeded, NULL otherwise. 
*
* Arguments:
* filename (input): name of the input pgm file
* nr (output): number of rows of the image
* nc (output): number of colums of the image
* max_inten (output): maximum intensity value
*/
unsigned char **readPGM(char *filename, int *nr, int *nc, int *max_inten) {
	FILE *fp;
	char msg[80], string[80];
	unsigned char **pixels;
	register int i;

	if ( filename == NULL)
		fp = stdin;
	else if ( (fp = fopen(filename, "r")) == NULL )
		// file not found
		return NULL;

	fscanf(fp, "%s\n", string);
	if (strcmp(string, "P5") != 0) {
		// not a PGM file
		fclose(fp);
		return NULL;
	}

	fscanf(fp, "%d%d\n%d\n", nr, nc, max_inten);

	// now read in the raw data block
	if (*max_inten > 255) {
		// can't handle unsigned short PGM files
		fclose(fp);
		return NULL;
	}

	if ( (pixels = createImage(*nr, *nc)) == NULL) {
		// out of memory
		fclose(fp);
		return NULL;
	}
	for (i=0; i < *nr; i++)
		fread(pixels[i], sizeof(unsigned char), *nc, fp);

	fclose(fp);
	return pixels;
}

/* ------------------------------------------------------ */

/** Write a pgm image to disk.  Function returns 1 if the write operation succeeded, 0 otherwise.
*
* Arguments:
* image (input): the 2D array of unsigned char that holds the contents of
*                the image
* nrows (input): number of rows of the image
* ncols (input): number of colums of the image
* maxval (input): maximum intensity value
* filename (input): name of the output image file
*/
int writePGM(unsigned char **image, int nrows, int ncols, int maxval, char *filename) {
	FILE *fp;
	register int i;

	if (filename == NULL)
		fp = stdout;
	else if ((fp = fopen(filename, "w")) == NULL)
		return 0;

	fprintf(fp, "P5\n%d %d\n%d\n", nrows, ncols, maxval);
	for (i=0; i < nrows; i++)
		fwrite(image[i], sizeof(unsigned char), ncols, fp);
	fclose(fp);

	return 1;
}

/*
int main(){
	puts("start");
	int nr, nc;
	nc = 256;
	nr = 256;	

	
	char *filename = "test.pgm";
	unsigned char **img, **pix;
	img = NULL;
	pix = NULL;
	img = createImage(nr, nc);
	if(img)	
		puts("create success");

	int *nrow = NULL;
	int *ncol = NULL;
	int *max_inten = NULL;

	nrow = &nr;
	ncol = &nc;
	max_inten = &nr;
	
	pix = readPGM(filename, nrow, ncol, max_inten);
	if(pix)	
		puts("reading...");
	
	for (unsigned int n = 0; n <255; ++n )
	{
		printf("%s", *pix );
		++pix;
		if(*pix)
			;
		else
			break;
	}

    int w = writePGM(pix, nr, nc, nc, "new.pgm");
	if(w==1)
		puts("write success!");
	return 0;	
}
*/
