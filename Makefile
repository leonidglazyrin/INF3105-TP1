CXX=g++ 
C11=--std=c++11
SRC_TAB= $(wildcard *_tableau.cpp)
SRC_ENS= $(wildcard *_ensemble.cpp)
EXEC_TAB= $(wildcard 0*_tableau)
EXEC_ENS= $(wildcard 0*_ensemble)

build: $(SRC_TAB) bonus_tableau.cpp $(SRC_ENS) tp1.cpp
	# $(CXX) $(C11) 01_tableau.cpp -o 01_tableau 
	# $(CXX) $(C11) 02_tableau.cpp -o 02_tableau 
	# $(CXX) $(C11) 03_tableau.cpp -o 03_tableau 
	# $(CXX) $(C11) 04_tableau.cpp -o 04_tableau 
	# $(CXX) $(C11) 05_tableau.cpp -o 05_tableau 
	# $(CXX) $(C11) 06_tableau.cpp -o 06_tableau 
	# $(CXX) $(C11) 07_tableau.cpp -o 07_tableau 
	# $(CXX) $(C11) bonus_tableau.cpp -o bonus_tableau
	# $(CXX) $(C11) 01_ensemble.cpp -o 01_ensemble 
	# $(CXX) $(C11) 02_ensemble.cpp -o 02_ensemble 
	# $(CXX) $(C11) 03_ensemble.cpp -o 03_ensemble 
	$(CXX) $(C11) 04_ensemble.cpp -o 04_ensemble 
	# $(CXX) $(C11) 05_ensemble.cpp -o 05_ensemble 
	# $(CXX) $(C11) 06_ensemble.cpp -o 06_ensemble 
	$(CXX) $(C11) 07_ensemble.cpp -o 07_ensemble 
	$(CXX) $(C11) tp1.cpp -o tp1

tableau: $(EXEC_TAB)
	./01_tableau
	./02_tableau
	./03_tableau
	./04_tableau
	./05_tableau
	./06_tableau
	./07_tableau

bonus: bonus_tableau
	./bonus_tableau

ensemble: $(EXEC_ENS)
	./01_ensemble
	./02_ensemble
	./03_ensemble
	./04_ensemble
	./05_ensemble
	./06_ensemble
	./07_ensemble

tp: tp1
	./tp1 < reseau.txt

full: tableau ensemble tp

clean:
	rm $(EXEC_TAB)
	rm $(EXEC_ENS)
	test -f bonus_tableau && rm bonus_tableau
	test -f tp1 && rm tp1
