#include "War.h"
#include "WarPhases/Dispute.h"

/**
 * \property string warState
 * \brief The current state of the war
 */
/**
 * \property string warStateDesc
 * \brief Description of the events of the current war state
 */
/**
 * \property std::vector<string> warStateThumbnail
 * \brief A graphic to decorate the current cutscene
 */
/**
 * \property ftxui::Color warStateThumbnailColor
 * \brief The colour of the graphic to decorate the current cutscene
 */
std::string War::warState = "UNSET_WAR_STATE";
std::string War::warStateDesc = "UNSET_WAR_STATE_DESC";
std::vector<std::string> War::warStateThumbnail;
ftxui::Color War::warStateThumbnailColor = ftxui::Color::Yellow1;

/**
 * \fn War ()
 * \brief constructor for the War class, adds countries. Defualt War State is 'Dispute' State
 *
 */
War::War(): frameCount(0), warPhase(new Dispute()) {
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

  map = new Map();
}

/**
 * \fn War ()
 * \brief constructor for the War class, adds countries to the war.
 *
 * \param warPhase sets the war phase of the war
 */
War::War(WarPhase* warPhase) : warPhase(warPhase) {
  // TransitionTo(warPhase); //REMOVED: for now, re-add later
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

  map = new Map();
}

/**
 * \fn ~War ()
 * \brief destructor for the War class. Deletes the map, warPhase and teams, but not the War.
 *
 */
War::~War() {
  delete map;
  delete warPhase;
  delete teamA, teamB;
}

/**
 * \fn void step ()
 * \brief The main simulation loop, Simulates a "turn" of the war
 */
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

/**
 * \fn bool onEvent (Event e)
 * \brief Called when there is an input event from the UI
 * 
 * \param e The event that occured
 * \return a false bool
 */
bool War::onEvent(ftxui::Event e)
{
  return false;
}

/**
 * \fn void transitionTo (WarPhase* warPhase)
 * \brief Transitions the war to the specified war phase
 * 
 * \param warPhase The new war phase
 */
void War::transitionTo(WarPhase* warPhase) {
  // TODO: Fix, something is segfaulting in here!
  if (this->warPhase) {
    delete this->warPhase;
  }

  this->warPhase = warPhase;
}

/**
 * \fn void addCountryToSideA (Country* country)
 * \brief Adds a country to the side A of the war
 * 
 * \param country The country to add
 */
void War::addCountryToSideA(Country* country) {
  teamA->add(country);
}

/**
 * \fn void addCountryToSideB (Country* country)
 * \brief Adds a country to the side B of the war
 * 
 * \param country The country to add
 */
void War::addCountryToSideB(Country* country) {
  teamB->add(country);
}

/**
 * \fn void changeState ()
 * \brief handles a change in the state of the war
 * 
 */
void War::changeState() {
  warPhase->handleWarChange(this);
}

/**
 * \fn void printSides ()
 * \brief Prints the 2 sides of the war
 * 
 */
void War::start() {
  teamA->print();
  teamB->print();
  // TODO start the war
}

/**
 * \fn boolean isOver ()
 * \brief Checks if the war is over
 * 
 * \return true if the war is over, false otherwise
 */
bool War::isOver() {
  return warPhase == NULL;
}

/**
 * \fn MapData getCurrentMapData ()
 * \brief gets a struct representing the current map
 * 
 * \return a MapData struct representing the current map
 */
MapData War::getCurrentMapData() {
  return this->map->getCurrentMapData();
}

/**
 * \fn Region* getRegionAt (int x, int y)
 * \brief gets the region at the specified coordinates
 * 
 * \return the region at the specified coordinates
 */
Region* War::getRegionAt(int x, int y)
{
  return this->map->getRegionAt(x, y);
}