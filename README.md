# LFA
Automatul este definit in fisierul "automat.txt"
considerand ca fisierul contine n linii, structura fisierului "automat.txt" :
linia 1:         Starea initiala
liniile 2->n-1 : "x l y"           /// muchie de la starea x la starea y cu litera l
linia n:         "x1 x2 x3 ... xk" /// starile finale separate printr-un spatiu


Cuvantul pe care vrem sa il verificam se afla in fisierul "input.txt"

Rezultatul se va afla in fisierul "output.txt" -> care ne spune daca cuvantul este acceptat sau nu
In cazul in care cuvantul este acceptat se va afisa pe urmatoarea linie si drumul parcurs pentru validarea acestuia
