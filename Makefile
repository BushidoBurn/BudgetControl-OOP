budget: main.o expense.o fixedexpense.o discretionaryexpense.o manager.o
	g++ -std=c++17 main.o expense.o fixedexpense.o discretionaryexpense.o manager.o -o budget

main.o: main.cpp
	g++ -std=c++17 -c main.cpp

expense.o: expense.cpp
	g++ -std=c++17 -c expense.cpp

fixedexpense.o: fixedexpense.cpp
	g++ -std=c++17 -c fixedexpense.cpp

discretionaryexpense.o: discretionaryexpense.cpp
	g++ -std=c++17 -c discretionaryexpense.cpp

manager.o: manager.cpp
	g++ -std=c++17 -c manager.cpp

clean:
	rm *.o budget