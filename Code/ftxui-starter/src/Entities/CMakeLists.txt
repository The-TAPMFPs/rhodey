# # List the files to be included here
# set(Entities_FILES
#     Entity.h

#     Troop/Commander.h
#     Troop/Soldier.h
#     Troop/Troop.h

#     Vehicle/Vehicle.h

#     Vehicle/AirVehicle/AirVehicle.h
#     Vehicle/AirVehicle/Bomber.h
#     Vehicle/AirVehicle/CargoPlane.h
#     Vehicle/AirVehicle/Fighterjet.h

#     Vehicle/GroundVehicle/GroundVehicle.h
#     Vehicle/GroundVehicle/Tank.h
#     Vehicle/GroundVehicle/Truck.h

#     Vehicle/WaterVehicle/CargoShip.h
#     Vehicle/WaterVehicle/Carrier.h
#     Vehicle/WaterVehicle/Submarine.h
#     Vehicle/WaterVehicle/Warship.h
#     Vehicle/WaterVehicle/WaterVehicle.h

#     WeaponTemplateMethod/Weapon.h
# )

# add_library(Entities STATIC ${Entities_FILES})

# set_target_properties(Entities PROPERTIES LINKER_LANGUAGE CXX)