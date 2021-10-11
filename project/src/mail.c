#include "../inc/mail.h"
#include "../inc/errors.h"

int process_username(mail_t *mail, char *username) {
    mail->username = (char *)malloc(strlen(username) * sizeof(char) + 2);
    if (mail->username == NULL)
        return MEM_ALLOC_ERROR;
    snprintf(mail->username, strlen(username) + 1, "%s", username);
    mail->username[strlen(username) + 1] = '\0';
    return OK;
}

int process_service(mail_t *mail, char *service) {
    mail->service = (char *)malloc(strlen(service) * sizeof(char) + 2);
    if (mail->service == NULL)
        return MEM_ALLOC_ERROR;
    snprintf(mail->service, strlen(service) + 1, "%s", service);
    mail->service[strlen(service) + 1] = '\0';
    return OK;
}

int process_domen(mail_t *mail, char *domen) {
    mail->domen = (char *)malloc(strlen(domen) * sizeof(char) + 2);
    if (mail->domen == NULL)
        return MEM_ALLOC_ERROR;
    snprintf(mail->domen, strlen(domen) + 1, "%s", domen);
    mail->domen[strlen(domen) + 1] = '\0';
    return OK;
}

int find_username(char *string, char **username) {
    size_t pos_user = strcspn(string, "@");
    if (pos_user == strlen(string))
        return NOT_FOUND;
    *username = (char *)malloc(sizeof(char) * pos_user + 1);
    if (username == NULL)
        return MEM_ALLOC_ERROR;
    snprintf(*username, pos_user + 1, "%s", string);
    return OK;
}

int find_service(char *string, char **service) {
    size_t pos_user = strcspn(string, "@");
    size_t pos_ser = strcspn(string, ".");
    if (pos_ser < pos_user)
        return INVALID_FORMAT;
    if (pos_ser == strlen(string))
        return NOT_FOUND;
    *service = (char *)malloc(sizeof(char) * pos_ser+ 1);
    if (service == NULL)
        return MEM_ALLOC_ERROR;
    strncpy(*service, string + pos_user + 1, pos_ser - pos_user - 1);
    return OK;
}

int find_domen(char *string, char **domen) {
    size_t pos_ser = strcspn(string, ".");
    if (pos_ser == strlen(string))
        return NOT_FOUND;
    *domen = (char *)malloc(sizeof(char) * strlen(string) - pos_ser);
    if (domen == NULL)
        return MEM_ALLOC_ERROR;
    strncpy(*domen, string + pos_ser + 1, strlen(string) - pos_ser);
    return OK;
}


int find_mail(char *string, char **username, char **domen, char **service) {
    int flag = OK;
    flag = find_username(string, username);
    if (flag != OK)
        return flag;
    flag = find_service(string, service);
    if (flag != OK) {
        free(*username);
        return flag;
    }
    flag = find_domen(string, domen);
    if (flag != OK) {
        free(*service);
        free(*username);
        return flag;
    }
    return OK;
}

mail_t * create_mail(char *username, char *domen, char *service) {
    mail_t *mail;
    mail = (mail_t *)malloc(sizeof(mail_t));
    mail->username = NULL;
    mail->domen = NULL;
    mail->service = NULL;
    if (process_username(mail, username) == MEM_ALLOC_ERROR) {
        free(mail);
        return NULL;
    }
    if (process_service(mail, service) == MEM_ALLOC_ERROR) {
        free(mail->username);
        free(mail);
        return NULL;
    }
    if (process_domen(mail, domen) == MEM_ALLOC_ERROR) {
        free(mail->username);
        free(mail->service);
        free(mail);
        return NULL;
    }
    return mail;
}


void free_mail(mail_t *mail) {
    free(mail->username);
    free(mail->domen);
    free(mail->service);
    free(mail);
}
