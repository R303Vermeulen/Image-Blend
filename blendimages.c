#include<stdio.h>
#include<stdlib.h>

typedef unsigned char byte;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef unsigned int LONG;

typedef struct tagBITMAPFILEHEADER 
{ 
    WORD bfType; //specifies the file type 
    DWORD bfSize; //specifies the size in bytes of the bitmap file 
    WORD bfReserved1; //reserved; must be 0 
    WORD bfReserved2; //reserved; must be 0 
    DWORD bfOffBits; //species the offset in bytes from the bitmapfileheader to the bitmap bits 
} tagBITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER 
{
    DWORD biSize; //specifies the number of bytes required by the struct
    LONG biWidth; //specifies width in pixels 
    LONG biHeight; //species height in pixels 
    WORD biPlanes; //specifies the number of color planes, must be 1 
    WORD biBitCount; //specifies the number of bit per pixel 
    DWORD biCompression;//spcifies the type of compression 
    DWORD biSizeImage; //size of image in bytes 
    LONG biXPelsPerMeter; //number of pixels per meter in x axis 
    LONG biYPelsPerMeter; //number of pixels per meter in y axis
    DWORD biClrUsed; //number of colors used by th ebitmap 
    DWORD biClrImportant; //number of colors that are important 
} tagBITMAPINFOHEADER;

typedef struct pixel
{
    byte pred;
    byte pgre;
    byte pblu;
}pixel;



