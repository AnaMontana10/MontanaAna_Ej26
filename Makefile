all: euler.dat rk4.dat leapfrog.dat plot.png 

plot.png: euler.dat rk4.dat leapfrog.dat MontanaAna_Ej26.py
	python MontanaAna_Ej26.py 

%.dat: MontanaAna_Ej26.x
	./MontanaAna_Ej26.x

MontanaAna_Ej26.x : MontanaAna_Ej26.cpp
	g++ MontanaAna_Ej26.cpp -o MontanaAna_Ej26.x 

clean:
	rm -rf *.x *.dat *.png