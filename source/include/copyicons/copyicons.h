#ifndef COPYICONS_H
#define COPYICONS_H

#ifdef __cplusplus
extern "C" {
#endif

// Copies decrypted icon0.png from app_path to ur0:appmeta. Returns 1 on success, 0 on failure.
int copy_decrypted_icon(const char *app_path);
// Copies decrypted pic0.png from app_path to ur0:appmeta. Returns 1 on success, 0 on failure.
int copy_decrypted_pic(const char *app_path);

#ifdef __cplusplus
}
#endif

#endif // COPYICONS_H
