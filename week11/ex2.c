#include <stdio.h>
#include <dirent.h>
  
int main() {
    struct dirent *dp;
    DIR *dirp = opendir("/");
    while ((dp = readdir(dirp)) != NULL) { // read while can
            printf("%s ", dp->d_name);
    }
    closedir(dirp);    
}
