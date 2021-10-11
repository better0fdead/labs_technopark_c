#include <gtest/gtest.h>
#include "../project/inc/errors.h"
#include "../project/inc/mail.h"


TEST(find_mail, NO_DOT) {
  char bad_example[50] = "wedh2011@mailcom\0";
  char *us = NULL;
  char *ser = NULL;
  char *dom = NULL;
  EXPECT_EQ(find_mail(bad_example, &us, &ser, &dom), NOT_FOUND);
}

TEST(find_mail, NO_SOBACHKA_IN_INPUT) {
  char bad_example[50] = "wedh2011mail.com\0";
  char *us = NULL;
  char *ser = NULL;
  char *dom = NULL;
  EXPECT_EQ(find_mail(bad_example, &us, &ser, &dom), NOT_FOUND);
}

TEST(find_mail, INVALID_INPUT) {
  char bad_example[50] = "wedh2011.mail@com\0";
  char *us = NULL;
  char *ser = NULL;
  char *dom = NULL;
  EXPECT_EQ(find_mail(bad_example, &us, &ser, &dom), INVALID_FORMAT);
}

TEST(find_mail, GOOD_INPUT) {
  char bad_example[50] = "wedh2011@mail.com\0";
  char *us = NULL;
  char *ser = NULL;
  char *dom = NULL;
  EXPECT_EQ(find_mail(bad_example, &us, &ser, &dom), OK);
  free(us);
  free(ser);
  free(dom);
}

TEST(create_mail, GOOD_INPUT) {
  char us[50] = "wedh2011\0";
  char ser[50] = "mail\0";
  char dom[50] = "ru\0";
  mail_t *mail = NULL;
  mail = create_mail(us, dom, ser);
  EXPECT_EQ(strcmp(mail->username, us), 0);
  EXPECT_EQ(strcmp(mail->domen, dom), 0);
  EXPECT_EQ(strcmp(mail->service, ser), 0);
  free_mail(mail);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}