class DirectedGraphException(Exception):
    pass


class DirectedGraph:
    def __init__(self, no_of_vertices=0):
        """
        Constructs a graph with the specified number of vertices, numbered from 0 and no edges.
        If no value is provided for the number of vertices, the default value is 0.
        :param no_of_vertices: the number of vertices in the graph
        """
        self.__inbound_edges = {} # key = target, value = sources
        self.__outbound_edges = {} # key = source, value = targets
        self.__no_of_vertices = no_of_vertices
        self.__no_of_edges = 0
        self.__edges_costs = {} # the keys are tuples (source, target) i.e. the edges, values are the corresponding costs of the edges
        for i in range(no_of_vertices):
            self.__inbound_edges[i] = []
            self.__outbound_edges[i] = []

    # --------------------------Getters/Setters
    @property
    def no_of_vertices(self):
        """
        :return: the number of vertices of the directed graph
        """
        return self.__no_of_vertices

    @property
    def no_of_edges(self):
        """
        :return: the number of edges of the directed graph
        """
        return self.__no_of_edges

    @property
    def vertices(self):
        """
        :return: a set of all the vertices in the directed graph
        """
        return set(self.__inbound_edges.keys())

    @property
    def edges(self):
        """
        :return: a set of all the edges in the directed graph
        """
        return set(self.__edges_costs.keys())

    def get_cost(self, source: int, target: int):
        """
        Return the cost of an edge represented as (source, target)
        :param source: the source of the edge
        :param target: the target of the edge
        :return: the cost of the edge
        :raises: DirectedGraphException if either of the vertices does not exist or if their is no edge between source and target.
        """
        if not self.is_vertex(source):
            raise DirectedGraphException("Invalid source vertex!")
        if not self.is_vertex(target):
            raise DirectedGraphException("Invalid target vertex!")
        if self.is_edge(source, target):
            return self.__edges_costs[(source, target)]
        raise DirectedGraphException("The edge does not exist!")

    def set_cost(self, source: int, target: int, cost: int):
        """
        Return the cost of an edge represented as (source, target)
        :param source: the source of the edge
        :param target: the target of the edge
        :param cost: the new cost of the edge
        :return: None
        :raises: DirectedGraphException if either of the vertices does not exist or if their is no edge between source and target.
        """
        if not self.is_vertex(source):
            raise DirectedGraphException("Invalid source vertex!")
        if not self.is_vertex(target):
            raise DirectedGraphException("Invalid target vertex!")
        if not self.is_edge(source, target):
            raise DirectedGraphException("The edge does not exist!")
        self.__edges_costs[(source, target)] = cost

    def get_in_degree(self, vertex: int):
        """
        Returns the in degree of the provided vertex. Raises DirectedGraphException if the vertex does not exist.
        """
        if not self.is_vertex(vertex):
            raise DirectedGraphException("Invalid vertex!")
        return len(self.__inbound_edges[vertex])

    def get_out_degree(self, vertex: int):
        """
        Returns the out degree of the provided vertex. Raises DirectedGraphException if the vertex does not exist.
        """
        if not self.is_vertex(vertex):
            raise DirectedGraphException("Invalid vertex!")
        return len(self.__outbound_edges[vertex])

    def get_inbound(self, vertex):
        """
        Generator function, provides a way of iterating over the inbound edges of the provided vertex.
        Raises DirectedGraphException if the provided vertex does not exist.
        """
        if not self.is_vertex(vertex):
            raise DirectedGraphException("Invalid vertex!")
        for vertex in self.__inbound_edges[vertex]:
            yield vertex

    def get_outbound(self, vertex):
        """
        Generator function, provides a way of iterating over the outbound edges of the provided vertex.
        Raises DirectedGraphException if the provided vertex does not exist.
        """
        if not self.is_vertex(vertex):
            raise DirectedGraphException("Invalid vertex!")
        for vertex in self.__outbound_edges[vertex]:
            yield vertex

    def is_vertex(self, vertex: int):
        """
        Checks if a vertex exists in the graph or not.
        :return: - True if the vertex exists
                 - False otherwise
        """
        if vertex in self.__inbound_edges.keys():
            return True
        return False

    def is_edge(self, source: int, target: int):
        """
        Checks if there is an edge between source and target.
        Raises DirectedGraphException if either of the vertices does not exist.
        :param source: The source of the edge
        :param target: The target of the edge
        :return: - True if there is an edge between source and target
                 - False otherwise
        """
        if not self.is_vertex(source):
            raise DirectedGraphException("Invalid source vertex!")
        if not self.is_vertex(target):
            raise DirectedGraphException("Invalid target vertex!")
        if source in self.__inbound_edges[target]:
            return True
        return False

    def add_vertex(self, vertex: int):
        """
        Adds a vertex to the directed graph. Raises DirectedGraphException if the vertex already exists in the graph.
        :param vertex: the vertex to be added
        :return: None
        """
        if self.is_vertex(vertex):
            raise DirectedGraphException("That vertex already exists!")
        self.__inbound_edges[vertex] = []
        self.__outbound_edges[vertex] = []
        self.__no_of_vertices += 1

    def remove_vertex(self, vertex: int):
        """
        Removes a vertex from the directed graph. Raises DirectedGraphException if the vertex does not exist.
        :param vertex: the vertex to be removed
        :return: None
        """
        if not self.is_vertex(vertex):
            raise DirectedGraphException("The vertex to be removed does not exist.")
        # delete all the inbound edges
        for key in self.__inbound_edges:
            if vertex in self.__inbound_edges[key]:
                self.__inbound_edges[key].remove(vertex)
                del self.__edges_costs[(vertex, key)]
                self.__no_of_edges -= 1
        # delete all the outbound edges
        for key in self.__outbound_edges:
            if vertex in self.__outbound_edges[key]:
                self.__outbound_edges[key].remove(vertex)
                del self.__edges_costs[(key, vertex)]
                self.__no_of_edges -= 1
        del self.__inbound_edges[vertex]
        del self.__outbound_edges[vertex]
        self.__no_of_vertices -= 1

    def add_edge(self, source: int, target: int, cost=None):
        """
        Adds an edge to the directed graph.
        Raises DirectedGraphException if either of the vertices does not exist or if the edge already exists.
        :param source: the source of the edge
        :param target: the target of the edge
        :param cost: the cost of the edge
        :return: None
        """
        if not self.is_vertex(source) or not self.is_vertex(target):
            raise DirectedGraphException("Invalid vertices!")
        if self.is_edge(source, target):
            raise DirectedGraphException("That edge already exists!")
        self.__inbound_edges[target].append(source)
        self.__outbound_edges[source].append(target)
        self.__edges_costs[(source, target)] = cost
        self.__no_of_edges += 1

    def remove_edge(self, source: int, target: int):
        """
        Removes an edge from the directed graph.
        Raises DirectedGraphException if either of the vertices does not exist or if the edge to be removed does not exist.
        :param source: the source of the edge
        :param target: the target of the edge
        :return: None
        """
        if not self.is_vertex(source) or not self.is_vertex(target):
            raise DirectedGraphException("Invalid vertices!")
        if not self.is_edge(source, target):
            raise DirectedGraphException("The edge to be removed does not exist!")
        self.__inbound_edges[target].remove(source)
        self.__outbound_edges[source].remove(target)
        del self.__edges_costs[(source, target)]
        self.__no_of_edges -= 1

    def get_copy(self):
        """
        :return: a deep copy of the graph, it does not allow modifying the initial graph through itself.
        """
        graph_copy = DirectedGraph()
        for vertex in self.__inbound_edges.keys():
            graph_copy.add_vertex(vertex)
        for edge in self.__edges_costs.keys():
            graph_copy.add_edge(edge[0], edge[1], self.__edges_costs[edge])

        return graph_copy

    def __str__(self):
        """
        :return: A string representation of the directed graph.
        """
        edges = ""
        for edge in self.__edges_costs:
            edges += "   " + str(edge) + " " + str(self.__edges_costs[edge]) + "\n"
        return (f"No. of vertices: {self.__no_of_vertices}\t\t\tNo. of edges: {self.__no_of_edges}\n"
                f"\tS T C\n") + edges
