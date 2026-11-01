#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include "String.h"
#define LEN 50
char *s_gets(char *st, int n)
{
    char * ret_val;
    int i=0;
    ret_val=fgets(st,n , stdin);
    if(ret_val)
    {
        while(st[i]!='\n' && st[i]!='\0')
            i++;
        if(st[i]=='\n')
           st[i]='\0';
        else
            while(getchar()!='\n')
                continue;
        }
         return ret_val;
    } 
int SrarchString_replace(void)
{
    char name[LEN] = {0};
    int match_count = 0;
    FILE *pf = fopen("D:\\VSCODE\\VScode_C_basic_0\\0055_StringSearch\\AA.txt", "rb");
    if (pf == NULL)
    {
        printf("Document open FAIL\n");
        return 1;
    }
    printf("�п�J�n�d�䪺 name�G\n");
    s_gets(name, LEN);

    if (name[0] != '\0')
    {
        const char replace[] = "XX";
        long file_size;
        char *content;
        size_t name_length = strlen(name);
        fseek(pf, 0, SEEK_END);
        file_size = ftell(pf);
        printf("%ld\n", file_size);
        rewind(pf);
        content = malloc((size_t)file_size + 1);

        if (content != NULL && fread(content, 1, (size_t)file_size, pf) == (size_t)file_size)
        {
            char *match = content;
            content[file_size] = '\0';
            printf("......%s\n",strstr(match, name));
            while ((match = strstr(match, name)) != NULL)
            {
                int starts_word = match == content ||        (!isalnum((unsigned char)match[-1]) && match[-1] != '_');
                printf("==%d\n",starts_word);
                int ends_word = match[name_length] == '\0' ||(!isalnum((unsigned char)match[name_length]) && match[name_length] != '_');
                printf("..%d\n",ends_word);
                if (starts_word && ends_word)
                    match_count++;
                match += name_length;
            }

            if (match_count > 0)
            {
                size_t replace_length = strlen(replace);
                size_t content_length = strlen(content);
                size_t new_size;

                if (replace_length >= name_length)
                    new_size = content_length +(replace_length - name_length) * (size_t)match_count;
                else
                    new_size = content_length -(name_length - replace_length) * (size_t)match_count;
                char *updated = malloc(new_size + 1);
                if (updated != NULL)
                {
                    char *source = content;
                    char *destination = updated;
                    while ((match = strstr(source, name)) != NULL)
                    {
                        printf("match %s\n",match);
                        int starts_word = match == content         || (!isalnum((unsigned char)match[-1]) && match[-1] != '_');
                        int ends_word = match[name_length] == '\0' || (!isalnum((unsigned char)match[name_length]) && match[name_length] != '_');
                        if (starts_word && ends_word)//�p�G�W�ߦr��}�Y�M�������ŦX
                        {
                            size_t before_match = (size_t)(match - source);
                            printf("before_match %d\n",before_match);
                            memcpy(destination, source, before_match);
                            destination += before_match;
                            memcpy(destination, replace, replace_length);
                            destination += replace_length;
                            source = match + name_length;
                        }
                        else
                        {
                            size_t skipped = (size_t)(match - source) + 1;
                            memcpy(destination, source, skipped);
                            destination += skipped;
                            source += skipped;
                        }
                    }
                    strcpy(destination, source);
                    updated[new_size] = '\0';
                    pf = freopen("D:\\VSCODE\\VScode_C_basic_0\\0055_StringSearch\\AA.txt", "wb", pf);
                    if (pf != NULL)
                        fwrite(updated, 1, new_size, pf);
                    free(updated);
                }
            }
        }

        free(content);
    }

    printf("�r�� \"%s\" �b AA.txt ���X�{ %d ���C\n", name, match_count);
    fclose(pf);
    return 0;



}









