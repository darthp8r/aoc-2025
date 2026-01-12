#include <aoc2025.h>

#include "file_to_list.h"

#include "bdd-for-c.h"

spec("file_to_list") {
  static list_t *subject = NULL;

  describe("dunsels") {
    before() {
      subject = file_to_list("spec/support_spec/file_to_list.txt");
    }

    it("three lines") {
      check(subject->next->next->next == NULL);
    }

    it("separates lines") {
      check(!(strcmp("payter", subject->text)));
      check(!(strcmp("is a", subject->next->text)));
      check(!(strcmp("hosehead", subject->next->next->text)));
    }
  }
}

