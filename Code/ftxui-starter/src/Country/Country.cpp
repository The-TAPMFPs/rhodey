#include "Country.h"

unsigned int Country::sizeOfArmy() //TODO: Calculate based off of troops
{
    return 0;
}
unsigned int Country::prowessInRegion(Region* region)
{
    return 0;
}

Country::Country(std::string name) : name(name) {
    population = 0;
    economy = 0;
    morale = 0;
    resources = 0;
    research = 0;
    aggressiveness = 0;
    goalRating = 0;
    numSpies = 0;
    numTroops = 0;
    numVehicles = 0;
    numEnemyRegions = 0;
    generatePersonalityMatrix();
}

std::string Country::getName()
{
    return this->name;
}

void Country::generatePersonalityMatrix()
{
    Eigen::MatrixXd pm(6, 18);
    double* offensiveVals = generateRandomNums(4);
    double* defensiveVals = generateRandomNums(4);
    double* developVals = generateRandomNums(3);
    double* prepVals = generateRandomNums(3);
    double* intelVals = generateRandomNums(1);
    double* diploVals = generateRandomNums(4);

    pm <<
        offensiveVals[0], 0, offensiveVals[1], 0, 0, 0, 0, 0, 0, offensiveVals[2], 0, 0, offensiveVals[3], 0, 0, 0, 0, 0, //offensive
        defensiveVals[0], 0, defensiveVals[1], 0, 0, 0, 0, 0, 0, defensiveVals[2], 0, 0, defensiveVals[3], 0, 0, 0, 0, 0, //defensive
        0, 0, 0, 0, 0, developVals[0], 0, developVals[1], 0, 0, 0, 0, 0, 0, 0, 0, 0, developVals[2], //development
        0, prepVals[0], 0, prepVals[1], prepVals[2], 0, 0, prepVals[3], 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //preparation
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, intelVals[0], 0, 0, 0, 0, 0, 0, //intel
        0, 0, 0, 0, 0, diploVals[0], 0, diploVals[1], 0, 0, 0, 0, 0, diploVals[2], diploVals[3], 0, 0, 0; //diplomacy

    this->personalityMatrix = pm;
}

Eigen::MatrixXd Country::generateValueMatrix()
{
    Eigen::MatrixXd valMatrix(18, 1);
    valMatrix <<
        numTroops/(0.3*population),
        1-(numTroops/(0.3*population)),
        numVehicles/(numTroops/10),
        1-(numVehicles/(numTroops/10)),
        economy,
        1-economy,
        resources,
        1-resources,
        morale,
        1-morale,
        numSpies/(numEnemyRegions/5),
        1-(numSpies/(numEnemyRegions/5)),
        aggressiveness,
        1-aggressiveness,
        goalRating,
        1-goalRating,
        research,
        1-research;

        return valMatrix;
}


double* Country::generateRandomNums(int num)
{
    srand((unsigned)time(NULL));

    double* vals = new double[num];
    double sum=0;
	for(int i = 0; i<num; i++)
	{
		vals[i] = (double) rand()/RAND_MAX;//array initialisation
        sum+=vals[i];
	}

    for(int i = 0; i<num; i++)
	{
		vals[i] /= sum;
	}

	return vals; 

}

void Country::setStrategy(BattleStrategy* strategy)
{
    this->strategy = strategy;
}

int Country::nextStrategy()
{
    Eigen::MatrixXd valMatrix = generateValueMatrix();
    Eigen::MatrixXd pm = this->personalityMatrix;
    Eigen::MatrixXd result = pm*valMatrix;
    int maxIndex = 0;
    double maxVal = 0;
    for(int i = 0; i<result.rows(); i++)
    {
        if(result(i,0) > maxVal)
        {
            maxVal = result(i,0);
            maxIndex = i;
        }
    }
    return maxIndex;
}



void Country::takeTurn()
{
    /* int nextStrat = nextStrategy();

    switch(nextStrat)
    {
        case 0:
            this->strategy = new Offensive(red);
            break;
         case 1:
            this->strategy = new Defensive();
            break;
        case 2:
            this->strategy = new ResearchAndDevelopment();
            break;
        case 3:
            this->strategy = new PreparationStrategy();
            break;
        case 4:
            this->strategy = new IntelligenceStrategy();
            break;
        case 5:
            this->strategy = new DiplomacyStrategy();
            break; 
        default:
            this->strategy = new Offensive(red);
            break;
    } */
    
}