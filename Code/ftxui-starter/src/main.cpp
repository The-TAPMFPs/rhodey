#include "UI.h"
#include "War/WarPhases/Dispute.h"

using namespace ftxui;

int main(int argc, const char* argv[]) {

    War* war = new War();

    UI* ui = new UI(war);

    ui->startSim();

    delete war;
    delete ui;
}