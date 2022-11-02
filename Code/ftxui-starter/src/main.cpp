#include "UI.h"
#include "War/WarPhases/Dispute.h"

using namespace ftxui;

int main(int argc, const char* argv[]) {

    WarPhase* startPhase = new Dispute();

    War* war = new War(startPhase);

    UI* ui = new UI(war);

    ui->startSim();

    delete war;
    delete ui;
}