#include "UI.h"

using namespace ftxui;

int main(int argc, const char* argv[]) {
    War* war = new War();

    UI* ui = new UI(war);

    ui->render();

    delete war;
    delete ui;
}