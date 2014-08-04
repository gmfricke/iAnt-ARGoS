#ifndef CPFA_H_
#define CPFA_H_

/* Make use of ARGoS cross platform representation of primitive data types. */
#include <argos3/core/utility/datatypes/datatypes.h>
/* ARGoS implementation of 2D vector and Cartesian coordinates. */
#include <argos3/core/utility/math/vector2.h>
/* Access XML loading functionality. */
#include <argos3/core/utility/configuration/argos_configuration.h>

/* access to Argos3 classes and objects */
using namespace argos;
/* access to std::endl and std::vector, etc. */
using namespace std;

class CPFA {

public:

	/* Primary state definitions for the CPFA. */
	enum STATE {
        SET_SEARCH_LOCATION = 0,
        TRAVEL_TO_SEARCH_SITE,
        PERFORM_INFORMED_WALK,
        PERFORM_UNINFORMED_WALK,
        SENSE_LOCAL_RESOURCE_DENSITY,
        TRAVEL_TO_NEST
	};

	/* Constructor/Destructor functions. */
	CPFA();
	~CPFA();

	/* XML configuration initializer. */
	void Init(TConfigurationNode& node);

	/* Just a thought, but you may make these private and add
	 * a function "changeState()" which calls the appropriate
	 * function from the list below... */
	/* CPFA state machine implementation functions */
	void setSearchLocation();
	void travelToSearchSite();
	void performInformedWalk();
	void performUninformedWalk();
	void senseLocalResourceDensity();
	void travelToNest();

private:

    /* NOTE: until my understanding improves, below comments may not be accurate */
	Real     travelProbability;           // %-chance of traveling, from [0.0, 1.0]
	Real     searchProbability;           // %-chance of searching, from [0.0, 1.0]
	CRadians uninformedSearchCorrelation; // radian angle turned during searching [0.0, 4.0PI]
	Real     informedSearchDecay;         // %-rate that informed search decays [0.0, 5.0]
	Real     siteFidelityRate;            // %-chance that robot remembers a site [0.0, 20.0]
	Real     pheromoneRate;               // %-chance of laying a pheromone [0.0, 20.0]
	Real     pheromoneDecayRate;          // %-rate that pheromones decay [0.0, 10.0]
	STATE    state;                       // the current state of the state-not-state machine

};

#endif /* CPFA_H_ */