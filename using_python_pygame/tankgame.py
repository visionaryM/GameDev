from tank import Tank
alice = Tank("Alice")
bob = Tank("Bob")
carol = Tank("Carol")
tanks = [alice, bob, carol]
alive_tanks = len(tanks)
while alive_tanks>1:
    for ele in tanks:
        print(ele)
    try:
        first_tank = input("Who fires? ")
        second_tank = input("Who at? ")
        if not first_tank.alive or not second_tank.alive:
            print("One on those tank is dead")
            continue
        print("*"*30)
        first_tank.fire_at(second_tank)
        if not second_tank.alive:
            alive_tanks -= 1
        print("*"*30)
    except Exception as e:
        print(e)
for tank in tanks:
    if tank.alive:
        print("%s is the winner"%tank.name)
        break