#include "copyicons.h"
#include <string.h>
#include <stdio.h>
#include <psp2/io/dirent.h>
#include <psp2/io/fcntl.h>
#include <psp2/io/stat.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/types.h>
#include "pfs.h"
#include "file.h"

static int copy_decrypted_image(const char *app_path, const char *image_name) {
    char src_path[512];
    char dst_path[512];
    char titleid[16];
    const char *last_slash = strrchr(app_path, '/');
    if (!last_slash || strlen(last_slash + 1) > 9) // TitleID is usually 9 chars
        return 0;
    strncpy(titleid, last_slash + 1, sizeof(titleid) - 1);
    titleid[sizeof(titleid) - 1] = '\0';

    snprintf(src_path, sizeof(src_path), "%s/sce_sys/%s", app_path, image_name);
    snprintf(dst_path, sizeof(dst_path), "ur0:appmeta/%s/%s", titleid, image_name);

    // Check if source exists
    if (!checkFileExist(src_path))
        return 0;

    // Check if already exists at destination
    if (checkFileExist(dst_path))
        return 1;

    // Create destination directory if needed
    char meta_path[512];
    snprintf(meta_path, sizeof(meta_path), "ur0:appmeta/%s", titleid);
    createDirectory(meta_path);

    // Try to mount PFS if needed
    int mounted = 0;
    char pfs_path[512];
    snprintf(pfs_path, sizeof(pfs_path), "%s/sce_pfs", app_path);
    if (checkFolderExist(pfs_path)) {
        if (pfsMount(app_path) == 0) {
            mounted = 1;
        }
    }

    int result = copyFile(src_path, dst_path, NULL) == 1 ? 1 : 0;

    if (mounted) {
        pfsUmount();
    }
    return result;
}

int copy_decrypted_icon(const char *app_path) {
    return copy_decrypted_image(app_path, "icon0.png");
}

int copy_decrypted_pic(const char *app_path) {
    return copy_decrypted_image(app_path, "pic0.png");
}