int main(int argc, char *argv[])
{
    char *df[5];
    double ratioOf1 = 0.5;

    if(argc<3)
    {
        return 0;
        printf("cringe");
    }
    if(argc < 5)
    {
        df[0] = argv[1];
        df[1] = argv[2];
        df[2] = "outImg.bmp";
    }
    if(argc > 3)
    {
        double rat;
        if(*(argv[3]) == 48 && *(argv[3]+1) == 0)
        {
            rat = 0;
        }
        else
        {
            rat = atof(argv[3]);
            if(rat == 0)
            {
                rat = 5;
            }
        }

        if(rat <= 1 && rat >= 0)
        {
            ratioOf1 = rat;
        }
        else
        {
            printf("Invalid Ratio, Using 0.5 Instead\n");
        }
    }

    if(argc > 4)
    {
        df[0] = argv[1];
        df[1] = argv[2];
        df[2] = argv[4];
    }

 
   
    //df[0] = "lion.bmp";
    //df[1] =  "wolf.bmp";


 

    int i = 6;


    FILE *f1 = fopen(df[0], "rb");
    if(f1 == NULL)
    {
        return 0;
    }


    struct tagBITMAPFILEHEADER fh1;
    struct tagBITMAPINFOHEADER ih1;
    int x;

    fread(&(fh1.bfType),sizeof(fh1.bfType), 1, f1);
    fread(&(fh1.bfSize),sizeof(fh1.bfSize), 1, f1);
    fread(&(fh1.bfReserved1),sizeof(fh1.bfReserved1), 1, f1);
    fread(&(fh1.bfReserved2),sizeof(fh1.bfReserved2), 1, f1);
    fread(&(fh1.bfOffBits),sizeof(fh1.bfOffBits), 1, f1);

    fread(&(ih1.biSize), sizeof(ih1.biSize), 1, f1);
    fread(&(ih1.biWidth), sizeof(ih1.biWidth), 1, f1);
    fread(&(ih1.biHeight), sizeof(ih1.biHeight), 1, f1);
    fread(&(ih1.biPlanes), sizeof(ih1.biPlanes), 1, f1);
    fread(&(ih1.biBitCount), sizeof(ih1.biBitCount), 1, f1);
    fread(&(ih1.biCompression), sizeof(ih1.biCompression), 1, f1);
    fread(&(ih1.biSizeImage), sizeof(ih1.biSizeImage), 1, f1);
    fread(&(ih1.biXPelsPerMeter), sizeof(ih1.biXPelsPerMeter), 1, f1);
    fread(&(ih1.biYPelsPerMeter), sizeof(ih1.biYPelsPerMeter), 1, f1);
    fread(&(ih1.biClrUsed), sizeof(ih1.biClrUsed), 1, f1);
    fread(&(ih1.biClrImportant), sizeof(ih1.biClrImportant), 1, f1);

    byte *data1 = (byte *) malloc(ih1.biSizeImage);
    fread(data1, ih1.biSizeImage, 1, f1);
    
    fclose(f1);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    FILE *f2 = fopen(df[1], "rb");
    if(f2 == NULL)
    {
        return 0;
    }

    struct tagBITMAPFILEHEADER fh2;
    struct tagBITMAPINFOHEADER ih2;
  

    fread(&(fh2.bfType),sizeof(fh2.bfType), 1, f2);
    fread(&(fh2.bfSize),sizeof(fh2.bfSize), 1, f2);
    fread(&(fh2.bfReserved1),sizeof(fh2.bfReserved1), 1, f2);
    fread(&(fh2.bfReserved2),sizeof(fh2.bfReserved2), 1, f2);
    fread(&(fh2.bfOffBits),sizeof(fh2.bfOffBits), 1, f2);

    fread(&(ih2.biSize), sizeof(ih2.biSize), 1, f2);
    fread(&(ih2.biWidth), sizeof(ih2.biWidth), 1, f2);
    fread(&(ih2.biHeight), sizeof(ih2.biHeight), 1, f2);
    fread(&(ih2.biPlanes), sizeof(ih2.biPlanes), 1, f2);
    fread(&(ih2.biBitCount), sizeof(ih2.biBitCount), 1, f2);
    fread(&(ih2.biCompression), sizeof(ih2.biCompression), 1, f2);
    fread(&(ih2.biSizeImage), sizeof(ih2.biSizeImage), 1, f2);
    fread(&(ih2.biXPelsPerMeter), sizeof(ih2.biXPelsPerMeter), 1, f2);
    fread(&(ih2.biYPelsPerMeter), sizeof(ih2.biYPelsPerMeter), 1, f2);
    fread(&(ih2.biClrUsed), sizeof(ih2.biClrUsed), 1, f2);
    fread(&(ih2.biClrImportant), sizeof(ih2.biClrImportant), 1, f2);

    byte *data2 = (byte *) malloc(ih2.biSizeImage);
    fread(data2, ih2.biSizeImage, 1, f2);
    
    fclose(f2);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    FILE *f3 = fopen(df[2], "wb");
    if(f3 == NULL)
    {
        printf("ye");
        return 0;
    }

    if(ih1.biSizeImage < ih2.biSizeImage)
    {
        struct tagBITMAPFILEHEADER fh3;
        struct tagBITMAPINFOHEADER ih3;
        byte *data3 = (byte *) malloc(ih2.biSizeImage);

        fh3 = fh1;
        ih3 = ih1;
        data3 = data1;

        fh1 = fh2;
        ih1 = ih2;
        data1 = data2;

        fh2 = fh3;
        ih2 = ih3;
        data2 = data3;

        ratioOf1 = 1 - ratioOf1;

    }

    

    fwrite(&(fh1.bfType),sizeof(fh1.bfType), 1, f3);
    fwrite(&(fh1.bfSize),sizeof(fh1.bfSize), 1, f3);
    fwrite(&(fh1.bfReserved1),sizeof(fh1.bfReserved1), 1, f3);
    fwrite(&(fh1.bfReserved2),sizeof(fh1.bfReserved2), 1, f3);
    fwrite(&(fh1.bfOffBits),sizeof(fh1.bfOffBits), 1, f3);

    fwrite(&ih1, sizeof(tagBITMAPINFOHEADER), 1, f3);

    pixel *pexs1 = (pixel *)malloc(ih1.biSizeImage);
    int pc = 0;
    double r1 = ratioOf1;
    double r2 = 1-ratioOf1;

    for(int i = 0; i < ih1.biSizeImage; i+=3)
    {
        int tx = pc%ih1.biWidth;
        double ty = (pc-tx)/ih1.biWidth;
        
        int rval;
        int gval;
        int bval;

        if(i<ih2.biSizeImage)
        {
            rval = (int)((data1[i])*(r1) + (data2[i])*(r2));
            gval = (int)((data1[i+1])*(r1) + (data2[i+1])*(r2));
            bval = (int)((data1[i+2])*(r1) + (data2[i+2])*(r2));
        }
        else
        {
            rval = (int)(data1[i]);
            gval = (int)(data1[i+1]);
            bval = (int)(data1[i+2]); 
        }

        pexs1[pc].pred = rval;
        pexs1[pc].pgre = gval;
        pexs1[pc].pblu = bval;
        pc += 1;
    }

    int pexnum = 0;

    for(int i = 0; i < pc; i++)
    {
        fwrite(&(pexs1[i].pred), sizeof(byte), 1, f3);
        fwrite(&(pexs1[i].pgre), sizeof(byte), 1, f3);
        fwrite(&(pexs1[i].pblu), sizeof(byte), 1, f3);
    }

    printf("\n");

    fclose(f3);
    free(data1);
    free(data2);


    
    
    return 0;
}

int commandLine(char *inp[])
{
    int rat;
    rat = -1;


    if(*(inp[1]+1) == 0)
    {
        if( *(inp[1]) > 47)
        {
            if(*(inp[1]) < 58)
            {
                rat = *(inp[1]) - 48;
            }
        }
    }
    else if((*(inp[1]) == 48 || *(inp[1]) == 49) && *(inp[1]+2) == 0)
    {
        if( *(inp[1]+1) > 47 && *(inp[1]+1) < 54)
        {
            rat = *(inp[1]+1) - 48;
            if( *(inp[1]) == 49)
            {
                rat += 10;
            }
        }
    }


    return rat;
}