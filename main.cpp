#include "BankService.h"

int main() {
    BankService service("data/accounts.txt");
    service.run();
    return 0;
}
