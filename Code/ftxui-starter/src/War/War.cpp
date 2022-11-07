#include "War.h"
#include "WarPhases/Dispute.h"

std::string War::warState = "UNSET_WAR_STATE";
std::string War::warStateDesc = "UNSET_WAR_STATE_DESCRIPTION";
Narrative War::narrative;
std::vector<std::string> War::warStateThumbnail;
ftxui::Color War::warStateThumbnailColor = ftxui::Color::Yellow1;

std::string countryNames[] = { "Puvir Theblicri", "Ncentruba", "Slandswait", "Lei Serthernsal", "Ilis Ekeelingpa", "Jimamaarcoca", "Naikongpri", "Luar Jesintco Island", "Pusouthcoi", "Bulso Nanuazue", "Ribouand", "Western Khstantomemo", "Rosman", "Estanprus", "Negi", "Liakitts Andri", "Sloni Liebacastan", "Narugam", "Lecua Territories", "Honre", "Guila", "Masouthbourg", "Cathern Brulandspit", "There Dorrusjo", "United Ghagear", "Newmayotteca", "Francei", "Rabda", "Xemnam Gote", "Apupierre", "New Menga", "Tico", "Belibritishriaviet", "Tarbeniue Island", "Dora Lizely", "Janneslands", "Guaylipnia", "Folkdonablic Kingdom", "Chadgrothernblic", "Scotlo Ainited", "Coswa", "Corepeda", "Leran Niaporegui", "Riarygin", "Croaco Andrezi", "Popines Pupatu", "Nitedpuboruza", "Nearwan", "Tswanga", "Syu Landstan", "North Radianlkland", "Maverde", "Rigal", "Lyna Gianame", "Sierbaninsomas", "Ciali Aandso", "Georgeri Isles", "Ata Bani", "Masrkey Nesena", "Layki", "Zamaurina", "Chtenji Nemaco", "Linitedtu", "Biamar Tzerbo", "Kephi", "Tanand", "Wanni Wedia", "Tervathe", "Gualand Finrii", "Chellesra Nticardesh", "Toslands Dapuagreen", "Quei Seyimoa", "Dorstriaro", "Bunafasiabon", "Ribliclands", "Isslandsleone", "Saubai Ofriahrain", "Riasaintsri", "Withethai", "Morsaint Ire", "Statesne Kibabweti Isles", "Ngoslandla", "Tainorgogia", "Zeslands Fiadan", "Tudia Andbri", "Slandsguam Landrunslands", "Rebelbia", "Towaytvia", "Landtana", "Brali Rusland", "Lauwalesguya", "Zbelavidos", "Restan", "Northto", "Nyapo", "Tablic Hermence", "Vica", "Neu", "Soueng Lage", "Vaki Ngonorla" };

War::War(): frameCount(0) {
  teamA = new Alliance("Side A");
  teamB = new Alliance("Side B");

  // TODO: Replace with properly initialized data
  teamA->add(new Country("country A"));
  teamA->add(new Country("country B"));
  teamA->add(new Country("country C"));
  teamA->add(new Country("country D"));
  teamB->add(new Country("country E"));
  teamB->add(new Country("country F"));
  teamB->add(new Country("country G"));
  teamB->add(new Country("country H"));

  //Build war narrative
  NarrativeDirector* director = new NarrativeDirector(teamA, teamB);
  this->narrative = director->makeTerritorialNarrative(); //TODO: Randomize this
  delete director;

  //Set start state
  this->warPhase = new Dispute();


  map = new Map();
}

War::~War() {
  delete warPhase;
  delete teamA, teamB;
}

//The main simulation loop
void War::step()
{
  //Get alliance/country whose turn it is now
  Alliance* team = (frameCount%2?this->teamA:this->teamB);
  Country* c = team->getMemberModuloSize(frameCount/2);

  if(c != nullptr)
  {
    c->morale = frameCount;
    // c->takeTurn(); //TODO: Fix Floating point exception
  }

  frameCount++;
}

//Called when there is an input event from the UI
bool War::onEvent(ftxui::Event e)
{
  return false;
}

void War::transitionTo(WarPhase* warPhase) {
  // TODO: Fix, something is segfaulting in here!
  if (this->warPhase) {
    delete this->warPhase;
  }

  this->warPhase = warPhase;
}

void War::addCountryToSideA(Country* country) {
  teamA->add(country);
}

void War::addCountryToSideB(Country* country) {
  teamB->add(country);
}

void War::changeState() {
  warPhase->handleWarChange(this);
}

void War::start() {
  teamA->print();
  teamB->print();
  // TODO start the war
}

bool War::isOver() {
  return warPhase == NULL;
}

MapData War::getCurrentMapData() {
  return this->map->getCurrentMapData();
}

Region* War::getRegionAt(int x, int y)
{
  return this->map->getRegionAt(x, y);
}