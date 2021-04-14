# All-Possible-Undirected-graph-generation
We can generate all possible graphs for a given number of vertex using boost library in C++.  
To run the code type:
(1)g++ undirected.cpp
(2)./a.out
Now provide number of vertex for which you want to generate all possible graphs.
(3) The program will generate a graphviz.dot file which will contains the graph in the form of list.
(4) To plot these generated graphs in a pdf file use following command:
    gvpack -u graphviz.dot | dot -Tpdf -o output.pdf
(5) Now you have all possible graphs with provided number of vertex.
