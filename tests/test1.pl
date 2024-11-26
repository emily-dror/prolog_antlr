vertex(v1).
vertex(v2).
vertex(v3).
vertex(v4).
vertex(v5).
vertex(v6).

edge(v1,v2).
edge(v1,v3).
edge(v3,v4).
edge(v1,v4).


/*
* dfs(S,D), S - source, D - dest
* */

dfs(X,X).
dfs(S,D) :- 
    vertex(S),
    vertex(D),
    (edge(S,T),vertex(T),dfs(T,D)).
                    

dfs(v1,v4).







