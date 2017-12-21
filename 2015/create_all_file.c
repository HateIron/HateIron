#include <stdio.h>
#include <string.h>

int main()
{
    FILE  *srcFile         = fopen("2015-10-01.html", "r");
    FILE  *pDstFile        = NULL;
    char   buff[1024]      = {0};
    int    year            = 2020;
    int    month           = 10;
    int    day             = 1;
    char   pDstName[32]    = {0};
    int    line_len        = 0;
    char   sel_line[256]   = {0};
    char   color_line[256] = {0};
    char  *prev_line_flag  = "rel=\"prev\"";
    char  *next_line_flag  = "rel=\"next\"";
    char   prev_line[256]  = {0};
    char   next_line[256]  = {0};

    if (NULL == srcFile)
    {
        printf("src file open failed\n");
        return 0;
    }

    for (month = 1; month <= 12; month ++)
    {
        for (day = 1; day <= 31; day++)
        {
            rewind(srcFile);
            sprintf(pDstName, "%04d-%02d-%02d.html", year, month, day);

            memset(color_line, 0, sizeof(color_line));
            memset(sel_line, 0, sizeof(sel_line));
            memset(prev_line, 0, sizeof(prev_line));
            memset(next_line, 0, sizeof(next_line));

            sprintf(sel_line, "<a target=\"_top\" title=\"%04d-%02d-%02d\" "
                    "href=\"%04d-%02d-%02d.html\">%04d-%02d-%02d</a>",
                    year, month, day, year, month, day, year, month, day);
            sprintf(color_line, "<a target=\"_top\" title=\"%04d-%02d-%02d\" "
                    "href=\"%04d-%02d-%02d.html\" "
                    "style=\"background-color: rgb(150, 185, 125); "
                    "font-weight: bold; color: rgb(255, 255, 255);\">%04d-%02d-%02d</a>",
                    year, month, day, year, month, day, year, month, day);
            sprintf(prev_line, "<a href=\"%04d-%02d-%02d.html\" rel=\"prev\" "
                    "title=\"%04d-%02d-%02d\">上一页%04d-%02d-%02d</a>",
                    year, month, day - 1, year, month, day - 1, year, month, day - 1);
            sprintf(next_line, "<a href=\"%04d-%02d-%02d.html\" rel=\"next\" "
                    "title=\"%04d-%02d-%02d\">下一页%04d-%02d-%02d</a>",
                    year, month, day + 1, year, month, day + 1, year, month, day + 1);

            pDstFile = fopen(pDstName, "w");

            if (NULL == pDstFile)
            {
                printf("pDstFile %s file open failed\n", pDstName);
                return 0;
            }

            while ((fgets(buff, 1024, srcFile)) != NULL)
            {
                if (strstr(buff, sel_line))
                {
                    fputs(color_line, pDstFile);
                }
                else if (strstr(buff, prev_line_flag))
                {
                    fputs(prev_line, pDstFile);
                }
                else if (strstr(buff, next_line_flag))
                {
                    fputs(next_line, pDstFile);
                }
                else
                {
                    fputs(buff, pDstFile);
                }
            }

            fclose(pDstFile);
        }
    }

    fclose(srcFile);
    return 0;
}

