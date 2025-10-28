#ifndef COPYICONS_FILE_H
#define COPYICONS_FILE_H

int checkFileExist(const char *path);
int checkFolderExist(const char *path);
int createDirectory(const char *path);
int copyFile(const char *src, const char *dst, void *progress_cb);

#endif // COPYICONS_FILE_H
