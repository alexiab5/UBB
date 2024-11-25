from service import Service

READ = "1"
WRITE = "2"
GET_NO_VERTICES = "3"
GET_NO_EDGES = "4"
PRINT_GRAPH = "16"
PARSE_INBOUND = "8"
PARSE_OUTBOUND = "7"
GET_DEGREE = "6"
GET_COST = "9"
SET_COST = "10"
ADD_VERTEX = "11"
REMOVE_VERTEX = "12"
ADD_EDGE = "13"
REMOVE_EDGE = "14"
FIND_EDGE = "5"
RANDOM_GRAPH = "15"
EXIT = "17"


class ConsoleUI:
    def __init__(self):
        self.__service = Service()

    @staticmethod
    def __print_menu():
        print("****************  MAIN MENU *****************\n"
              "1. Read the graph from a text file.\n"
              "2. Write the graph to a text file.\n"
              "3. Get the number of vertices.\n"
              "4. Get the number of edges.\n"
              "5. Find if there is an edge from source to target.\n"
              "6. Get the in and the out degree of a vertex.\n"
              "7. Parse the set of outbound edges of a vertex.\n"
              "8. Parse the set of inbound edges of a vertex.\n"
              "9. Get the cost of an edge.\n"
              "10. Set the cost of an edge.\n"
              "11. Add a vertex.\n"
              "12. Remove a vertex.\n"
              "13. Add an edge.\n"
              "14. Remove an edge.\n"
              "15. Create a random directed graph.\n"
              "16. Print the directed graph.\n"
              "17. EXIT.\n")

    def __read_from_file_menu(self):
        file_name = input("Enter the name of the input file: ")
        try:
            if file_name == "":
                self.__service.read_graph_from_file()
            else:
                self.__service.read_graph_from_file(file_name)
            print("The graph was successfully read from the input file!")
        except Exception:
            print("The input file does not exist!")

    def __write_to_file_menu(self):
        file_name = input("Enter the name of the output file: ")
        try:
            if file_name == "":
                self.__service.write_graph_to_file()
            else:
                self.__service.write_graph_to_file(file_name)
            print("The graph was successfully written in the output file!")
        except Exception:
            print("The output file could not be opened for writing!")

    def __add_vertex_menu(self):
        vertex = input("Enter the vertex you want to add: ")
        try:
            vertex = int(vertex)
        except Exception:
            print("Invalid vertex!")
            return

        try:
            self.__service.graph.add_vertex(vertex)
            print("The vertex was successfully added to the graph!")
        except Exception as e:
            print(e)

    def __remove_vertex_menu(self):
        vertex = input("Enter the vertex you want to remove: ")
        try:
            vertex = int(vertex)
        except Exception:
            print("Invalid vertex!")
            return

        try:
            self.__service.graph.remove_vertex(vertex)
            print("The vertex was successfully removed!")
        except Exception as e:
            print(e)

    def __add_edge_menu(self):
        source = input("Enter the source vertex: ")
        target = input("Enter the target vertex: ")
        cost = input("Enter the cost of the edge: ")
        try:
            source = int(source)
            target = int(target)
            cost = int(cost)
        except Exception:
            print("Invalid input!")
            return

        try:
            self.__service.graph.add_edge(source, target, cost)
            print("The edge was successfully added to the graph!")
        except Exception as e:
            print(e)

    def __remove_edge_menu(self):
        source = input("Enter the source vertex: ")
        target = input("Enter the target vertex: ")
        try:
            source = int(source)
            target = int(target)
        except Exception:
            print("Invalid vertices!")
            return

        try:
            self.__service.graph.remove_edge(source, target)
            print("The edge was successfully removed!")
        except Exception as e:
            print(e)

    def __print_graph(self):
        print(self.__service.graph)

    def __parse_inbound_menu(self):
        vertex = input("Enter the vertex: ")
        try:
            vertex = int(vertex)
        except Exception:
            print("Invalid vertex!")
            return
        try:
            for vertex in self.__service.graph.get_inbound(vertex):
                print(vertex, end=" ")
            print("\n")
        except Exception as e:
            print(e)

    def __parse_outbound_menu(self):
        vertex = input("Enter the vertex: ")
        try:
            vertex = int(vertex)
        except Exception:
            print("Invalid vertex!")
            return
        try:
            for vertex in self.__service.graph.get_outbound(vertex):
                print(vertex, end=" ")
            print("\n")
        except Exception as e:
            print(e)

    def __get_cost_menu(self):
        source = input("Enter the source vertex: ")
        target = input("Enter the target vertex: ")
        try:
            source = int(source)
            target = int(target)
        except Exception:
            print("Invalid vertices!")
            return

        try:
            cost = self.__service.graph.get_cost(source, target)
            print(f"The cost of the edge ({source},{target}): {cost}")
        except Exception as e:
            print(e)

    def __set_cost_menu(self):
        source = input("Enter the source vertex: ")
        target = input("Enter the target vertex: ")
        cost = input("Enter the new cost of the edge: ")
        try:
            source = int(source)
            target = int(target)
            cost = int(cost)
        except Exception:
            print("Invalid input!")
            return

        try:
            self.__service.graph.set_cost(source, target, cost)
            print(f"The cost of the edge ({source},{target}) was successfully updated!")
        except Exception as e:
            print(e)

    def __find_edge_menu(self):
        source = input("Enter the source vertex: ")
        target = input("Enter the target vertex: ")
        try:
            source = int(source)
            target = int(target)
        except Exception:
            print("Invalid vertices!")
            return

        try:
            ok = self.__service.graph.is_edge(source, target)
            if ok:
                print(f"There is an edge from {source} to {target}.")
            else:
                print(f"There is no edge from {source} to {target}.")
        except Exception as e:
            print(e)

    def __get_degree_menu(self):
        vertex = input("Enter the vertex: ")
        try:
            vertex = int(vertex)
        except Exception:
            print("Invalid vertex!")
            return
        try:
            print(f"IN degree of the vertex {vertex}: {self.__service.graph.get_in_degree(vertex)}")
            print(f"OUT degree of the vertex {vertex}: {self.__service.graph.get_out_degree(vertex)}")
        except Exception as e:
            print(e)

    def __random_graph_menu(self):
        vertices = input("Enter the number of vertices: ")
        edges = input("Enter the number of edges: ")
        try:
            vertices = int(vertices)
            edges = int(edges)
        except Exception:
            print("Invalid input!")
            return

        try:
            self.__service.load_random_graph(vertices, edges)
            print("The graph was successfully created!")
        except Exception as e:
            print(e)

    def start(self):
        while True:
            self.__print_menu()
            print("What would you like to do?")
            user_option = input(">>>")
            if user_option == EXIT:
                print("Goodbye!")
                break
            elif user_option == READ:
                self.__read_from_file_menu()

            elif user_option == WRITE:
                self.__write_to_file_menu()

            elif user_option == ADD_VERTEX:
                self.__add_vertex_menu()

            elif user_option == REMOVE_VERTEX:
                self.__remove_vertex_menu()

            elif user_option == ADD_EDGE:
                self.__add_edge_menu()

            elif user_option == REMOVE_EDGE:
                self.__remove_edge_menu()

            elif user_option == PRINT_GRAPH:
                self.__print_graph()

            elif user_option == PARSE_INBOUND:
                self.__parse_inbound_menu()

            elif user_option == PARSE_OUTBOUND:
                self.__parse_outbound_menu()
            elif user_option == GET_COST:
                self.__get_cost_menu()
            elif user_option == SET_COST:
                self.__set_cost_menu()
            elif user_option == GET_NO_EDGES:
                print(f"The graph has {self.__service.graph.no_of_edges} edges.")
            elif user_option == GET_NO_VERTICES:
                print(f"The graph has {self.__service.graph.no_of_vertices} vertices.")
            elif user_option == FIND_EDGE:
                self.__find_edge_menu()
            elif user_option == GET_DEGREE:
                self.__get_degree_menu()
            elif user_option == RANDOM_GRAPH:
                self.__random_graph_menu()
            else:
                print("Invalid input!")

