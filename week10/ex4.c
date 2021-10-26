#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include "string.h"
int main() {
    DIR *dirp = opendir("tmp/");
    struct dirent *dp;
    struct stat st;
    if (dirp == NULL) {
        printf("The directory /tmp/ cannot be opened!\n");
        return 1;
    }
    printf("File --- Hard Links\n");
    while ((dp = readdir(dirp)) != NULL) {
        char file_path[256] = "tmp/";
        DIR *dirp_i = opendir(file_path);
        strcat(file_path, dp->d_name);
        stat(file_path, &st);

        struct dirent *dp_i;
        struct stat st_i;
        int link_cnt = 0;
        char *filenames[256];
        while ((dp_i = readdir(dirp_i)) != NULL) {
            char file_path_i[256] = "tmp/";
            strcat(file_path_i, dp_i->d_name);
            stat(file_path_i, &st_i);
            if (st.st_ino == st_i.st_ino) {
                filenames[link_cnt] = dp_i->d_name;
                link_cnt++;
            }
        }
        closedir(dirp_i);
        if (link_cnt >= 2) {
            printf("%s --- ", dp->d_name);
            for (int i = 0; i < link_cnt - 1; i++) {
                printf("%s, ", filenames[i]);
            }
            printf("%s \n", filenames[link_cnt - 1]);
        }
    }
    closedir(dirp);
}
