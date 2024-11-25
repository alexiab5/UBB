from directed_graph import DirectedGraph, DirectedGraphException
from random import randint

class Service:
    def __init__(self):
        self.__graph = DirectedGraph()

    @property
    def graph(self):
        return self.__graph

    def read_graph_from_file(self, file_name="sample.txt"):
        with open(file_name, "r") as file:
            line = file.readline()
            line = line.strip()
            n, m = line.split(" ")
            n = int(n)
            m = int(m)
            self.__graph = DirectedGraph(n)
            for i in range(m):
                line = file.readline()
                line = line.strip()
                source, target, cost = line.split(" ")
                source = int(source)
                target = int(target)
                cost = int(cost)
                self.__graph.add_edge(source, target, cost)

    def write_graph_to_file(self, file_name="output.txt"):
        with open(file_name, "w") as file:
            n = self.__graph.no_of_vertices
            m = self.__graph.no_of_edges
            file.write(f"{n} {m}\n")
            for edge in self.__graph.edges:
                file.write(f"{edge[0]} {edge[1]} {self.__graph.get_cost(edge[0], edge[1])}\n")

    @staticmethod
    def generate_random_graph(no_of_vertices: int, no_of_edges: int):
        """
        Generates a random graph with the specifed number of vertices and of edges.
        :param no_of_vertices:
        :param no_of_edges:
        :return: the random graph
        """
        graph = DirectedGraph(no_of_vertices)
        if no_of_edges > no_of_vertices ** 2:
            raise DirectedGraphException("Too many edges for the specified number of vertices!")
        while no_of_edges > 0:
            source, target, cost = randint(0, no_of_vertices - 1), randint(0, no_of_vertices - 1), randint(0, 50)
            try:
                graph.add_edge(source, target, cost)
                no_of_edges -= 1
            except Exception:
                pass
        return graph

    def load_random_graph(self, no_of_vertices: int, no_of_edges: int):
        """
        Replaces the current graph with a random graph having the specified number of vertices and edges.
        """
        self.__graph = self.generate_random_graph(no_of_vertices, no_of_edges)
