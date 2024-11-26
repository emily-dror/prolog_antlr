/*
* has(num, list)
* num is the number we are looking for in the list
*/
has(X,[X|Y]).
has(X,[Z|Y]) :- has(X,Y).
