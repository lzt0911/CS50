#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int is_jpeg(uint8_t buffer[BLOCK_SIZE]);
void get_new_filename(char file[], int count);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *image = fopen(argv[1], "r");
    if (image == NULL)
    {
        printf("Can't open %s.\n", argv[1]);
        return 1;
    }
    uint8_t buffer[BLOCK_SIZE];
    memset(buffer, 0, BLOCK_SIZE);
    FILE *f = NULL;
    int file_count = 0;
    char newfile[8] = "000.jpg";
    while (fread(buffer, BLOCK_SIZE, 1, image) > 0)
    {
        if (is_jpeg(buffer)) // 判断是否为jpeg格式
        {
            // 发现一张新的jpeg
            if (f != NULL) // 关闭旧文件，打开新文件
            {
                fclose(f);
                f = NULL;
            }
            get_new_filename(newfile, file_count);
            file_count++;
            f = fopen(newfile, "w");
            if (f == NULL)
            {
                printf("Can't open new file.\n");
                return 1;
            }
            fwrite(buffer, BLOCK_SIZE, 1, f);
        }
        else
        {
            if (f != NULL) // 添加到当前文件中
            {
                fwrite(buffer, BLOCK_SIZE, 1, f);
            }
        }
    }
    if (f != NULL)
    {
        fclose(f);
    }
    fclose(image);
}

int is_jpeg(uint8_t buffer[BLOCK_SIZE])
{
    if (buffer[0] != 0xff || buffer[1] != 0xd8 || buffer[2] != 0xff)
    {
        return 0;
    }
    if ((buffer[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    return 0;
}

void get_new_filename(char file[], int count)
{
    file[0] = count / 100 + '0';
    file[1] = (count % 100) / 10 + '0';
    file[2] = count % 10 + '0';
}
