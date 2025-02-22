#include "helpers.h"
#include <math.h>

// 计算pixel附近3*3的平均值
RGBTRIPLE blur_grid_average(int height, int width, RGBTRIPLE image[height][width], int i, int j);

// 计算piexl附近3*3的加权平均值得到边缘
RGBTRIPLE edge_grid_average(int height, int width, RGBTRIPLE image[height][width], int i, int j);

#define MAX_PIXEL 255

int GX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

int GY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // 取平均
            BYTE average =
                round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, k = width - 1; j < k; j++, k--)
        {
            // 左右翻转
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][k];
            image[i][k] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_image[i][j] = blur_grid_average(height, width, image, i, j);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_image[i][j] = edge_grid_average(height, width, image, i, j);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
    return;
}

RGBTRIPLE blur_grid_average(int height, int width, RGBTRIPLE image[height][width], int i, int j)
{
    float sum_right = 0;
    float sum_blue = 0;
    float sum_green = 0;
    int num = 0;
    for (int m = -1; m <= 1; m++)
    {
        for (int n = -1; n <= 1; n++)
        {
            int new_i = i + m;
            int new_j = j + n;
            if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width)
            {
                sum_right += image[new_i][new_j].rgbtRed;
                sum_green += image[new_i][new_j].rgbtGreen;
                sum_blue += image[new_i][new_j].rgbtBlue;
                num++;
            }
        }
    }
    sum_right = round(sum_right / num);
    sum_blue = round(sum_blue / num);
    sum_green = round(sum_green / num);
    RGBTRIPLE average;
    average.rgbtRed = (BYTE) sum_right;
    average.rgbtGreen = (BYTE) sum_green;
    average.rgbtBlue = (BYTE) sum_blue;
    return average;
}

RGBTRIPLE edge_grid_average(int height, int width, RGBTRIPLE image[height][width], int i, int j)
{
    float sum_right_x = 0, sum_blue_x = 0, sum_green_x = 0;
    float sum_right_y = 0, sum_blue_y = 0, sum_green_y = 0;
    for (int m = -1; m <= 1; m++)
    {
        for (int n = -1; n <= 1; n++)
        {
            int new_i = i + m;
            int new_j = j + n;
            if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width)
            {
                sum_right_x += image[new_i][new_j].rgbtRed * GX[m + 1][n + 1];
                sum_green_x += image[new_i][new_j].rgbtGreen * GX[m + 1][n + 1];
                sum_blue_x += image[new_i][new_j].rgbtBlue * GX[m + 1][n + 1];
                sum_right_y += image[new_i][new_j].rgbtRed * GY[m + 1][n + 1];
                sum_green_y += image[new_i][new_j].rgbtGreen * GY[m + 1][n + 1];
                sum_blue_y += image[new_i][new_j].rgbtBlue * GY[m + 1][n + 1];
            }
        }
    }
    RGBTRIPLE average;
    int val = round(sqrt(sum_right_x * sum_right_x + sum_right_y * sum_right_y));
    if (val > MAX_PIXEL)
    {
        average.rgbtRed = MAX_PIXEL;
    }
    else
    {
        average.rgbtRed = (BYTE) val;
    }
    val = round(sqrt(sum_green_x * sum_green_x + sum_green_y * sum_green_y));
    if (val > MAX_PIXEL)
    {
        average.rgbtGreen = MAX_PIXEL;
    }
    else
    {
        average.rgbtGreen = val;
    }
    val = round(sqrt(sum_blue_x * sum_blue_x + sum_blue_y * sum_blue_y));
    if (val > MAX_PIXEL)
    {
        average.rgbtBlue = MAX_PIXEL;
    }
    else
    {
        average.rgbtBlue = val;
    }

    return average;
}
