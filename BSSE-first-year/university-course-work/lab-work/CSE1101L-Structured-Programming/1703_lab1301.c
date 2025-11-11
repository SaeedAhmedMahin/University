// Name: Saeed Ahmed Mahin
// Roll: 1703
// CSE1101L


#include <stdio.h>
#include <stdlib.h>
#include <math.h> 



#define H 512
#define W 512

// TO DO
// 1. Read image and get height and width and store in the struct, 
// 2. turn the image into gray scaled and save as a new image  

// Use structure packing so compiler doesn’t add padding bytes
#pragma pack(push, 1)

// ===================== BITMAP FILE HEADER (14 bytes) =====================
typedef struct {
    unsigned short bfType;        // File type, always 'BM' (0x4D42)
    unsigned int   bfSize;        // Size of the file in bytes
    unsigned short bfReserved1;   // Reserved, must be 0
    unsigned short bfReserved2;   // Reserved, must be 0
    unsigned int   bfOffBits;     // Offset in bytes from beginning of file to pixel data
} BITMAPFILEHEADER;

// ===================== BITMAP INFO HEADER (40 bytes) =====================
typedef struct {
    unsigned int   biSize;           // Size of this header (40 bytes)
    int            biWidth;          // Image width in pixels
    int            biHeight;         // Image height in pixels
    unsigned short biPlanes;         // Number of color planes (must be 1)
    unsigned short biBitCount;       // Bits per pixel (24 for RGB)
    unsigned int   biCompression;    // Compression (type 0 = uncompressed)
    unsigned int   biSizeImage;      // Image size (may be 0 for uncompressed)
    int            biXPelsPerMeter;  // Horizontal resolution (pixels per meter)
    int            biYPelsPerMeter;  // Vertical resolution (pixels per meter)
    unsigned int   biClrUsed;        // Number of colors in the color table (0 = all colors used)
    unsigned int   biClrImportant;   // Number of important colors (0 = all are important)
} BITMAPINFOHEADER;

typedef struct {
    unsigned char rgbtBlue;
    unsigned char rgbtGreen;
    unsigned char rgbtRed;
} RGBTRIPLE;

#pragma pack(pop)



void grayscale(int height, int width, RGBTRIPLE image[H][W]){
for(int x=0; x<height; x++){
    for(int y=0; y<width ; y++){
        
            unsigned int colour = 0.299*image[x][y].rgbtRed + 0.587*image[x][y].rgbtGreen + 0.114*image[x][y].rgbtBlue;
            image[x][y].rgbtRed = colour ;
            image[x][y].rgbtBlue = colour ;
            image[x][y].rgbtGreen = colour ;
         }
    }
}



int main() {
// Part 1 reading the given data
    FILE *f = fopen("lena_rgb.bmp", "rb");
    if (!f) {
        printf("Error: could not open file.\n");
        return 1;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, f);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, f);
	
    
    printf("BITMAP FILE HEADER STRUCT DATA\n");
    printf("File type: %c%c\n", fileHeader.bfType & 0xFF, fileHeader.bfType >> 8);
    printf("File size: %u bytes\n", fileHeader.bfSize);
    printf("Reserved1: %u\n", fileHeader.bfReserved1);
    printf("Reserved2: %u\n", fileHeader.bfReserved2);
    printf("Pixel data offset: %u bytes\n", fileHeader.bfOffBits);

    printf("\nBITMAP INFO HEADER STRUCT DATA\n");
    printf("Header size: %u bytes\n", infoHeader.biSize);
    printf("Width: %d pixels\n", infoHeader.biWidth);
    printf("Height: %d pixels\n", infoHeader.biHeight);
    printf("Color planes: %u\n", infoHeader.biPlanes);
    printf("Bits per pixel: %u\n", infoHeader.biBitCount);
    printf("Compression: %u\n", infoHeader.biCompression);
    printf("Image size: %u bytes\n", infoHeader.biSizeImage);
    printf("X pixels per meter: %d\n", infoHeader.biXPelsPerMeter);
    printf("Y pixels per meter: %d\n", infoHeader.biYPelsPerMeter);
    printf("Colors used: %u\n", infoHeader.biClrUsed);
    printf("Important colors: %u\n", infoHeader.biClrImportant);
    
    // Now part 2 creating a new file gray scale version
    
     // Move to pixel data
    fseek(f, fileHeader.bfOffBits, SEEK_SET);

    // Allocate memory for pixels
    unsigned char *pixels = malloc(infoHeader.biSizeImage);
    fread(pixels, infoHeader.biSizeImage, 1, f);
    fclose(f);
    int width = infoHeader.biWidth;
    int height = abs(infoHeader.biHeight); // BMP height can be negative
    
    RGBTRIPLE image[H][W] = {0};
  

    // Modify pixels (for now, we’ll just keep them unchanged)
    // Later, we can add grayscale conversion here.
    grayscale(height, width, image);
    
    

    FILE *newFile = fopen("gray.bmp", "wb");
    if (!newFile) {
        printf("Error: could not create new file.\n");
        free(pixels);
        return 1;
    }

    fwrite(&fileHeader, sizeof(fileHeader), 1, newFile);
    fwrite(&infoHeader, sizeof(infoHeader), 1, newFile);
    fwrite(image, infoHeader.biSizeImage, 1, newFile);

    fclose(newFile);
    free(pixels);

    printf("Copied image successfully to gray.bmp\n");
    
    

    fclose(f);
    return 0;
}

