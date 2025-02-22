// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int copy_header(FILE *input, FILE *output);
int multi_samples(FILE *input, FILE *output, float factor);

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    int ret = copy_header(input, output);
    if (ret != 0)
    {
        fclose(input);
        fclose(output);
        return ret;
    }

    // TODO: Read samples from input file and write updated data to output file
    ret = multi_samples(input, output, factor);
    if (ret != 0)
    {
        fclose(input);
        fclose(output);
        return ret;
    }

    // Close files
    fclose(input);
    fclose(output);
}

int copy_header(FILE *input, FILE *output)
{
    uint8_t buf[HEADER_SIZE];
    memset(buf, 0, HEADER_SIZE);
    int readlen = fread(buf, 1, HEADER_SIZE, input);
    if (readlen != HEADER_SIZE)
    {
        printf("read header from input failed.\n");
        return 1;
    }
    int writelen = fwrite(buf, 1, HEADER_SIZE, output);
    if (writelen != HEADER_SIZE)
    {
        printf("write header to output failed.\n");
        return 1;
    }
    return 0;
}

int multi_samples(FILE *input, FILE *output, float factor)
{
    int16_t sample = 0;
    while (1)
    {
        int readlen = fread(&sample, sizeof(int16_t), 1, input);
        if (readlen < 0)
        {
            printf("read samples from input failed.\n");
            return 1;
        }
        if (readlen == 0)
        {
            printf("read samples finished.\n");
            return 0;
        }
        sample *= factor;
        int writelen = fwrite(&sample, 2, 1, output);
        if (writelen <= 0)
        {
            printf("write samples to output failed.\n");
            return 1;
        }
    }
    return 0;
}
