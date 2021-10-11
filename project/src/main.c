#include "stdio.h"
#include "../inc/mail.h"
#include "../inc/errors.h"

int main() {
    char bad_example[50];
    mail_t *mail = NULL;
    char *us = NULL;
    char *ser = NULL;
    char *dom = NULL;
    scanf("%s", bad_example);
    int flag = find_mail(bad_example, &us, &ser, &dom);
    if (flag != OK) {
        return flag;
    }
    mail = create_mail(us, ser, dom);
    printf("%s %s %s\n", mail->username, mail->service, mail->domen);
    free_mail(mail);
    return 0;
}
