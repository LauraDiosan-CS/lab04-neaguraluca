#include "Cheltuiala.h"
#include "Repository.h"
#include "Service.h"
#include "Test.h"
#include "UI.h"
#include <iostream>
#include <string>
#include <string.h>


int main()
{
    UI ui;
    Service serv;
    Repository repo;
    ui.showUI(serv);
    return 0;
}