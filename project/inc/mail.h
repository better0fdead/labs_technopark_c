#ifndef PROJECT_INC_MAIL_H_
#define PROJECT_INC_MAIL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct {
    char *username;
    char *domen;
    char *service;
} mail_t;

mail_t * create_mail(char *username, char *domen, char *service);
int find_mail(char *string, char **username, char **domen, char **service);
void free_mail(mail_t *mail);

#ifdef __cplusplus
};
#endif

#endif  // PROJECT_INC_MAIL_H_

