#include "War.h"
#include "WarPhases/Dispute.h"

std::string War::warState = "UNSET_WAR_STATE";
std::string War::warStateDesc = "UNSET_WAR_STATE_DESC";
std::vector<std::string> War::warStateThumbnail;
ftxui::Color War::warStateThumbnailColor = ftxui::Color::Yellow1;

War::War() : frameCount(0), warPhase(new Dispute()) {

  this->warPhase = new Conflict();
  teamA = new Alliance("Side A", true);
  teamB = new Alliance("Side B", false);

  // TODO: Replace with properly initialized data
  teamA->add(new Country("country A"));
  teamA->add(new Country("country B"));
  teamA->add(new Country("country C"));
  teamA->add(new Country("country D"));
  teamB->add(new Country("country E"));
  teamB->add(new Country("country F"));
  teamB->add(new Country("country G"));
  teamB->add(new Country("country H"));

  map = new Map(getAllCountries());
}

War::~War() {
  delete warPhase;
  delete teamA, teamB;
}

//Returns a homogenous vector of all countries from both alliances
std::vector<Country*> War::getAllCountries()
{
  std::vector<Country*> membersA = teamA->getMembers(), membersB = teamB->getMembers();
  std::vector<Country*> res;
  res.insert(res.end(), membersA.begin(), membersA.end());
  res.insert(res.end(), membersB.begin(), membersB.end());

  return res;
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

//Returns null if the Country is not bound to an alliance
Alliance* War::getSideCountryIsOn(Country* country)
{
  return teamA->containsCountry(country) ? teamA :
        (teamB->containsCountry(country) ? teamB : nullptr);
}

float War::getTravelDifficulty(MapCoords from, MapCoords to, bool teamA)
{
  return this->map->getTravelDifficulty(from, to, teamA);
}
