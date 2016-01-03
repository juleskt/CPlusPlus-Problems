GCC = g++

PA3: PA4.o CartPoint.o CartVector.o Cave.o CoralReef.o Fish.o GameCommand.o GameObject.o Model.o View.o Tuna.o Shark.o Sharknado.o
	$(GCC) PA4.o CartPoint.o CartVector.o Cave.o CoralReef.o Fish.o GameCommand.o GameObject.o Model.o View.o Tuna.o Shark.o Sharknado.o -o PA4

PA3.o: PA4.cpp
	$(GCC) -c PA4.cpp

CartPoint.o: CartPoint.cpp
	$(GCC) -c CartPoint.cpp

CartVector.o: CartVector.cpp
	$(GCC) -c CartVector.cpp

Cave.o: Cave.cpp
	$(GCC) -c Cave.cpp

CoralReef.o: CoralReef.cpp
	$(GCC) -c CoralReef.cpp

Fish.o: Fish.cpp
	$(GCC) -c Fish.cpp

GameCommand.o: GameCommand.cpp
	$(GCC) -c GameCommand.cpp

GameObject.o: GameObject.cpp
	$(GCC) -c GameObject.cpp

Model.o: Model.cpp
	$(GCC) -c Model.cpp

View.o: View.cpp
	$(GCC) -c View.cpp

Tuna.o: Tuna.cpp
	$(GCC) -c Tuna.cpp

Shark.o: Shark.cpp
	$(GCC) -c Shark.cpp

Sharknado.o: Sharknado.cpp
	$(GCC) -c Sharknado.cpp

clean:
	rm PA3.o CartPoint.o CartVector.o Cave.o CoralReef.o Fish.o GameCommand.o GameObject.o Model.o View.o Tuna.o Shark.o Sharknado.o PA4
