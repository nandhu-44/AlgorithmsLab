```
DIJKSTRA(G, w, s)
    INITIALIZE_SINGLE_SOURCE(G,s)
    S = Ø
    Q = G.V
    while Q != Ø
        u = EXTRACT_MIN(Q)
        S = S U {u}
        for each vertex v belongs to G.Adj[u]
            RELAX(u, v, w)
```

```
INITIALIZE_SINGLE_SOURCE(G,s)
    for each vertex v belongs to G.V
        v.d = INF
        V.J = NIL
    s.d = 0
```

```
RELAX(u, v, w)
    if v.d > u.d + w(u, v)
        v.d = u.d + w(u, v)
        v.pi = u
```

```
EXTRACT_MIN(Q)
    u = Q[0]
    for each vertex v belongs to Q
        if v.d < u.d
            u = v
    Q = Q - {u}
    return u
```



<!-- Bellman ford -->
```
BELLMAN_FORD(G, w, s):
    INITIALIZE_SINGLE_SOURCE(G,s)
    for i = 1 to |G.V| - 1
        for each edge (u, v) belongs to G.E
            RELAX(u, v, w)
    for each edge (u, v) belongs to G.E
        if v.d > u.d + w(u, v)
            return False
    return True
```

<!-- Prims algorithm -->
```
MST_PRIMS(G, w, r)
    for each u belongs to G.V
        u.key = INF
        u.pi = NIL
    r.key = 0
    Q = G.V
    while Q != Ø
        u = EXTRACT_MIN(Q)
        for each v belongs to G.Adj[u]
            if v belongs to Q and w(u, v) < v.key
                v.pi = u
                v.key = w(u, v)
```

<!-- Kruskal's algorithm -->
```
MST_KRUSKAL(G, w)
    A = Ø
    for each vertex v belongs to G.V
        MAKE_SET(v)
    sort the edges of G.E into nondecreasing order by weight w
    for each edge (u, v) belongs to G.E, taken in nondecreasing order by weight
        if FIND_SET(u) != FIND_SET(v)
            A = A U {(u, v)}
            UNION(u, v)
    return A
```