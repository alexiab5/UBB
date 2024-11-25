    @staticmethod
    def bfs(graph: DirectedGraph, source: int, target: int):
        """
        Returns a list containing the parents of every vertex in the graph reachable from source.
        """
        queue = []
        visited = [False] * graph.no_of_vertices
        previous = [None] * graph.no_of_vertices
        queue.append(source)
        visited[source] = True
        while len(queue) != 0:
            current = queue.pop(0)
            for neighbour in graph.get_outbound(current):
                if not visited[neighbour]:
                    queue.append(neighbour)
                    visited[neighbour] = True
                    previous[neighbour] = current
                    if neighbour == target:
                        break
        return previous

    def find_lowest_length_path(self, source: int, target: int):
        """
        Returns a list of vertices representing the lowest path between source and target.
        Raises Exception if either of the vertices is invalid.
        """
        if source not in self.__graph.vertices or target not in self.__graph.vertices:
            raise DirectedGraphException("Invalid source or target vertex!")
        previous = self.bfs(self.__graph, source, target)
        # reconstruct the shortest path from source to target starting from target
        shortest_path = []
        current_vertex = target
        # reconstructing the path in reverse order
        while current_vertex != source:
            shortest_path.append(current_vertex)
            current_vertex = previous[current_vertex]
        shortest_path.append(current_vertex)
        # reversing the path
        shortest_path.reverse()
        if shortest_path[0] == source: # there is a path from source to target
            return shortest_path
        return [] # there is no path from source to target

    # the UI function:
    def __print_lowest_length_path(self):
        source = input("Enter the source vertex: ")
        target = input("Enter the target vertex: ")
        try:
            source = int(source)
            target = int(target)
        except Exception as e:
            print("Invalid vertices!")
        try:
            shortest_path = self.__service.find_lowest_length_path(source, target)
            if shortest_path == []:
                print(f"There is no path from {source} to {target}!")
            else:
                print(
                    f"The lowest length path from from {source} to {target} has length {len(shortest_path) - 1}: {shortest_path}")
        except DirectedGraphException as e:
            print(e)