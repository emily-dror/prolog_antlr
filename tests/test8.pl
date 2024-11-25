/*
* is_ascending(List)
* num is the number we are looking for in the list
*/
is_ascending([]).
is_ascending([X]).
is_ascending([X | [Y | Z]]) :- 
    Y >= X.







