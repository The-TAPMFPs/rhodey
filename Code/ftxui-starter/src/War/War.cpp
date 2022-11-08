#include "War.h"
#include "WarPhases/Dispute.h"

std::string War::warState = "UNSET_WAR_STATE";
std::string War::warStateDesc = "UNSET_WAR_STATE_DESCRIPTION";
Narrative War::narrative;
std::vector<std::string> War::warStateThumbnail;
ftxui::Color War::warStateThumbnailColor = ftxui::Color::Yellow1;



War::War(): stepCount(0) {

  std::string countryNames[] = { "Puvir Theblicri", "Ncentruba", "Slandswait", "Lei Serthernsal", "Ilis Ekeelingpa", "Jimamaarcoca", "Naikongpri", "Luar Jesintco Island", "Pusouthcoi", "Bulso Nanuazue", "Ribouand", "Western Khstantomemo", "Rosman", "Estanprus", "Negi", "Liakitts Andri", "Sloni Liebacastan", "Narugam", "Lecua Territories", "Honre", "Guila", "Masouthbourg", "Cathern Brulandspit", "There Dorrusjo", "United Ghagear", "Newmayotteca", "Francei", "Rabda", "Xemnam Gote", "Apupierre", "New Menga", "Tico", "Belibritishriaviet", "Tarbeniue Island", "Dora Lizely", "Janneslands", "Guaylipnia", "Folkdonablic Kingdom", "Chadgrothernblic", "Scotlo Ainited", "Coswa", "Corepeda", "Leran Niaporegui", "Riarygin", "Croaco Andrezi", "Popines Pupatu", "Nitedpuboruza", "Nearwan", "Tswanga", "Syu Landstan", "North Radianlkland", "Maverde", "Rigal", "Lyna Gianame", "Sierbaninsomas", "Ciali Aandso", "Georgeri Isles", "Ata Bani", "Masrkey Nesena", "Layki", "Zamaurina", "Chtenji Nemaco", "Linitedtu", "Biamar Tzerbo", "Kephi", "Tanand", "Wanni Wedia", "Tervathe", "Gualand Finrii", "Chellesra Nticardesh", "Toslands Dapuagreen", "Quei Seyimoa", "Dorstriaro", "Bunafasiabon", "Ribliclands", "Isslandsleone", "Saubai Ofriahrain", "Riasaintsri", "Withethai", "Morsaint Ire", "Statesne Kibabweti Isles", "Ngoslandla", "Tainorgogia", "Zeslands Fiadan", "Tudia Andbri", "Slandsguam Landrunslands", "Rebelbia", "Towaytvia", "Landtana", "Brali Rusland", "Lauwalesguya", "Zbelavidos", "Restan", "Northto", "Nyapo", "Tablic Hermence", "Vica", "Neu", "Soueng Lage", "Vaki Ngonorla" };
  int CountryStartIndex = uuid::randomInt(0, 100);

  teamA = new Alliance("Side A", true);
  teamB = new Alliance("Side B", false);
  teamA->setEnemyAlliance(teamB);
  teamB->setEnemyAlliance(teamA);

  teamA->add(new Country(countryNames[CountryStartIndex++]));
  teamA->add(new Country(countryNames[CountryStartIndex++]));
  teamA->add(new Country(countryNames[CountryStartIndex++]));
  teamA->add(new Country(countryNames[CountryStartIndex++]));
  teamA->add(new Country(countryNames[CountryStartIndex++]));

  teamB->add(new Country(countryNames[CountryStartIndex++]));
  teamB->add(new Country(countryNames[CountryStartIndex++]));
  teamB->add(new Country(countryNames[CountryStartIndex++]));
  teamB->add(new Country(countryNames[CountryStartIndex++]));
  teamB->add(new Country(countryNames[CountryStartIndex++]));

  //Build war narrative
  NarrativeDirector* director = new NarrativeDirector(teamA, teamB);
  switch(uuid::randomInt(0, 5))
  {
    case 0:
      this->narrative = director->makeEconomicNarrative();
      break;

    case 1:
      this->narrative = director->makeTerritorialNarrative();
      break;

    case 2:
      this->narrative = director->makeRevengeNarrative();
      break;

    case 3:
      this->narrative = director->makeReligiouslNarrative();
      break;

    default:
      this->narrative = director->makePoliticalNarrative();
      break;
  }

  delete director;

  //Set start state
  this->warPhase = new Dispute();


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
  Alliance* team = (stepCount%2?this->teamA:this->teamB);
  Country* c = team->getMemberModuloSize(stepCount/2);

  if(c != nullptr)
  {
    c->takeTurn(); //TODO: Fix Floating point exception
  }

  this->stepCount++;
}

//Called when there is an input event from the UI
bool War::onEvent(ftxui::Event e)
{
  return false;
}

int War::getStepCount()
{
  return this->stepCount;
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

//Returns null if the Country is not bound to an alliance
Alliance* War::getSideCountryIsOn(Country* country)
{
  return teamA->containsCountry(country) ? teamA :
        (teamB->containsCountry(country) ? teamB : nullptr);
}

Map* War::getMap()
{
  return this->map;
}

Country* War::getCountryInAllianceWithHighestTroopCount(bool teamA)
{
  vector<Country*> teamMembers = (teamA ? this->teamA : this->teamB)->getMembers();
  OccupancyTable* oc = this->map->getOccupancyTable();

  int max = -1;
  Country* maxC = nullptr;

  for(auto c = teamMembers.begin(); c != teamMembers.end(); c++)
  {
    int numT = oc->getNumTroops(*c);

    if(numT > max)
    {
      max = numT;
      maxC = *c;
    }
  }

  return maxC;
}

Country* War::getCountryInAllianceWithHighestVehicleCount(bool teamA)
{
  vector<Country*> teamMembers = (teamA ? this->teamA : this->teamB)->getMembers();
  OccupancyTable* oc = this->map->getOccupancyTable();

  int max = -1;
  Country* maxC = nullptr;

  for(auto c = teamMembers.begin(); c != teamMembers.end(); c++)
  {
    int numV = oc->getNumVehicles(*c);

    if(numV > max)
    {
      max = numV;
      maxC = *c;
    }
  }

  return maxC;
}