#include "UI.h"
#include "War/WarPhases/Dispute.h"

int main(int argc,char* argv[]) {

    WarPhase* startPhase = new Dispute();

    War* war = new War(startPhase);

    UI* ui = new UI(war);

    //ui->startSim();

    delete war;
    delete ui;
}
